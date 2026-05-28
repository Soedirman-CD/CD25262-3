#pragma once

#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

#include "konfig_network.h"
#include "sensor.h"

#define bot_token "8866918276:***"
#define acc_id "acoount id"

extern WiFiClientSecure client_tele;
extern UniversalTelegramBot bot_tele;

void set_tele();
void warning_notify();
void telegram_read();
