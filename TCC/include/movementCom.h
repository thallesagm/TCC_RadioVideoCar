#ifndef COMMUNICATION_INCLUDED
#define COMMUNICATION_INCLUDED

void sendMoveForward(int trigger_speed);
void sendMoveBack(int trigger_speed);
void sendMoveForwardRight(float analog_direction, float trigger_speed);
void sendMoveForwardLeft(float analog_direction, float trigger_speed);
void sendMoveBackRight(float analog_direction, float trigger_speed);
void sendMoveBackLeft(float analog_direction, float trigger_speed);
void sendMotorStop();

#endif