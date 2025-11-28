#include "crow.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <mutex>
#include <string>

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

int main() {
    crow::SimpleApp app;

    // POST-Route: Fügt neue Luftdaten hinzu
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
        // Benötigt es alle Felder?
        if (!body.contains("device_id") || !body["device_id"].is_string() ||
            !body.contains("timestamp") || !body["timestamp"].is_number_integer() ||
            !body.contains("pressure_value") || !body["pressure_value"].is_number() ||
            !body.contains("temp_value") || !body["temp_value"].is_number() ||
            !body.contains("humidity_value") || !body["humidity_value"].is_number()) {

            return crow::response(400, "Invalid JSON: missing or incorrect data types for AirData fields (device_id: string, timestamp: long, others: double).");
        }

        // Erstelle ein neues AirData-Objekt aus den JSON-Werten
        AirData newAirData{
                body["device_id"].get<std::string>(),
                body["timestamp"].get<long>(),
                body["pressure_value"].get<double>(),
                body["temp_value"].get<double>(),
                body["humidity_value"].get<double>()
        };

        // Daten unter Schutz des Mutex zur globalen Liste hinzufügen
        std::lock_guard<std::mutex> lock(airData_mutex);
        airData.push_back(newAirData);

        // Erfolgreiche Antwort (201 Created) zurückgeben
        return crow::response(201, "AirData successfully recorded.");
    });

    // GET-Route: Gibt alle gespeicherten Luftdaten zurück
    CROW_ROUTE(app, "/koi/data/airData").methods("GET"_method)([]() {
        std::lock_guard<std::mutex> lock(airData_mutex);

        // Konvertiere den Vektor der AirData-Strukturen in ein JSON-Array
        // Die Funktion to_json wird hier automatisch von nlohmann::json verwendet.
        json j = airData;

        // Gebe die Daten als JSON zurück
        return crow::response(200, j.dump());
    });


    app.port(18080).multithreaded().run();
}