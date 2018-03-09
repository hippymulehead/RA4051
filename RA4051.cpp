#include <Arduino.h>
#include <RA4051.h>

RA4051::RA4051(int s0, int s1, int s2) {
    m_s0 = s0;
    m_s1 = s1;
    m_s2 = s2;
    pinMode(m_s0, OUTPUT);
    pinMode(m_s1, OUTPUT);
    pinMode(m_s2, OUTPUT);
    m_currentPin = 0;
    m_eb = 0;
}

RA4051::RA4051(int s0, int s1, int s2, int readPin) {
    m_s0 = s0;
    m_s1 = s1;
    m_s2 = s2;
    m_readPin = readPin;
    pinMode(m_s0, OUTPUT);
    pinMode(m_s1, OUTPUT);
    pinMode(m_s2, OUTPUT);
    pinMode(m_readPin, OUTPUT);
    m_currentPin = 0;
    m_eb = 0;
    m_cr = 1;
}

void RA4051::setEnablePin(int enablePin) {
    m_e = enablePin;
    pinMode(m_e, OUTPUT);
    m_eb = 1;
}

void RA4051::setPin(int pinToSet) {
    if ((pinToSet >= 0) && (pinToSet < 8)) {
        m_currentPin = pinToSet;
        int m_r0 = bitRead(m_currentPin, 0);
        int m_r1 = bitRead(m_currentPin, 1);
        int m_r2 = bitRead(m_currentPin, 2);
        digitalWrite(m_s0, m_r0);
        digitalWrite(m_s1, m_r1);
        digitalWrite(m_s2, m_r2);
    }
}

int RA4051::getCurrentPin() {
    return m_currentPin;
}

void RA4051::on() {
    if ((m_eb == 1) && (m_enableBit != LOW)) {
        digitalWrite(m_e, LOW);
        m_enableBit = LOW;
    }
}

void RA4051::off() {
    if ((m_eb == 1) && (m_enableBit != HIGH)) {
        digitalWrite(m_e, HIGH);
        m_enableBit = HIGH;
    }
}

int RA4051::RADigitalRead() {
    if (m_cr == 1) {
        return digitalRead(m_readPin);
    } else {
        return 0;
    }
}

int RA4051::RAAnalogRead() {
    if (m_cr == 1) {
        return analogRead(m_readPin);
    } else {
        return 0;
    }
}
