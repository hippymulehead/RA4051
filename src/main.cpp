#include <Arduino.h>
#include <RA4051.h>

RA4051 aswitch(12,11,10);

void setup() {
    aswitch.setPin(0);
}

void loop() {
    for (size_t i = 0; i < 8; i++) {
        aswitch.setPin(i);
        delay(300);
    }
}