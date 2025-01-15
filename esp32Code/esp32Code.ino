#include <WiFi.h>
//#include "Wifi_setup.h"  
#include "temp_sensor.h"
#include "ec_sensor.h"
#include "hum_sensor.h"
#include "mqtt_config.h"  

DS18B20 tempSensor;
EC_SENSOR tdsSensor(TDS_PIN);
HumiditySensor humiditySensor(HUMIDITY_PIN);

void setup() {
    Serial.begin(115200);  
    delay(10);

    connectWiFi();
    setupMQTT();

    tempSensor.begin();
    tdsSensor.begin();
    humiditySensor.begin();
}

void loop() {
    //mqtt connection
    if (!client.connected()) {
        reconnect();
    }
    client.loop();

    //temp
    float temperature = tempSensor.getTemperature();
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    //tds
    tdsSensor.update();
    Serial.print("Sensor Value: ");
    Serial.print(tdsSensor.getVoltage());  
    Serial.print(" Voltage | TDS: ");
    Serial.println(tdsSensor.getTDS(), 2);  

    //hum
    humiditySensor.update();
    int humidity = humiditySensor.getHumidity();
    Serial.print("Humidity: ");
    Serial.println(humidity);

    // Publish data to MQTT broker
    publishData(temperature, humidity, tdsSensor.getTDS());

    delay(2000);  //setting for how often to read
}
