/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-esp8266-mysql-database-php/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

*/

#ifdef ESP32
  #include <WiFi.h>
  #include <HTTPClient.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
  #include <WiFiClient.h>
#endif

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Replace with your network credentials
const char* ssid     = "B315_F9519";
const char* password = "1GGRTA85GD4";
  
// REPLACE with your Domain name and URL path or IP address with path
const char* serverName = "https://agritechproj.000webhostapp.com/root_esp_data.php";

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
}

void loop()
{
  int pinlevel = analogRead(A0); // read input value
  
  if (pinlevel<=480){ 
    Serial.println(pinlevel);
    Serial.println("Water level: 0mm - Empty!"); 
  }
  else if (pinlevel>480 && pinlevel<=530){ 
     Serial.println(pinlevel);
    Serial.println("Water level: 0mm to 5mm"); 
  }
  else if (pinlevel>530 && pinlevel<=615){ 
     Serial.println(pinlevel);
    Serial.println("Water level: 5mm to 10mm"); 
  }
  else if (pinlevel>615 && pinlevel<=660){ 
     Serial.println(pinlevel);
    Serial.println("Water level: 10mm to 15mm"); 
  } 
  else if (pinlevel>660 && pinlevel<=680){ 
     Serial.println(pinlevel);
    Serial.println("Water level: 15mm to 20mm"); 
  }
  else if (pinlevel>680 && pinlevel<=690){
     Serial.println(pinlevel); 
    Serial.println("Water level: 20mm to 25mm"); 
  }
  else if (pinlevel>690 && pinlevel<=700){ 
     Serial.println(pinlevel);
    Serial.println("Water level: 25mm to 30mm"); 
  }
  else if (pinlevel>700 && pinlevel<=705){ 
     Serial.println(pinlevel);
    Serial.println("Water level: 30mm to 35mm"); 
  }
  else if (pinlevel>705){ 
     Serial.println(pinlevel);
    Serial.println("Water level: 35mm to 40mm"); 
  }
  
  delay(1000); // Check for new value every 5 sec
}
