#include <Arduino.h>
#include <RA4051.h>

RA4051::RA4051(int s0, int s1, int s2) {
    _s0 = s0;
    _s1 = s1;
    _s2 = s2;
    pinMode(_s0, OUTPUT);
    pinMode(_s1, OUTPUT);
    pinMode(_s2, OUTPUT);
    _currentPin = 0;
    _eb = 0;
}

RA4051::RA4051(int s0, int s1, int s2, int readPin) {
    _s0 = s0;
    _s1 = s1;
    _s2 = s2;
    _readPin = readPin;
    pinMode(_s0, OUTPUT);
    pinMode(_s1, OUTPUT);
    pinMode(_s2, OUTPUT);
    pinMode(_readPin, OUTPUT);
    _currentPin = 0;
    _eb = 0;
    _cr = 1;
}

void RA4051::setEnablePin(int enablePin) {
    _e = enablePin;
    pinMode(_e, OUTPUT);
    _eb = 1;
}

void RA4051::setPin(int pinToSet) {
    if ((pinToSet >= 0) && (pinToSet < 8)) {
        _currentPin = pinToSet;
        int _r0 = bitRead(_currentPin, 0);
        int _r1 = bitRead(_currentPin, 1);
        int _r2 = bitRead(_currentPin, 2);
        digitalWrite(_s0, _r0);
        digitalWrite(_s1, _r1);
        digitalWrite(_s2, _r2);
    }
}

int RA4051::getCurrentPin() {
    return _currentPin;
}

void RA4051::on() {
    if ((_eb == 1) && (_enableBit != LOW)) {
        digitalWrite(_e, LOW);
        _enableBit = LOW;
    }
}

void RA4051::off() {
    if ((_eb == 1) && (_enableBit != HIGH)) {
        digitalWrite(_e, HIGH);
        _enableBit = HIGH;
    }
}

int RA4051::RADigitalRead() {
    if (_cr == 1) {
        return digitalRead(_readPin);
    } else {
        return 0;
    }
}

int RA4051::RAAnalogRead() {
    if (_cr == 1) {
        return analogRead(_readPin);
    } else {
        return 0;
    }
}