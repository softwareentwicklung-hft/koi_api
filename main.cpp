#include "crow.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <mutex>
#include <string>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <iomanip>

using json = nlohmann::json;

//----Definiert den Namen und Speicherort der CSV-Datei (hier im Ordner des Projekts)---
const std::string CSV_Air_Filename   = "./daten/airdata_log.csv";
const std::string CSV_Water_Filename = "./daten/waterdata_log.csv";

std::mutex csv_air_mutex;
std::mutex csv_water_mutex;

// ------------------- Datenstrukturen -----------------------
struct WaterData {
    std::string device_id;
    long timestamp;
    double tds_value;
    double temp_value;
    double ph_value;
};

struct AirData {
    std::string device_id;
    long timestamp;
    double pressure_value;
    double temp_value;
    double humidity_value;
};

// ------------------- Globale Vektoren ---------------------
std::vector<WaterData> waterData;
//Schützt vor gleichzeitigen Zugriffen
std::mutex waterData_mutex;

std::vector<AirData> airData;
//Schützt vor gleichzeitigen Zugriffen
std::mutex airData_mutex;

// JSON Serialisierung für AirData
// Diese Funktion ermöglicht es nlohmann::json, std::vector<AirData> direkt zu serialisieren.
void to_json(json& j, const AirData& a) {
    j = json{
        {"device_id", a.device_id},
        {"timestamp", a.timestamp},
        {"pressure_value", a.pressure_value},
        {"temp_value", a.temp_value},
        {"humidity_value", a.humidity_value}
    };
}

// JSON Serialisierung für WaterData
// Diese Funktion ermöglicht es nlohmann::json, std::vector<AirData> direkt zu serialisieren.
void to_json(json& j, const WaterData& w) {
    j = json{
        {"device_id", w.device_id},
        {"timestamp", w.timestamp},
        {"tds_value", w.tds_value},
        {"temp_value", w.temp_value},
        {"ph_value", w.ph_value}
    };
}

//CSV-Datei erstellen, falls Datei fehlt
void initializeCSV() {
    std::filesystem::create_directories("./daten");
    // AirData CSV-Datei kontrollieren, ob besteht und leer ist
    if (!std::filesystem::exists(CSV_Air_Filename) || std::filesystem::file_size(CSV_Air_Filename) == 0) {
        //Datei wird zum Schreiben geöffnet
        std::ofstream file(CSV_Air_Filename);
    // Spalten-Namen erstellen
        if (file.is_open()) {
            file << "device_id;"
                 << "timestamp;"
                 << "pressure_value;"
                 << "temp_value;"
                 << "humidity_value\n";
        }
    }

    // WaterDataCSV-Datei kontrollieren, ob besteht und leer ist
    if (!std::filesystem::exists(CSV_Water_Filename) || std::filesystem::file_size(CSV_Water_Filename) == 0) {
        //Datei wird zum Schreiben geöffnet
        std::ofstream file(CSV_Water_Filename);
        // Spalten-Namen erstellen
        if (file.is_open()) {
            file << "device_id;"
                 << "timestamp;"
                 << "tds_value;"
                 << "temp_value;"
                 << "ph_value\n";
        }
    }
}

// ------------------- Helper-Funktionen -------------------

// JSON Validierung für AirData
//Kontrollieren, ob alle Daten vorhanden und richtiger Datentyp-> gibt "true" zurück.
bool validateAirDataJson(const json& body) {
    return body.contains("device_id") && body["device_id"].is_string() &&
           body.contains("timestamp") && body["timestamp"].is_number_integer() &&
           body.contains("pressure_value") && body["pressure_value"].is_number() &&
           body.contains("temp_value") && body["temp_value"].is_number() &&
           body.contains("humidity_value") && body["humidity_value"].is_number();
}

// JSON Validierung für WaterData
//Kontrollieren, ob alle Daten vorhanden und richtiger Datentyp → gibt "true" zurück.
bool validateWaterDataJson(const json& body) {
    return body.contains("device_id") && body["device_id"].is_string() &&
           body.contains("timestamp") && body["timestamp"].is_number_integer() &&
           body.contains("tds_value") && body["tds_value"].is_number() &&
           body.contains("temp_value") && body["temp_value"].is_number() &&
           body.contains("ph_value") && body["ph_value"].is_number();
}

//Konvertieren von Timestamp-Format in Jahr-Monat-Tag-Stunde-Minute-Sekunden-Format
//Macht aus dem Timestamp ein String
std::string formatTimestamp(long ts) {
    //time_tist der C++ Zeitstandard in Sekunden seit 1970
    std::time_t t = ts;
    //Struktur  im Format Jahr-Monat-Tag-Stunde-Minute-Sekunden-Format wird erstellt
    std::tm tm_struct{};

// Hier werden die Sekunden seit 1970 in Jahre/Monate/Tage/Stunden/Minuten und Sekunden umgerechnet
//  entweder in Linux oder Windows Format
#ifdef _WIN32
    localtime_s(&tm_struct, &t); // Windows
#else
    localtime_r(&t, &tm_struct); // Linux
#endif
//oss String wird erstellt und tm_struct in das Format "2025-12-19-10-32-08" gewandelt
    std::ostringstream oss;
    oss << std::put_time(&tm_struct, "%Y-%m-%d-%H-%M-%S");
    return oss.str();
}

// CSV schreiben für AirData
bool saveAirDataToCSV(const AirData& data) {
    std::lock_guard<std::mutex> lock(csv_air_mutex);
    std::ofstream file(CSV_Air_Filename, std::ios::app);
    if (!file.is_open()) return false;

    file << data.device_id << ";"
         << formatTimestamp(data.timestamp) << ";"
         << data.pressure_value << ";"
         << data.temp_value << ";"
         << data.humidity_value << "\n";
    return true;
}

// CSV schreiben für WaterData
bool saveWaterDataToCSV(const WaterData& data) {
    std::lock_guard<std::mutex> lock(csv_water_mutex);
    std::ofstream file(CSV_Water_Filename, std::ios::app);
    if (!file.is_open()) return false;
    file << data.device_id << ";"
         << formatTimestamp(data.timestamp) << ";"
         << data.tds_value << ";"
         << data.temp_value << ";"
         << data.ph_value << "\n";
    return true;
}

// ------------------- MAIN -------------------
int main() {
    crow::SimpleApp app;

    initializeCSV();

    // POST-Route: Fügt neue Luftdaten hin zu
    // Macht diese Route Sinn?
    CROW_ROUTE(app, "/koi/air").methods("POST"_method)([](const crow::request& req) {
        json body;
        try
        {
            // Wandelt den Request-Body in ein JSON-Objekt um
            body = json::parse(req.body);
        }
        catch (...)
        {
            // Fehler bei der JSON-Analyse
            return crow::response(400, "Invalid JSON format in request body.");
        }

        if (!validateAirDataJson(body))
            return crow::response(400, "Invalid AirData JSON fields");

        AirData newAirData{
            body["device_id"].get<std::string>(),
            body["timestamp"].get<long>(),
            body["pressure_value"].get<double>(),
            body["temp_value"].get<double>(),
            body["humidity_value"].get<double>()
        };

        {
            std::lock_guard<std::mutex> lock(airData_mutex);
            airData.push_back(newAirData);
        }

        if (!saveAirDataToCSV(newAirData))
            return crow::response(500, "Cannot write AirData to CSV");

        return crow::response(201, "AirData recorded");
    });

    // ------------------- POST WaterData -------------------
    CROW_ROUTE(app, "/koi/water").methods("POST"_method)([](const crow::request& req) {
        json body;
        try { body = json::parse(req.body); }
        catch (...) { return crow::response(400, "Invalid JSON format"); }

        if (!validateWaterDataJson(body))
            return crow::response(400, "Invalid WaterData JSON fields");

        WaterData newWaterData{
            body["device_id"].get<std::string>(),
            body["timestamp"].get<long>(),
            body["tds_value"].get<double>(),
            body["temp_value"].get<double>(),
            body["ph_value"].get<double>()
        };

        {
            std::lock_guard<std::mutex> lock(waterData_mutex);
            waterData.push_back(newWaterData);
        }

        if (!saveWaterDataToCSV(newWaterData))
            return crow::response(500, "Cannot write WaterData to CSV");

        return crow::response(201, "WaterData recorded");
    });

    // ------------------- GET AirData -------------------
    CROW_ROUTE(app, "/koi/air").methods("GET"_method)([]() {
        std::lock_guard<std::mutex> lock(airData_mutex);
        return crow::response(200, json(airData).dump());
    });

    // ------------------- GET WaterData -------------------
    CROW_ROUTE(app, "/koi/water").methods("GET"_method)([]() {
        std::lock_guard<std::mutex> lock(waterData_mutex);
        return crow::response(200, json(waterData).dump());
    });

    app.port(18080).multithreaded().run();
}
//END main
