#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid     = "B315_F9519";
const char* password = "1GGRTA85GD4";

char *host, *user, *pass, *db;
int isconnected = 0;

WiFiClient client;
MySQL_Connection conn((Client *)&client);

char server_addr(remotemysql.com: 3306";         // MySQL server IP
char user[] = "lt8QoXOAiY";           // MySQL user
char password[] = "SUIMflEtWD";       // MySQL password

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Connecting to database");
  while (conn.connect(server_addr, 3306, user, password) != true) {
    delay(200);
    Serial.print ( "." );
  }
  Serial.println("");
  Serial.println("Connected to SQL Server!");

}

char rx_byte = 0;

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
    Serial.print(rx_byte);
  }
}
