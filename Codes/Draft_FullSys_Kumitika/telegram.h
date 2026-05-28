#pragma once

#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

#include "konfig_network.h"
#include "sensor.h"

#define bot_token "8866918276:AAFB7Q_0S5e39b2pAxd2G6SbIlr0jKAcnSI"
#define acc_id "7420580424"

extern WiFiClientSecure client_tele;
extern UniversalTelegramBot bot_tele;

void set_tele();
void warning_notify();
void telegram_read();