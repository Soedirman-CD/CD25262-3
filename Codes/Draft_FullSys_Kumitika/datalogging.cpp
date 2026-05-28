#include "datalogging.h"

WiFiClientSecure client_log;

const char* serverName = "https://script.google.com/macros/s/AKfycbw02Yl6gkAmaH5w5c_f-aSFeIhrr_uub08SwIAzRyxR/dev";

void set_log() {
  client_log.setInsecure();
}

void send_log() {

  HTTPClient http;

  // VERSION 1
  // String url = String(serverName)
  //   + "?voltage=" + String(voltage)
  //   + "&current=" + String(current)
  //   + "&power=" + String(power)
  //   + "&energy=" + String(energy);

  // http.begin(url);

  // int httpCode = http.GET();
  // if(httpCode > 0) {
  //   logging_success();
  // } else {
  //   logging_failed();
  // }

  // VERSION 2
  http.begin(client_log, serverName);
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  http.addHeader("Content-Type", "application/json");
  String jsonData = "{";
  jsonData += "\"Voltage\":" + String(voltage) + ",";
  jsonData += "\"Current\":" + String(current) + ",";
  jsonData += "\"Power\":" + String(power) + ",";
  jsonData += "\"Energy\":" + String(energy) + ",";
  jsonData += "\"Price\":" + String(price);
  jsonData += "}";
  http.end();
}