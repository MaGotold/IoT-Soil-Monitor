#ifndef EC_SENSOR_H
#define EC_SENSOR_H

#include <Arduino.h>

#define TDS_PIN 2

class EC_SENSOR {  
    public:
        EC_SENSOR(int pin);
        void begin();
        void update();
        float getVoltage();
        float getTDS();
        
    private:
        int pin;
        int sensorValue;
        float voltage;
        float tds;
};

#endif
