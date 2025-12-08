# Beispiel für CMD 
curl -X POST http://localhost:18080/koi/data -H "Content-Type: application/json" -d "{\"device_id\": \"SENSOR_02\", \"timestamp\": 1704067200, \"tds_value\": 2012.5, \"temp_value\": 22.8, \"ph_value\": 7.2}"

curl -X GET  http://localhost:18080/koi/data