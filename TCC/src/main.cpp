#include <Arduino.h>
#include "movement.h"
#include "controller.h"
#include "feedback.h"


void setup() {
  Serial.begin(115200);
  Serial1.begin(9600, SERIAL_8N1, 4, 2);
  motorInitialize();
  sensorInitialize();
  xTaskCreate(handleXboxController,"Handle Xbox Controller",8000,NULL,1,NULL);
}


void loop() {
}