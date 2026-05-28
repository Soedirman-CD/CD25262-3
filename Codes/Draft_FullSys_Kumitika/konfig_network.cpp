#include "konfig_network.h"

const char* ssid = "MBG";
const char* password = "pencuriapbn";

void set_network() {
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    display_loading();
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  wifi_notify();
}

void check_wifi() {
 
  if(WiFi.status() != WL_CONNECTED) {
    wifi_reconnect();
    WiFi.disconnect();
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED) {
      display_loading();
    }
    wifi_notify();
  }
}