#include "crow.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <mutex>
#include <string>
#include <fstream>
#include <iostream>
# include <iomanip>
#include <filesystem>
#include <sstream>

//Definieren des Namens und Speicherort der CSV-Datei hier im Ordner des Projekts
const std::string CSV_Filename= "waterdata_log.csv";

std::mutex csv_file_mutex;

using json = nlohmann::json;

struct WaterData{
        std::string device_id;
        long timestamp;
        double tds_value;
        double temp_value;
        double ph_value;
};

struct AirData{
        std::string device_id;
        long timestamp;
        double pressure_value;
        double temp_value;
        double humidity_value;
};

std::vector<WaterData> waterData;
std::mutex waterData_mutex;
std::vector<AirData> airData;
std::mutex airData_mutex;

// JSON Serialisierung für WaterData
// Diese Funktion ermöglicht es nlohmann::json, std::vector<AirData> direkt zu serialisieren.
void to_json(json& j, const WaterData& a) {
    j = json{
            {"device_id", a.device_id},
            {"timestamp", a.timestamp},
            {"tds_value", a.tds_value},
            {"temp_value", a.temp_value},
            {"ph_value", a.ph_value}
    };
}

//CSV-Datei erstellen, falls Datei fehlt
void initializeCSV()
{
        std::ofstream file(CSV_Filename);
        // Spalten-Namen erstellen
        if (file.is_open())
        {
            file << "device_id;"
                 << "timestamp;"
                 << "tds_value;"
                 << "temp_value;"
                 << "ph_value"
                 << "\n";
        }
        else
            {
            //Fehlermeldung in Clion
            std::cerr << "ERROR: Cannot create CSV file: " << CSV_Filename << std::endl;
            }

}

//Start main
int main() {
    crow::SimpleApp app;

    initializeCSV();

    // POST-Route: Fügt neue Wasserdaten hin zu
    // Macht diese Route Sinn?
    CROW_ROUTE(app, "/koi/data").methods("POST"_method)([](const crow::request& req) {
        json body;
        try {
            // Wandelt den Request-Body in ein JSON-Objekt um
            body = json::parse(req.body);
        } catch (const std::exception& e) {
            // Fehler bei der JSON-Analyse
            return crow::response(400, "Invalid JSON format in request body.");
        }

        // Validierung der erforderlichen Felder und Datentypen
        // benötigt es alle Felder?
        if (!body.contains("device_id") || !body["device_id"].is_string() ||
            !body.contains("timestamp") || !body["timestamp"].is_number_integer() ||
            !body.contains("tds_value") || !body["tds_value"].is_number() ||
            !body.contains("temp_value") || !body["temp_value"].is_number() ||
            !body.contains("ph_value") || !body["ph_value"].is_number()) {

            return crow::response(400, "Invalid JSON: missing or incorrect data types for WaterData fields (device_id: string, timestamp: long, others: double).");
        }

        // Erstelle ein neues WaterData-Objekt aus den JSON-Werten
        WaterData newWaterData{
                body["device_id"].get<std::string>(),
                body["timestamp"].get<long>(),
                body["tds_value"].get<double>(),
                body["temp_value"].get<double>(),
                body["ph_value"].get<double>()
        };

        // Daten unter Schutz des Mutex zur globalen Liste hinzufügen
        std::lock_guard<std::mutex> lock(waterData_mutex);
        waterData.push_back(newWaterData);

       //CSV-Speichern
        {
        std::lock_guard<std::mutex> lock(csv_file_mutex);

        std::ofstream file(CSV_Filename, std::ios::app);

//Daten in CSV-Datei Speichern
        if (file.is_open()) {
       file << newWaterData.device_id     << ";"
            << newWaterData.timestamp     << ";"
            << newWaterData.tds_value << ";"
            << newWaterData.temp_value    << ";"
            << newWaterData.ph_value << "\n";
        }
        else {
              std::cerr << "ERROR: Cannot open CSV for writing file is alread open: " << CSV_Filename << std::endl;
              return crow::response(500, "Cannot write to CSV file is already open");
          }
   }

        // Erfolgreiche Antwort (201 Created) zurückgeben
        return crow::response(201, "WaterData successfully recorded.");
    });

    // GET-Route: Gibt alle gespeicherten Wasserdaten zurück
    CROW_ROUTE(app, "/koi/data").methods("GET"_method)([]() {
        std::lock_guard<std::mutex> lock(waterData_mutex);

        // Konvertiere den Vektor der WaterData-Strukturen in ein JSON-Array.
        // Die Funktion to_json wird hier automatisch von nlohmann::json verwendet.
        json j = waterData;

        // Gebe die Daten als JSON zurück
        return crow::response(200, j.dump());
    });



    app.port(18080).multithreaded().run();
}
//End main


