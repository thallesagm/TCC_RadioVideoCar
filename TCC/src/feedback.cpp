#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 sensor;

void sensorInitialize(){

    while(!sensor.begin()){
        Serial.println("Failed to find MPU6050 chip");
        delay(10);
    }

    sensor.setAccelerometerRange(MPU6050_RANGE_4_G);
    sensor.setGyroRange(MPU6050_RANGE_250_DEG);
    sensor.setFilterBandwidth(MPU6050_BAND_5_HZ);
}

float getZAcceleration(){
    sensors_event_t a, g, temp;
    sensor.getEvent(&a, &g, &temp);
    if(abs(a.acceleration.z - 9.74) > 1)
        return abs(a.acceleration.z);
    else
        return 0;
}

float getXAcceleration(){
    sensors_event_t a, g, temp;
    sensor.getEvent(&a, &g, &temp);
    if(abs(a.acceleration.x - 0.35) > 1)
        return abs(a.acceleration.x);
    else
        return 0;
}