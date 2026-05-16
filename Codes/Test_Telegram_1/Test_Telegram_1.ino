#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

#define bot_token ""
#define acc_id ""


WiFiClientSecure client_kumi;
UniversalTelegramBot kumi_test1_bot(bot_token, client_kumi);

const char* ssid = "MBG";
const char* password = "pencuriapbn";
long prev_millis = 0, now_millis = 0;

void setup() {
  Serial.begin(115200);
  client_kumi.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  kumi_test1_bot.sendMessage(acc_id, "Bot is online", "");
}

void loop() {
  now_millis = millis();
  if(now_millis - prev_millis >= 10000) {
    kumi_test1_bot.sendMessage(acc_id, "test", "");
    Serial.println("test");
    prev_millis = now_millis;
  }
}