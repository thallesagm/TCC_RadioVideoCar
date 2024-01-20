#include <Arduino.h>

#define ACTIVE_A 2
#define PIN_MOTOR_A1 4
#define PIN_MOTOR_A2 5

#define ACTIVE_B 6
#define PIN_MOTOR_B1 7
#define PIN_MOTOR_B2 10


//#define SPEED 150


void moveForward(int trigger_speed){
  analogWrite(ACTIVE_A, trigger_speed);
  analogWrite(ACTIVE_B, trigger_speed);

  digitalWrite(PIN_MOTOR_A1,HIGH);
  digitalWrite(PIN_MOTOR_A2, LOW);
  digitalWrite(PIN_MOTOR_B1,HIGH);
  digitalWrite(PIN_MOTOR_B2,LOW);
}

void moveBack(int trigger_speed){
  analogWrite(ACTIVE_A, trigger_speed);
  analogWrite(ACTIVE_B, trigger_speed);

  digitalWrite(PIN_MOTOR_A1,LOW);
  digitalWrite(PIN_MOTOR_A2, HIGH);
  digitalWrite(PIN_MOTOR_B1,LOW);
  digitalWrite(PIN_MOTOR_B2,HIGH);
}

void moveForwardRight(float analog_direction, float trigger_speed){
  analog_direction = trigger_speed - analog_direction*2;

   analogWrite(ACTIVE_B, trigger_speed);
   analogWrite(ACTIVE_A, analog_direction);

  digitalWrite(PIN_MOTOR_A1,HIGH);
  digitalWrite(PIN_MOTOR_A2, LOW);
  digitalWrite(PIN_MOTOR_B1,HIGH);
  digitalWrite(PIN_MOTOR_B2,LOW);
  
}

void moveForwardLeft(float analog_direction, float trigger_speed){
  analog_direction = trigger_speed - analog_direction*2;

  analogWrite(ACTIVE_B, analog_direction);
  analogWrite(ACTIVE_A, trigger_speed);

  digitalWrite(PIN_MOTOR_A1,HIGH);
  digitalWrite(PIN_MOTOR_A2,LOW);
  digitalWrite(PIN_MOTOR_B1,HIGH);
  digitalWrite(PIN_MOTOR_B2,LOW);
}

void moveBackRight(float analog_direction, float trigger_speed){
  analog_direction = trigger_speed - analog_direction*2;

  analogWrite(ACTIVE_B, trigger_speed);
  analogWrite(ACTIVE_A, analog_direction);

  digitalWrite(PIN_MOTOR_A1,LOW);
  digitalWrite(PIN_MOTOR_A2,HIGH);
  digitalWrite(PIN_MOTOR_B1,LOW);
  digitalWrite(PIN_MOTOR_B2,HIGH);
}

void moveBackLeft(float analog_direction, float trigger_speed){
  analog_direction = trigger_speed - analog_direction*2;

  analogWrite(ACTIVE_B, analog_direction);
  analogWrite(ACTIVE_A, trigger_speed);

  digitalWrite(PIN_MOTOR_A1,LOW);
  digitalWrite(PIN_MOTOR_A2,HIGH);
  digitalWrite(PIN_MOTOR_B1,LOW);
  digitalWrite(PIN_MOTOR_B2,HIGH);
}

void motorInitialize(){
  pinMode(PIN_MOTOR_A1, OUTPUT);
  pinMode(PIN_MOTOR_A2, OUTPUT);
  pinMode(PIN_MOTOR_B1,OUTPUT);
  pinMode(PIN_MOTOR_B2,OUTPUT);

}

void motorStop(){
  digitalWrite(PIN_MOTOR_A1,LOW);
  digitalWrite(PIN_MOTOR_A2,LOW);
  digitalWrite(PIN_MOTOR_B1,LOW);
  digitalWrite(PIN_MOTOR_B2,LOW);
}