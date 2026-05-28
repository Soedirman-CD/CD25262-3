#pragma once

#include "konfig_network.h"
#include <HTTPClient.h>

extern WiFiClientSecure client_log;

extern const char* serverName;

void set_log();
void send_log();