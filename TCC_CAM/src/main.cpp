#include <Arduino.h>
#include "movementCom.h"

void setup() {
  Serial1.begin(9600, SERIAL_8N1, 4, 2);
  Serial.begin(115200);
  xTaskCreatePinnedToCore(serialReceiver, "SerialMotorReceiver", 10000, NULL, 1, NULL, 0); 
}

void loop() {
}