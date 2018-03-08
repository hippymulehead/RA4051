#include <Arduino.h>
#include <RA4051.h>

/*
Simple demo.  +5v in then an LED and a r220 to ground from each output.
Demo simply walks through the outputs switching the +5v to each of the
outs lighting the LED.
*/

// Init the object and set the pins to use for s0-s2
// RA4051(int s0, int s1, int s2);
RA4051 aswitch(12,11,10);

void setup() {
    // Set it to Pin 0
    aswitch.setPin(0);
    // Set the enable pin
    aswitch.setEnablePin(9);
    // Turn on the chip's outs
    aswitch.on();
}

void loop() {
    // Cycle through the outputs
    for (size_t i = 0; i < 8; i++) {
        aswitch.setPin(i);
        delay(300);
    }
    // Turn off the outputs
    aswitch.off();
    delay(300);
    // Turn them back on and loop
    aswitch.on();
}
