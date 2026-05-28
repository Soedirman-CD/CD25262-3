#include "sensor.h"
#include "telegram.h"

PZEM004Tv30 pzem(&Serial2, PZEM_RX_PIN, PZEM_TX_PIN, 0x01);

float voltage;
float current;
float power;
float energy;
float price;
float limit_power;
float limit_price;
float price_kwh;

void set_sensor() {
    voltage = 220;
    current = 0;
    power = 0;
    energy = 0;
    price = 0;
    price_kwh = 1000;
    limit_power = 800;
    limit_price = 50000;
}

float estimate_price(float enrgy, float prc_kwh) {
    return enrgy * prc_kwh;
}

void sensor_read() {
    voltage = pzem.voltage();
    current = pzem.current();
    power = pzem.power();
    energy = pzem.energy();
    price = estimate_price(energy, price_kwh);

    if (isnan(voltage)) voltage = -1;
    if (isnan(current)) current = -1;
    if (isnan(power)) power = -1;
    if (isnan(energy)) energy = -1;
}