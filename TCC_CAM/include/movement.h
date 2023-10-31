#ifndef MOVEMENT_INCLUDED
#define MOVEMENT_INCLUDED

void moveForward(int trigger_speed);
void moveBack(int trigger_speed);
void moveForwardRight(float analog_direction, float trigger_speed);
void moveForwardLeft(float analog_direction, float trigger_speed);
void moveBackRight(float analog_direction, float trigger_speed);
void moveBackLeft(float analog_direction, float trigger_speed);
void motorInitialize();
void motorStop();

#endif