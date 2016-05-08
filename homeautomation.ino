

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid = "ChiconCollective-Guest";
const char* password = "........";

const char* host = "arduino-node-project-nglaser.c9users.io";
const uint16_t port = 80;
const int lightPin = D5;
WiFiClient client;


void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(lightPin, OUTPUT);
}

void loop() {

  changeLightState();

 
}


void changeLightState() {
    if (client.connect(host, port)) {
          String url =  "/lightstate";
          client.println("GET " + url + " HTTP/1.1");
          client.println("Host: "+ (String)host);
          client.println("User-Agent: Arduino/1.0");
          client.println("Connection: close");
          client.println();
          client.println();
          delay(500);
          String line = "";
          while (client.connected()) {
            line = client.readStringUntil('\n');
          }
          Serial.println("RESPONSE " + line);
          if((String)"true" == line) {
              digitalWrite(lightPin, HIGH);   // Turn the LED on (Note that LOW is the voltage level
          }
          else {
              digitalWrite(lightPin, LOW);   // Turn the LED on (Note that LOW is the voltage level
          }
    }
    else {
      Serial.println("NOT CONNECTED");
    }
}
