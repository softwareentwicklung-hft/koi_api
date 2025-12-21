###############################################################
# Koi
Wasser- und Luft-Daten erfassen und auf Server in CSV-Datei speichern

Autoren: Isabel Geissmann(Product-Owner)

Stephan Fankhauser (Tech-Lead)

Peter Meier (Scrum-Master)

Dieses readme.md gilt für beide GitHub Projekt-Repository:

https://github.com/softwareentwicklung-hft/koi_api/tree/test

https://github.com/Latrusanimi/Koi

###############################################################


## Inhaltsverzeichnis

1. [Projektbeschreibung](#projektbeschreibung)
2. [Anforderungen](#anforderungen)
   - [Funktionen](#funktionen)
   - [Hardware-Komponenten](#hardware-komponenten)
     - [Ursprüngliches Setting](#ursprüngliches-Setting) 
     - [Aktuelles Setting](#aktuelles-Setting)
   - [Software-Komponenten](#software-komponenten)
3. [Scrum Meetings](#scrum-meetings)
   - [20251115_Sprint1](#20251115_sprint1)
   - [20251122_Sprint1 erreicht](#20251122_sprint1-erreicht)
   - [20251122_Sprint2](#20251122_sprint2)
   - [20251129_Sprint2 erreicht](#20251129_sprint2-erreicht)
   - [20251129_Sprint3](#20251129_sprint3)
   - [20251206_Sprint3 erreicht](#20251206_sprint3-erreicht)
   - [20251206_Sprint4](#20251206_sprint4)
   - [20251213_Sprint4 erreicht](#20251213_sprint4-erreicht)
   - [20251213_Sprint5](#20251213_sprint5)
   - [20251222_Sprint5 erreicht](#20251222_sprint5-erreicht)
   - [20251220_Sprint6](#20251220_sprint6)
   - [20260109_Sprint6 erreicht](#20260109_sprint6-erreicht)
4. [Flussdiagramm](#flussdiagramm)
5. [Ablaufdiagramm](#ablaufdiagramm)
6. [Projekt-Links](#projekt-links)
7. [HTTP Test-Befehle](#http-test-befehle)


---

## Projektbeschreibung
Im Rahmen dieses Projekts wird eine Anlage erstellt,
welche die Wasserqualität des BBZ-Teichs und Luftdaten mit Sensoren und einem Controller erfasst.  
Diese Daten werden via lokalen WLAN über eine API an einen Server übertragen,
der sie jeweils in einer separaten csv-Datei speichert.

---

## Anforderungen

### Funktionen
| Funktion                                 | Muss | Wunsch | erfüllt |
|------------------------------------------|------|--------|---------|
| Daten Wassertemperatur erfassen          | X    | -      | OK      |
| Daten Wasserfeststoff erfassen           | X    | -      | OK      |
| Daten in Controller aufbereiten          | X    | -      | OK      |
| Daten via WLAN und API an Server senden  | X    | -      | OK      |
| Daten auf Server speichern in CSV-Datei  | X    | -      | OK      |
| Daten Luft erfassen (Druck/Temp/Feuchte) | -    | X      | OK      |
| Daten Wasser PH-Wert erfassen            | -    | X      | - 1)    |

1) Weil der PH-Sensor nicht erhalten wurde, fehlt diese Wunschfunktion.

### Hardware-Komponenten
#### Ursprüngliches Setting
| Hardware-Komponente     | Bezeichnung             | Typ        |
|-------------------------|-------------------------|------------|
| Microcontroller ESP32   | Freenove ESP32-S3-WROOM | FNK0099    |
| Breakoutboard           | Freenove Breakoutboard  | FNK0091    |
| TDS-Sensor              | Seed Studio SKU X       | 101020753  |
| Temperaturfühler        | DS18B20                 | DS18B20    |
| PH-Messfühler           | DFROBOT                 | SEN0161-V2 |
| Messfühler Luftqualität | BME 680                 | BME 680    |

#### Aktuelles Setting
| Hardware-Komponente     | Bezeichnung             | Typ        |
|-------------------------|-------------------------|------------|
| Microcontroller ESP32   | Freenove ESP32-S3-WROOM | FNK0099    |
| Breakoutboard           | Freenove Breakoutboard  | FNK0091    |
| TDS-Sensor              | Seed Studio SKU X       | 101020753  |
| Temperaturfühler        | DS18B20                 | DS18B20    |
| PH-Messfühler           | DFROBOT                 | SEN0161-V2 |
| Messfühler Luftqualität | BME 680                 | BME 680    |

### Software-Komponenten
| Software-Komponente |
|---------------------|
| CLion               |
| GitHub              |
| MS-Excel            |
| ChatGPT             |


---

## Scrum Meetings

### 20251115_Sprint1
| Sprint-Ziel                  |           
|------------------------------|
| Rollenverteilung             | 
| Projekt-Definition           | 
| Hardware Definition          | 
| Software Definition          | 
| GitHub Repository erstellen  | 

### 20251122_Sprint1 erreicht
| Sprint-Ziel                  | Erfüllt |          
|------------------------------|---------|
| Rollenverteilung             | OK      |
| Projekt-Definition           | OK      |
| Hardware Definition          | OK      |
| Software Definition          | OK      |
| GitHub Repository erstellen  | OK      |

Rollenverteilung:
- Projekt-Owner: Isabel Geissmann
- Tech Lead: Stephan Fankhauser
- Scrum-Master: Peter Meier

#### 20251122_Sprint2
| Sprint-Ziel                                  |           
|----------------------------------------------|
| Datenflussdiagramm erstellen                 | 
| Ablaufdiagramm Controller & Server erstellen |  

#### 20251129_Sprint2 erreicht
| Sprint-Ziel                                  | Erfüllt |          
|----------------------------------------------|---------|
| Datenflussdiagramm erstellen                 | OK      |
| Ablaufdiagramm Controller & Server erstellen | OK      |

#### 20251129_Sprint3
- Sprint-Ziel: (noch nicht ausgefüllt)

#### 20251206_Sprint3 erreicht
- Sprint-Ziel erreicht

#### 20251206_Sprint4
| Sprint-Ziel                                                                                          |           
|------------------------------------------------------------------------------------------------------|
| CLion-Programm API-Server erstellen/Daten vom Controller als CSV-Datei speichern.                    | 
| CLion Programm, das die Daten im Controller erfasst und über WiFi an den API-Server sendet erstellen | 
| Zusammensetzen der Programmteile und Testen mit der Hardware                                         |  

#### 20251213_Sprint4 erreicht
| Sprint-Ziel                                                                                          | Erfüllt |          
|------------------------------------------------------------------------------------------------------|---------|
| CLion-Programm API-Server erstellen/Daten vom Controller als CSV-Datei speichern.                    | OK      |
| CLion Programm, das die Daten im Controller erfasst und über WiFi an den API-Server sendet erstellen | OK      |
| Zusammensetzen der Programmteile und Testen mit der Hardware                                         | - 1)    |

1) Sensoren wurden erst am 12.12.2025 erhalten, deshalb konnte Punkt 3 nicht durchgeführt werden.

#### 20251213_Sprint5
| Sprint-Ziel                                                                                          |           
|------------------------------------------------------------------------------------------------------|
| CLion Programm, das die Daten im Controller erfasst und über WiFi an den API-Server sendet erstellen |   
| Zusammensetzen der Programmteile und Testen mit der Hardware                                         |
| System funktioniert (Hardware und Software)                                                          |
| System im Teich und Lehrerzimmer installiert                                                         |
| Daten über 3 Tage erfasst                                                                            |
| Code auf GitHub gespeichert                                                                          |
| Dokumentation erstellt                                                                               |
| Video erstellt                                                                                       |  
| Test-Dokument erstellt                                                                               |

#### 20251222_Sprint5 erreicht
| Sprint-Ziel                                                                                          | Erfüllt |
|------------------------------------------------------------------------------------------------------|---------|
| CLion Programm, das die Daten im Controller erfasst und über WiFi an den API-Server sendet erstellen | OK      |
| Zusammensetzen der Programmteile und Testen mit der Hardware                                         | OK      |
| System funktioniert (Hardware und Software)                                                          | OK      |
| System im Teich und Lehrerzimmer installiert                                                         | OK      |
| Daten über 3 Tage erfasst                                                                            | - 1)    |
| Code auf GitHub gespeichert                                                                          | OK      |
| Dokumentation erstellt                                                                               | OK      |
| Video erstellt                                                                                       | OK      |
| Test-Dokument erstellt                                                                               | OK      |
| Projektdokumentation abgegeben                                                                       | OK      |

1) Erster Tag Datenerfassung Zuhause in Eimer, zweiter Teil im BBZ-Teich; Es wurde festgestellt, dass das BBZ-WLAN zwischen 23:00 und 06:00 Uhr ausgeschaltet wird.

#### 20251220_Sprint6
| Sprint-Ziel                                |           
|--------------------------------------------|
| Präsentation Projekt im Januar vorbereiten | 
| Präsentation beendet                       | 

#### 20260109_Sprint6 erreicht
| Sprint-Ziel                                | Erfüllt |          
|--------------------------------------------|---------|
| Präsentation Projekt im Januar vorbereiten |         |
| Präsentation beendet                       |         |

---

### Flussdiagramm
![Datenflussdiagramm](Koi_Datenfluss-Diagramm.png)

### Ablaufdiagramm
![Ablaufdiagramm Controller & Server](Flussdiagramm_Wasserqualität.png)

### Projekt-Links
- GitHub Repository 1: [koi_api](https://github.com/softwareentwicklung-hft/koi_api/tree/test)
- GitHub Repository 2: [Koi](https://github.com/Latrusanimi/Koi)
- CSV-Dateien: [waterdata_log.csv](https://github.com/softwareentwicklung-hft/koi_api/blob/test/waterdata_log.csv) 
               [airdata_log.csv](https://github.com/softwareentwicklung-hft/koi_api/blob/test/airdata_log.csv)
- Kanban: [GitHub Projects](https://github.com/users/pesche70/projects/7)
- Videos:
 
### HTTP Test-Befehle

 Luftdaten abrufen

curl -X GET http://<IP-Adresse Server>:18080/koi/air

 Luftdaten speichern

curl -X POST http://<IP-Adresse Server>/koi/air -H "Content-Type: application/json" -d "{\"device_id\": \"SENSOR_01\", \"timestamp\": 1704067200, \"pressure_value\": 1012.5, \"temp_value\": 22.8, \"humidity_value\": 55.7}"

 Wasserdaten speichern

curl -X POST http://<IP-Adresse Server>:18080/koi/water -H "Content-Type: application/json" -d "{\"device_id\": \"SENSOR_02\", \"timestamp\": 1704067200, \"tds_value\": 1012.5, \"temp_value\": 22.8, \"ph_value\": 7}"

 Wasserdaten abrufen

curl -X GET http://<IP-Adresse Server>:18080/koi/water


##  Systemtest

1 Stabilität der W-LAN-Verbindung: Beim Erfassen der Daten wurde festgestellt, dass das BBZ-Netzwerk zwischen 23:00 und 6:00Uhr
  abgestellt wird. Nachdem die Verbindung wiederhergestellt war, lief die Datenerfassung einwandfrei weiter.

2 Fehlen von einzelnen Daten in den csv-Dateien sind uns nicht erklärbar. Weil unsere Testphase zu kurz war,
  konnten wir den Ursachen nicht genauer auf den Grund gehen. Nach dem jetzigen Erkenntnisstand wurde die Verbindung auf der Seite des Mikrocontrollers unterbrochen.
  Gemäss dem geschriebenen Code wird die Verbindung bei einem Unterbruch erneut aufgebaut. Dies scheint geschehen zu sein.

3 Test Wasserdatenerfassung: Die beiden Sensoren wurden während dem Programmieren in verschiedenen Flüssigkeiten (Sprudelwasser, Cola, icetea) eingetaucht und auf Veränderungen verglichen.

4 Test Wasserdatenerfassung: Beim Temperatursensor gab es Probleme mit der Datenerfassung. Deshalb wurde im Code eine Ausgabe auf dem CLion Terminal eingerichtet, um zu sehen, wo der Fehler auftritt. Der Fehler konnte auf einen Wackelkontakt beim Pullup-Widerstand zurückgeführt werden.

5 Test Luftdatenerfassung: Trotz Verbindung wurden beim BME680 nur 0 Werte übertragen. Es wurde daraufhin eine Funktion erstellt mit welcher die Ausgabe jedes Sensors in der Konsole überwacht werden konnte.

6 Test Luftdatenerfassung: Es gab Probleme mit der Einbindung des BME680 Sensors trotz vermeintlich korrektem Code. Es wurde daraufhin eine Funktion erstellt, welche überprüft ob der Sensor korrekt angeschlossen ist. Dies war der Fall, es wurde jedoch festgestellt, dass Softwareseitig die Zuordnung der Pins für den I2C Bus nicht stimmte. Es wurde eine Codezeile eingefügt, welche dieses Problem behob.

7 Test NTP Zeit: Es wurde mittels Überprüfung auf einen Wert, welcher nicht unterschritten werden durfte, sichergestellt, dass die NTP Zeit korrekt übernommen wird. Bei einem Fehler wird auf der Konsole eine entsprechende Meldung ausgegeben.

8 Test Aufbau WLAN Verbindung: Es wurde eine Ausgabe auf der Konsole eingerichtet, mit welcher der Aufbau und Verbindungsstatus der WLAN Verbindung überprüft wird.

9 API: Bei einer geöffneten csv-Datei kann kein Datensatz zugefügt werden. Es gibt auf der Konsole eine Fehlermeldung aus.

10 API: Nach dem erfolgreichen Zufügen eines Datensatzes in einer csv-Datei wird eine Speicherbestätigung auf der Konsole angezeigt.



