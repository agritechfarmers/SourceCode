#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

//#include <mysql.h>

#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

char *host, *user, *pass, *db;
int isconnected = 0;

// Replace with your network credentials
const char* ssid     = "B315_F9519";
const char* password = "1GGRTA85GD4";
  
// REPLACE with your Domain name and URL path or IP address with path
const char* serverName = "https://agritechproj.000webhostapp.com/root_esp_data.php";
WiFiClient client;
MySQL_Connection conn((Client *)&client);


// Keep this API Key value to be compatible with the PHP code provided in the project page. 
// If you change the apiKeyValue value, the PHP file /post-esp-data.php also needs to have the same key 
String apiKeyValue = "tPmAT5Ab3j7F9";

String sensorName = "Water Level";
String sensorLocation = "UC";

String bme;

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  host = "remotemysql.com:3306";
  user = "lt8QoXOAiY";
  pass = "SUIMflEtWD";
  db = "lt8QoXOAiY";
  isconnected = mysqli_connect(host,user,pass,db);
  if(isconnected){
    Serial.print("Connected to ");
                Serial.println(host);
  }
  else{
    Serial.println("Connection failed.");
  }
  mysql_close();
  if (conn.connect(server_addr, 3306, user, password)) {
    delay(1000);
  }
  else
    Serial.println("Connection failed.");
}

char rx_byte = 0;

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
      Serial.print(rx_byte);
  }
}
