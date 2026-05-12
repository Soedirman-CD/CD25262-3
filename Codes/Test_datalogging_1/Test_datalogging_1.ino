#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

const char* ssid = "MBG";
const char* password = "pencuriapbn";

const char* serverName = "https://script.google.com/macros/s/AKfycbzPi0CDfuqNoax6Q9pHIQNVpCOtnrgkdVOipvFxbI_HGMeUX4MvOjyfE5068spZXAgD0Q/exec";

WiFiClientSecure client;

float voltage = 200;
float current = 0;
float power = 0;
float kWh = 0;
float tarif = 0;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Connecting...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected!");

  client.setInsecure(); // penting untuk HTTPS
}
void loop() {
  voltage = random(218,222);
  current = random(0,4);
  power = voltage * current;
  kWh = kWh + (power / 1000);
  tarif = kWh * 700;

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    http.begin(client, serverName);
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS); // WAJIB
    http.addHeader("Content-Type", "application/json");

    String jsonData = "{";
    jsonData += "\"data1\":" + String(voltage) + ",";
    jsonData += "\"data2\":" + String(current) + ",";
    jsonData += "\"data3\":" + String(power) + ",";
    jsonData += "\"data4\":" + String(kWh) + ",";
    jsonData += "\"data5\":" + String(tarif);
    jsonData += "}";

    Serial.println(jsonData); // DEBUG

    int httpResponseCode = http.POST(jsonData);

    Serial.print("HTTP Response: ");
    Serial.println(httpResponseCode);

    http.end();
  }

  delay(5000);
}