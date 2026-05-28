#include "local_display.h"
#include "sensor.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
unsigned long lcd_timer, lcd_timerInterval;
unsigned short displayPage;

void set_display() {
    Serial.begin(115200);
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Setting up...");
    lcd_timer = millis();
    lcd_timerInterval = 2000;
    delay(500);
}

void display_loading() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Connecting WiFi");

    for(int i=0; i<4; i++) {
        lcd.setCursor(i,1);
        lcd.print(".");
        Serial.print(".");
        delay(100);
    }
}

void wifi_notify() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("WiFi Connected");
    lcd.setCursor(0,1);
    lcd.print(WiFi.localIP());
    delay(500);
}

void wifi_reconnect() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("WiFi Lost!");
    lcd.setCursor(0,1);
    lcd.print("Reconnecting...");
}

void display_page_voltage_current() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(voltage,1);
    lcd.print(" V");
    lcd.setCursor(0,1);
    lcd.print(current,3);
    lcd.print(" A");
}

void display_page_power_energy() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(power,1);
    lcd.print(" W");
    lcd.setCursor(0,1);
    lcd.print(energy,3);
    lcd.print(" kWh");
}

void display_page_cost() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Est. Cost:");
    lcd.setCursor(0,1);
    lcd.print("Rp ");
    lcd.print(price,0);
}

void display_rotate() {
    if(millis() - lcd_timer >= lcd_timerInterval) {
        lcd_timer = millis();
        switch(displayPage) {
            case 0:
                display_page_voltage_current();
                break;
            case 1:
                display_page_power_energy();
                break;
            case 2:
                display_page_cost();
                break;
        }
        displayPage++;
        if(displayPage > 2) {
            displayPage = 0;
        }
    }
}