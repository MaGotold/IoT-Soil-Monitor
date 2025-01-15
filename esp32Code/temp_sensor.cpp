#include "temp_sensor.h"

DS18B20::DS18B20() : oneWire(ONE_WIRE_BUS), sensors(&oneWire) {}

void DS18B20::begin() {
    sensors.begin();  
}

float DS18B20::getTemperature() {
    sensors.requestTemperatures();  
    float tempC = sensors.getTempCByIndex(0);  
    return tempC;
}
