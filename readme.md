# Beispiel für CMD 

Zum Anzeigen undnSpeichern von Luftdaten

curl -X GET  http://localhost:18080/koi/air

curl -X POST http://localhost:18080/koi/air -H "Content-Type: application/json" -d "{\"device_id\": \"SENSOR_01\", \"timestamp\": 1704067200, \"pressure_value\": 1012.5, \"temp_value\": 22.8, \"humidity_value\": 55.7}"

Zum Anzeigen undnSpeichern von Wasserdaten
curl -X POST http://localhost:18080/koi/water -H "Content-Type: application/json" -d "{\"device_id\": \"SENSOR_02\", \"timestamp\": 1704067200, \"tds_value\": 1012.5, \"temp_value\": 22.8, \"ph_value\": 7}"

curl -X GET  http://localhost:18080/koi/water