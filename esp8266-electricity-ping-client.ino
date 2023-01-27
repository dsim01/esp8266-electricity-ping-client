#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

String ssid = "your-ssid";
String password = "your-password";
String apiKey = "your-api-key";
String host = "elec.vova-lantsov.dev";
int port = 443;
String pingUri = "/v1/ping";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("Connected!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClientSecure client;
    client.setInsecure();

    if (!client.connect(host, port)) {
      Serial.println("Connection failed");
      delay(10000);
      return;
    }

    Serial.print("[HTTPS] sending request...\n");
    client.print(String("POST ") + pingUri + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Authorization: ApiKey " + apiKey + "\r\n\r\n");
    Serial.print("[HTTPS] request sent...\n");
    delay(2000);
  }
}