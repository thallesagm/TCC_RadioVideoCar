#include <Arduino.h>


#define ACTIVE_A 12
#define PIN_MOTOR_FRONT 13
#define PIN_MOTOR_REAR 15

#define ACTIVE_B 14

// Can't be defined as pins below due a Wifi and Camera conflict
//#define PIN_MOTOR_B1 16
//#define PIN_MOTOR_B2 0

void moveForward(int trigger_speed){
  analogWrite(ACTIVE_A, trigger_speed);
  analogWrite(ACTIVE_B, trigger_speed);

  digitalWrite(PIN_MOTOR_FRONT,HIGH);
  digitalWrite(PIN_MOTOR_REAR,LOW);
}

void moveBack(int trigger_speed){
  analogWrite(ACTIVE_A, trigger_speed);
  analogWrite(ACTIVE_B, trigger_speed);

  digitalWrite(PIN_MOTOR_FRONT,LOW);
  digitalWrite(PIN_MOTOR_REAR,HIGH);
}

void moveForwardRight(float analog_direction, float trigger_speed){
  analogWrite(ACTIVE_B, analog_direction);
  analogWrite(ACTIVE_A, trigger_speed);

  digitalWrite(PIN_MOTOR_FRONT,HIGH);
  digitalWrite(PIN_MOTOR_REAR,LOW);  
}

void moveForwardLeft(float analog_direction, float trigger_speed){
  analogWrite(ACTIVE_B, trigger_speed);
  analogWrite(ACTIVE_A, analog_direction);

  digitalWrite(PIN_MOTOR_FRONT,HIGH);
  digitalWrite(PIN_MOTOR_REAR,LOW);
}

void moveBackRight(float analog_direction, float trigger_speed){
  analogWrite(ACTIVE_B, analog_direction);
  analogWrite(ACTIVE_A, trigger_speed);

  digitalWrite(PIN_MOTOR_FRONT,LOW);
  digitalWrite(PIN_MOTOR_REAR,HIGH);
}

void moveBackLeft(float analog_direction, float trigger_speed){
  analogWrite(ACTIVE_B, trigger_speed);
  analogWrite(ACTIVE_A, analog_direction);

  digitalWrite(PIN_MOTOR_FRONT,LOW);
  digitalWrite(PIN_MOTOR_REAR,HIGH);
}

void motorStop(){
  analogWrite(ACTIVE_B, 0);
  analogWrite(ACTIVE_A, 0);
  digitalWrite(PIN_MOTOR_FRONT,LOW);
  digitalWrite(PIN_MOTOR_REAR,LOW);
}

void motorInitialize(){
  pinMode(ACTIVE_A, OUTPUT);
  pinMode(ACTIVE_B, OUTPUT);
  pinMode(PIN_MOTOR_FRONT,OUTPUT);
  pinMode(PIN_MOTOR_REAR,OUTPUT);
  motorStop();
}