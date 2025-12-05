# Beispiel für CMD 
curl -X POST http://localhost:18080/koi/data -H "Content-Type: application/json" -d "{\"device_id\": \"SENSOR_01\", \"timestamp\": 1704067200, \"pressure_value\": 1012.5, \"temp_value\": 22.8, \"humidity_value\": 55.2}"

curl -X GET  http://localhost:18080/koi/data
