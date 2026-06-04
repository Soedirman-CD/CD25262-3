#pragma once

#include "konfig_network.h"
#include <PubSubClient.h>

extern const char* mqtt_server;
extern const int mqtt_port;
extern const char* mqtt_user;
extern const char* mqtt_pass;
extern const char* mqtt_topic;

extern WiFiClientSecure client_dashboard;
extern PubSubClient client;

extern unsigned long lastMsg;

void set_mqtt();
void stream_data();