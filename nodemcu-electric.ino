#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "helpers.h"

char* ssid = "set-wifi";
String password = "set-pass";
String pingUri = "https://elec.vova-lantsov.dev/v1/ping";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting...");
  while (!checkWifiConnection()) {
    delay(500);
  }
  Serial.println("Connected!");
}

void loop() {
  if (checkWifiConnection()) {
    pingServer(pingUri);
    delay(500);
  }
}