#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>

void sendMoveForward(int trigger_speed){
    char bufferOut[15];
    char str_trigger_speed[4];
    strcpy(bufferOut, "frente#");
    sprintf(str_trigger_speed, "%d", trigger_speed);
    strcat(bufferOut, str_trigger_speed);
    strcat(bufferOut, "!");

    Serial1.println(bufferOut);
}

void sendMoveBack(int trigger_speed){
    char bufferOut[15];
    char str_trigger_speed[4];
    strcpy(bufferOut, "tras#");
    sprintf(str_trigger_speed, "%d", trigger_speed);
    strcat(bufferOut, str_trigger_speed);
    strcat(bufferOut, "!");

    Serial1.println(bufferOut);
}

void sendMoveForwardRight(float analog_direction, float trigger_speed){
    analog_direction = trigger_speed - analog_direction*2;
    if(analog_direction<0){
        analog_direction = 0;
    }
    int int_analog_direction = analog_direction;
    int int_trigger_speed = trigger_speed;
    char bufferOut[20];
    char str_trigger_speed[4], str_analog_direction[4];
    strcpy(bufferOut, "frente_d#");
    sprintf(str_trigger_speed, "%d", int_trigger_speed);
    strcat(bufferOut, str_trigger_speed);
    strcat(bufferOut, "#");
    sprintf(str_analog_direction, "%d", int_analog_direction);
    strcat(bufferOut, str_analog_direction);
    strcat(bufferOut, "!");

    Serial1.println(bufferOut);
}

void sendMoveForwardLeft(float analog_direction, float trigger_speed){
    analog_direction = trigger_speed - analog_direction*2;
    if(analog_direction<0){
        analog_direction = 0;
    }
    int int_analog_direction = analog_direction;
    int int_trigger_speed = trigger_speed;
    char bufferOut[20];
    char str_trigger_speed[4], str_analog_direction[4];
    strcpy(bufferOut, "frente_e#");
    sprintf(str_trigger_speed, "%d", int_trigger_speed);
    strcat(bufferOut, str_trigger_speed);
    strcat(bufferOut, "#");
    sprintf(str_analog_direction, "%d", int_analog_direction);
    strcat(bufferOut, str_analog_direction);
    strcat(bufferOut, "!");

    Serial1.println(bufferOut);
}

void sendMoveBackRight(float analog_direction, float trigger_speed){
    analog_direction = trigger_speed - analog_direction*2;
    if(analog_direction<0){
        analog_direction = 0;
    }
    int int_analog_direction = analog_direction;
    int int_trigger_speed = trigger_speed;
    char bufferOut[20];
    char str_trigger_speed[4], str_analog_direction[4];
    strcpy(bufferOut, "tras_d#");
    sprintf(str_trigger_speed, "%d", int_trigger_speed);
    strcat(bufferOut, str_trigger_speed);
    strcat(bufferOut, "#");
    sprintf(str_analog_direction, "%d", int_analog_direction);
    strcat(bufferOut, str_analog_direction);
    strcat(bufferOut, "!");

    Serial1.println(bufferOut);
}

void sendMoveBackLeft(float analog_direction, float trigger_speed){
    analog_direction = trigger_speed - analog_direction*2;
    if(analog_direction<0){
        analog_direction = 0;
    }
    int int_analog_direction = analog_direction;
    int int_trigger_speed = trigger_speed;
    char bufferOut[20];
    char str_trigger_speed[4], str_analog_direction[4];
    strcpy(bufferOut, "tras_e#");
    sprintf(str_trigger_speed, "%d", int_trigger_speed);
    strcat(bufferOut, str_trigger_speed);
    strcat(bufferOut, "#");
    sprintf(str_analog_direction, "%d", int_analog_direction);
    strcat(bufferOut, str_analog_direction);
    strcat(bufferOut, "!");

    Serial1.println(bufferOut);
}

void sendMotorStop(){
    Serial1.println("para!" + '\0');
}