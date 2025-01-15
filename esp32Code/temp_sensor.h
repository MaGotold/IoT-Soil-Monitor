#ifndef TEMP_SENSOR.H
#define TEMP_SENSOR.H

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 17  

class DS18B20 {
    public:
        DS18B20();
        void begin();
        float getTemperature();
        
    private:
        OneWire oneWire;
        DallasTemperature sensors;
};

#endif
