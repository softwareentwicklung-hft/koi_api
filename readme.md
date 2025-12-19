readme für Projekt Koi
# Beispiel für CMD 
Zum Anzeigen und Speichern von Luft und Wasserdaten auf einem Server (Notebook_xxx IP ist Netzabhängig).
curl -X GET http://192.168.20.20:18080/koi/air

curl -X POST http://192.168.20.20/koi/air -H "Content-Type: application/json" -d "{\"device_id\": \"SENSOR_01\", \"timestamp\": 1704067200, \"pressure_value\": 1012.5, \"temp_value\": 22.8, \"humidity_value\": 55.7}"

Zum Anzeigen und Speichern von Wasserdaten
curl -X POST http://192.168.20.20:18080/koi/water -H "Content-Type: application/json" -d "{\"device_id\": \"SENSOR_02\", \"timestamp\": 1704067200, \"tds_value\": 1012.5, \"temp_value\": 22.8, \"ph_value\": 7}"

curl -X GET  http://192.168.20.20:18080/koi/water


Auf eigenem Notebook

curl -X GET  http://localhost:18080/koi/air

curl -X POST http://localhost:18080/koi/air -H "Content-Type: application/json" -d "{\"device_id\": \"SENSOR_01\", \"timestamp\": 1704067200, \"pressure_value\": 1012.5, \"temp_value\": 22.8, \"humidity_value\": 55.7}"

Zum Anzeigen und Speichern von Wasserdaten
curl -X POST http://localhost:18080/koi/water -H "Content-Type: application/json" -d "{\"device_id\": \"SENSOR_02\", \"timestamp\": 1704067200, \"tds_value\": 1012.5, \"temp_value\": 22.8, \"ph_value\": 7}"

curl -X GET  http://localhost:18080/koi/water


//Readme vom itHub  Repository "pesche70/Koi" übernommen 20151219

# Koi
Daten Wasserqualität erfassen und auf Server in CSV-Datei speichern

Autoren: Isabel Geissmann(Product-Owner) / Stephan Fankhauser(Tech-Lead) / Peter Meier(Scrum-Master)

## Inhaltsverzeichniss:

Projektbeschreibung:

Anforderungen:

Use Case:

Anleitung fürs Programm:

Fazit:

Scrum Meetings:

Flussdiagramm:

Systemsequenzdiagramm:


## Projektbeschreibung:

Im Rahmen dieses Projekts wird eine Anlage erstellt welche die Wasserqualität des BBT-Teichs mit Sensoren und einem Controller erfasst.
Diese Daten werden via lokales Netzwerk mit WIFI über eine API Schnittstelle an einen Server übertragen.
Dieser Server speichert die Daten in eine CSV-Datei. Diese CSV-Daten werden in einem Excel Tabelle dargestellt.


## Anforderungen:
| Funktion                                                                   | Muss | Wunsch |
|----------------------------------------------------------------------------|------|--------|
| Daten (Feststoff/Temperatur/PH)erfassen mit Sensoren                       | X    | X      |
| Daten in Controller aufbereiten                                            | X    | -      |
| Daten via Wifi und API an Server senden                                    | X    | -      |
| Daten auf Server speichern in  CSV-Datei                                   | X    | -      |
| Daten der Luft erfassen (Druck/Temperatur/Feuchte)                         | -    | X      |


| Hardware-Komponente     | Bezeichnung             | Typ        |
|-------------------------|-------------------------|------------|
| Microcontroller ESP 32  | Freenove ESP32-S3-WROOM | FNK0099    |
| Breakoutboard           | Freenove Breakoutboard  | FNK0091    |
| TDS-Sensor              | Seed Studio SKU X       | 101020753  |
| Temperaturfühler        | DS18B20                 | DS18B20    |
| PH-Messfühler           | DFROBOT                 | SEN0161-V2 |
| Messfühler Luftqualität | BME 680                 | BME 680    |

|  Software-Komponente   |
|------------------------|
| Clion                  |
| Git-Hub                |


## Use Case:
Funktionen

Erfassen von Daten

Ziel:
Projekt-Beschreibung

Auslöser:

Vorbedingungen:
Server muss erreichbar sein.
Wifi Verbindung muss bestehen

Ablauf einer Erfassung:

Nachbedingungen:
Der neue Datensatz ist in der CSV-Datei vorhanden und korrekt formatiert.

Korrekturablauf:


Ablauf einer Abfrage:

Nachbedingungen:


## Anleitung fürs Programm:


Voraussetzungen:
- CLion (IDE von JetBrains)
- Compiler (z. B. GCC für Linux, MinGW für Windows oder Xcode Command Line Tools für macOS)
- Git (um Das Repository zu klonen)

Projekt herunterladen:



Programm ausführen:


oder
- Warte, bis CLion das Projekt vollständig indexiert hat.
- Klicke auf Build. oder ctr. F9 (Windows)
- Starte das Programm über den Pfeil Symbol oben rechts oder über Run.

oder
-


## Fazit:

| Funktion / Kriterium | Pflicht / Wunsch | Erfüllt?

| Funktion/Kriterium                                 | Pflicht/Wunsch | erfüllt |           
|----------------------------------------------------|----------------|---------|
| Daten (Feststoff/Temperatur)erfassen mit Sensoren  | Muss           | -       |
| Daten in Controller aufbereiten                    | Muss           | -       |
| Daten via Wifi und API an Server senden            | Muss           | -       |
| Daten auf Server speichern CSV-Datei               | Muss           | -       |
| Daten (PH ) erfassen mit Sensoren                  | Wunsch         | -       |
| Daten der Luft erfassen (Druck/Temperatur/Feuchte) | Wunsch         | -       |


## Scrum Meetings:

## 20251115_Sprint1

| Sprint-Ziel                  |           
|------------------------------|
| Rollenverteilung             | 
| Projekt-Definition           | 
| Hardware Definition          | 
| Software Definition          | 
| Git-Hub Resopitory erstellen | 


## 20251122_Sprint1 erreicht:
| Sprint-Ziel                  | Erfüllt |          
|------------------------------|---------|
| Rollenverteilung             | OK      |
| Projekt-Definition           | OK      |
| Hardware Definition          | OK      |
| Software Definition          | OK      |
| Git-Hub Resopitory erstellen | OK      |

Rollenverteilung: Projekt-Owner: Isabel Geissmann
Tech Lead: Stephan Fankhauser
Scrum-Master: Peter Meier


## 20251122_Sprint2
| Sprint-Ziel                                |           
|--------------------------------------------|
| Datenflussdiagramm erstellen               | 
| Ablaufdiagramm Controller&Server erstellen | 


## 20251129_Sprint2 erreicht:
| Sprint-Ziel                                | Erfüllt |          
|--------------------------------------------|---------|
| Datenflussdiagramm erstellen               | OK      |
| Ablaufdiagramm Controller&Server erstellen | OK      |


## 20251129_Sprint3
-Sprint-Ziel:

## 20251206_Sprint3 erreicht:


## 20251206_Sprint4
| Sprint-Ziel                                                                                          |           
|------------------------------------------------------------------------------------------------------|
| CLion-Programm APi-Server erstellen/Daten vom Controller als CSV-Datei speichern.                    | 
| CLion Programm das die Daten im Controller erfasst und  über WiFi an den API-Server sendet erstellen | 
| Zusammensetzen der Programmteile und testen mit der Hardware                                         | 


## 20251213_Sprint4 erreicht:
| Sprint-Ziel                                                                                          | Erfüllt |          
|------------------------------------------------------------------------------------------------------|---------|
| CLion-Programm APi-Server erstellen/Daten vom Controller als CSV-Datei speichern.                    | OK      |
| CLion Programm das die Daten im Controller erfasst und  über WiFi an den API-Server sendet erstellen | OK      |
| Zusammensetzen der Programmteile und testen mit der Hardware                                         | --      |

Weil wie die Sensoren erst am Freitag, 12.12.2025 bekamen konnten wir in dieser Woche den Punkt 3 nicht durchführen.



## 20251213_Sprint5
| Sprint-Ziel                                                                                          |           
|------------------------------------------------------------------------------------------------------|
| CLion Programm das die Daten im Controller erfasst und  über WiFi an den API-Server sendet erstellen |   
| Zusammensetzen der Programmteile und testen mit der Hardware                                         |
| System funktioniert (Hardware und Software)                                                          | 
| System im Teich und Lehrerzimmer installiert                                                         | 
| Daten über 3 Tage erfasst                                                                            | 
| Code  auf Git-Hub gespeichert                                                                        | 
| Dokumentation erstellt                                                                               | 
| Daten über 3 Tage erfasst                                                                            |



## 20251222_Sprint5 erreicht:
| Sprint-Ziel                                                                                          | Erfüllt |
|------------------------------------------------------------------------------------------------------|---------|
| CLion Programm das die Daten im Controller erfasst und  über WiFi an den API-Server sendet erstellen | OK      |
| Zusammensetzen der Programmteile und testen mit der Hardware                                         | OK      |
| System funktioniert (Hardware und Software)                                                          | OK      |
| System im Teich und Lehrerzimmer installiert                                                         | OK      |
| Daten über 3 Tage erfasst                                                                            | 1)      |
| Code auf Git-Hub gespeichert                                                                         |         |
| Dokumentation erstellt                                                                               |         |

1)Der erste Tag der Datenerfassung wurde Zuhause in einem Wassereimer
  erstellt und der zweite Teil im BBZ-Teich mit einem Testschiff. Dadurch haben wir durch das Datenloggen herausgefunden,
  dass das BBZ-W-LAN zwischen 23:00Uhr und 06:00 abgestellt wird.


## 20251220_Sprint6
-Sprint-Ziel: Präsentation Projekt im Januar

## 20260109_Sprint3 erreicht:
    Präsentation beendet



## Flussdiagramm:

![Datenflussdiagramm](Datenflussdiagramm.png)


## Systemsequenzdiagramm:

![Systemsequenzdiagramm](Flussdiagramm_Wasserqualität.png)


End
