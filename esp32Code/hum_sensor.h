#ifndef HUM_SENSOR.H
#define HUM_SENSOR.H

#include <Arduino.h>

#define HUMIDITY_PIN 15  

class HumiditySensor {
    public:
        HumiditySensor(int pin);
        void begin();
        void update();
        int getHumidity();

    private:
        int pin;
        int humidityValue;
};

#endif
