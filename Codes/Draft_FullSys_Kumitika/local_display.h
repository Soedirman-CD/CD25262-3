#pragma once

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>

#include "sensor.h"

extern LiquidCrystal_I2C lcd;

// Setup
void set_display();
void display_loading();
void wifi_notify();
void wifi_reconnect();
void display_page_voltage_current();
void display_page_power_energy();
void display_page_cost();
void display_rotate();