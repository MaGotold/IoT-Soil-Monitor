#include "ec_sensor.h"

EC_SENSOR::EC_SENSOR(int pin) {
    this->pin = pin;
    this->sensorValue = 0;
    this->voltage = 0.0;
    this->tds = 0.0;
}

void EC_SENSOR::begin() {
    pinMode(this->pin, INPUT);  
}

void EC_SENSOR::update() {
    this->sensorValue = analogRead(this->pin);

    this->voltage = this->sensorValue * (3.3 / 4095.0);

    this->tds = (this->voltage - 0.5) * 1000.0;  
}

float EC_SENSOR::getVoltage() {
    return this->voltage;
}

float EC_SENSOR::getTDS() {
    return this->tds;
}
