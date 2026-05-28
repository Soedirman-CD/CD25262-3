#include "konfig_network.h"
#include "telegram.h"
#include "datalogging.h"
#include "sensor.h"

void setup() {
  set_display();
  set_network();
  set_tele();
  // set_log();
  set_sensor();
}

void loop() {
  sensor_read();
  display_rotate();
  warning_notify();
  telegram_read();
}
