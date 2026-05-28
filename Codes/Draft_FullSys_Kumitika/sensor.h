#pragma once

#include <PZEM004Tv30.h>

#define PZEM_RX_PIN 16
#define PZEM_TX_PIN 17

extern PZEM004Tv30 pzem;

extern float voltage;
extern float current;
extern float power;
extern float energy;
extern float price;
extern float limit_power;
extern float limit_price;
extern float price_kwh;

void set_sensor();
float estimate_price(float enrgy, float prc_kwh);
void sensor_read();
