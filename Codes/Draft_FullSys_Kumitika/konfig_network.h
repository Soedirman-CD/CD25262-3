#pragma once

#include <WiFi.h>
#include <WiFiClientSecure.h>

#include "local_display.h"

extern const char* ssid;
extern const char* password;

void set_network();
void check_wifi();