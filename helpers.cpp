#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "helpers.h"

void pingServer(String pingUri) {
  WiFiClient client;
  HTTPClient http;
  
  http.begin(client, pingUri);
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Authorization", "{\"ApiKey\":\"XxBjzojdL4XNyxlw6LiM\"}");
  
  Serial.println("[POST]: " + pingUri);
  
  int httpCode = http.POST("");
  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      const String& payload = http.getString();
      Serial.println("received payload:\n<<");
      Serial.println(payload);
      Serial.println(">>");
    }
  } else {
    Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  
  http.end();
}

bool checkWifiConnection() {
  return WiFi.status() == WL_CONNECTED;
}