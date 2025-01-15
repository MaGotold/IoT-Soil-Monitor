#include "hum_sensor.h"

HumiditySensor::HumiditySensor(int pin) {
    this->pin = pin;
    this->humidityValue = 0;
}

void HumiditySensor::begin() {
    pinMode(this->pin, INPUT);  
}

void HumiditySensor::update() {
    this->humidityValue = analogRead(this->pin);  
}

int HumiditySensor::getHumidity() {
    return this->humidityValue;
}
