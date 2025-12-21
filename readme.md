###############################################################
## Koi
Wasser- und Luft-Daten erfassen und auf Server in CSV-Datei speichern
Autoren: Isabel Geissmann(Product-Owner)
         Stephan Fankhauser (Tech-Lead)
         Peter Meier (Scrum-Master)

Dieses readme.md gilt für beide GitHub Projekt-Repository:
 https://github.com/softwareentwicklung-hft/koi_api/tree/test 
 https://github.com/Latrusanimi/Koi

###############################################################


## Inhaltsverzeichnis:

1 Projektbeschreibung:

2 Anforderungen:

3 Use Case:

4 Anleitung fürs Programm:

5 Fazit:

6 Scrum Meetings:

7 Flussdiagramm:

8 Systemsequenzdiagramm:

9 Projekt-Links:

10 HTTP: Test-Befehle:

11 Systemtest:



## 1 Projektbeschreibung:
Im Rahmen dieses Projekts wird eine Anlage erstellt welche die Wasserqualität des BBT-Teichs mit Sensoren und einem Controller erfasst.
Diese Daten werden via lokales Netzwerk mit WIFI über eine API Schnittstelle an einen Server übertragen.
Dieser Server speichert die Daten in eine CSV-Datei. Diese CSV-Daten werden in einem Excel Tabelle dargestellt.


## 2 Anforderungen:
| Funktion                                             | Muss | Wunsch |
|------------------------------------------------------|------|--------|
| Daten (Feststoff/Temperatur/PH)erfassen mit Sensoren | X    | -      |
| Daten in Controller aufbereiten                      | X    | -      |
| Daten via Wifi und API an Server senden              | X    | -      |
| Daten auf Server speichern in  CSV-Datei             | X    | -      |
| Daten der Luft erfassen (Druck/Temperatur/Feuchte)   | -    | X      |


| Hardware-Komponente     | Bezeichnung             | Typ        |
|-------------------------|-------------------------|------------|
| Microcontroller ESP 32  | Freenove ESP32-S3-WROOM | FNK0099    |
| Breakoutboard           | Freenove Breakoutboard  | FNK0091    |
| TDS-Sensor              | Seed Studio SKU X       | 101020753  |
| Temperaturfühler        | DS18B20                 | DS18B20    |
| PH-Messfühler           | DFROBOT                 | SEN0161-V2 |
| Messfühler Luftqualität | BME 680                 | BME 680    |

| Software-Komponente |
|---------------------|
| Clion               |
| Git-Hub             |
| MS-Excel            |

## 3 Use Case:

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


## 4 Anleitung fürs Programm:

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


## 5 Fazit:

| Funktion / Kriterium | Pflicht / Wunsch | Erfüllt?

| Funktion/Kriterium                                 | Pflicht/Wunsch | erfüllt |           
|----------------------------------------------------|----------------|---------|
| Daten (Feststoff/Temperatur)erfassen mit Sensoren  | Muss           | OK      |
| Daten in Controller aufbereiten                    | Muss           | OK      |
| Daten via Wifi und API an Server senden            | Muss           | OK      |
| Daten auf Server speichern CSV-Datei               | Muss           | OK      |
| Daten (PH ) erfassen mit Sensoren                  | Wunsch         | 1)      |
| Daten der Luft erfassen (Druck/Temperatur/Feuchte) | Wunsch         | OK      |

1) Weil der PH-Sensor nicht erhalten wurde, fehlt diese Wunschfunktion.


## 6 Scrum Meetings:

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
| Zusammensetzen der Programmteile und testen mit der Hardware                                         | 1)      |

1) Weil wie die Sensoren erst am Freitag, 12.12.2025 bekamen konnten
   wir in dieser Woche den Punkt 3 nicht durchführen.


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
| Video erstellt                                                                                       |  
| Test-dokument erstellt                                                                               |


## 20251222_Sprint5 erreicht:
| Sprint-Ziel                                                                                          | Erfüllt |
|------------------------------------------------------------------------------------------------------|---------|
| CLion Programm das die Daten im Controller erfasst und  über WiFi an den API-Server sendet erstellen | OK      |
| Zusammensetzen der Programmteile und testen mit der Hardware                                         | OK      |
| System funktioniert (Hardware und Software)                                                          | OK      |
| System im Teich und Lehrerzimmer installiert                                                         | OK      |
| Daten über 3 Tage erfasst                                                                            | 1)      |
| Code auf Git-Hub gespeichert                                                                         | OK      |
| Dokumentation erstellt                                                                               | OK      |
| Video erstellt                                                                                       | OK      |
| Test-Dokument erstellt                                                                               | OK      |
| Projekdokumentation abgegeben                                                                        | OK      |

1)Der erste Tag der Datenerfassung wurde Zuhause in einem Wassereimer
erstellt und der zweite Teil im BBZ-Teich mit einem Testschiff.
Dadurch haben wir durch das Datenloggen herausgefunden,
dass das BBZ-W-LAN zwischen 23:00Uhr und 06:00 abgestellt wird.
Deshalb fehlen in den CSV-Dateien die Daten zwischen 23:00 und 6:00Uhr.


## 20251220_Sprint6
| Sprint-Ziel                                |           
|--------------------------------------------|
| Präsentation Projekt im Januar vorbereiten | 
| Präsentation beendet                       | 

-Sprint-Ziel: Präsentation Projekt im Januar vorbereiten

## 20260109_Sprint6 erreicht:
| Sprint-Ziel                                | Erfüllt |          
|--------------------------------------------|---------|
| Präsentation Projekt im Januar vorbereiten |         |
| Präsedntation beenet                       |         |



## 7 Flussdiagramm:

![Datenflussdiagramm](Koi_Datenfluss-Diagramm.png)


## 8 Systemsequenzdiagramm:

![Systemsequenzdiagramm](Flussdiagramm_Wasserqualität.png)

## 9 Projekt-Links:

//GitHub  Repository https://github.com/orgs/softwareentwicklung-hft/repositories/koi_api  Branch <test>
//GitHub  Repository https://github.com/Latrusanimi/Projekt_2024/commits?author=Latrusanimi/  Branch <test>

//CSV-Dateien  waterdata_log.csv https://github.com/softwareentwicklung-hft/koi_api/tree/test
               airdata_log.csv   https://github.com/softwareentwicklung-hft/koi_api/tree/test






## 10 HTTP: Test-Befehle (Kommandozeile)

Zum Anzeigen und Speichern von Luft und Wasserdaten auf einem Server (Notebook_xxx IP ist Netzabhängig).

curl -X GET http://<IP-Adresse Server>:18080/koi/air
curl -X POST http://<IP-Adresse Server>/koi/air -H "Content-Type: application/json" -d "{\"device_id\": \"SENSOR_01\", \"timestamp\": 1704067200, \"pressure_value\": 1012.5, \"temp_value\": 22.8, \"humidity_value\": 55.7}"

Zum Anzeigen und Speichern von Wasserdaten

curl -X POST http://<IP-Adresse Server>:18080/koi/water -H "Content-Type: application/json" -d "{\"device_id\": \"SENSOR_02\", \"timestamp\": 1704067200, \"tds_value\": 1012.5, \"temp_value\": 22.8, \"ph_value\": 7}"
curl -X GET  http://<IP-Adresse Server>:18080/koi/water

## 11 Systemtest

1 Stabilität der W-LAN-Verbindung wurde beim Erfassen der Daten das BBZ-Netzwerk zwischen 23:00 und 6:00Uhr
  abgestellt. Danach lief die Datenerfassung einwandfrei weiter.

2 Fehlen von einzelnen Daten im CSV-Datei

3

20251221

