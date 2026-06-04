#include "mqtt_dashboard.h"

const char* mqtt_server  = "....s1.eu.hivemq.cloud";
const int mqtt_port      = 8883; // Port standar MQTT SSL/TLS untuk ESP32
const char* mqtt_user    = "...";
const char* mqtt_pass    = "...";
const char* mqtt_topic   = "Smart Home";

unsigned long lastMsg = 0;

WiFiClientSecure client_dashboard;
PubSubClient client(client_dashboard);

void set_mqtt() {

  client_dashboard.setInsecure();
  client.setServer(mqtt_server, mqtt_port);

  while(!client.connected()) {

    Serial.println("Connecting MQTT...");

    if(client.connect("ESP32Client", mqtt_user, mqtt_pass)) {

      Serial.println("MQTT Connected");
    }

    else {
      Serial.print("MQTT Failed: ");
      Serial.println(client.state());
      delay(500);
    }
  }
}

void stream_data() {

    if(!client.connected()) {
    set_mqtt();
  }
  // Versi 1
  String jsonData2 = "{";
  jsonData2 += "\"tegangan\":" + String(voltage,1) + ",";
  jsonData2 += "\"arus\":" + String(current,3) + ",";
  jsonData2 += "\"daya\":" + String(power,1) + ",";
  jsonData2 += "\"energi\":" + String(energy,3) + ",";
  jsonData2 += "\"biaya\":" + String(price);
  jsonData2 += "}";

  // Versi 2
  // StaticJsonDocument<256> doc;
  //   doc["tegangan"]  = voltage;
  //   doc["arus"]      = current;
  //   doc["daya"]      = power;
  //   doc["energi"]    = energy;
  //   doc["biaya"]    = price;

  //   // Convert JSON ke string buffer
  //   char jsonData2[256];
  //   serializeJson(doc, jsonData2);

  //   // 3. Publish ke Topik MQTT
  //   Serial.print("Mengirim data: ");
  //   Serial.println(jsonData2);

    client.publish(mqtt_topic, jsonData2.c_str());
}