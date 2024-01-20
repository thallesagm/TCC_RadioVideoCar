#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include "movement.h"

#define MAX_MESSAGE_LENGTH 20

void handlesCommand (char * command){
    if(strncmp(command, "para!", 5) == 0){
        motorStop();
        analogWrite(4, 0);
    } else
    if(strchr(command, '#') != NULL){
        strtok(command, "#");
        if(strncmp(command,"frente_d", 8) == 0){
            int trigger_speed = atoi(strtok(NULL,"#"));
            int analog_direction = atoi(strtok(NULL, "!"));
            int light = trigger_speed/60;
            analogWrite(4, light);
            moveForwardRight(analog_direction, trigger_speed);
        } else
        if(strncmp(command,"frente_e", 8) == 0){
            int trigger_speed = atoi(strtok(NULL,"#"));
            int analog_direction = atoi(strtok(NULL,"!"));
            int light = trigger_speed/60;
            analogWrite(4, light);
            moveForwardLeft(analog_direction, trigger_speed);
        } else
        if(strncmp(command,"tras_d", 6) == 0){
            int trigger_speed = atoi(strtok(NULL,"#"));
            int analog_direction = atoi(strtok(NULL,"!"));
            moveBackRight(analog_direction, trigger_speed);
        } else
        if(strncmp(command,"tras_e", 6) == 0){
            int trigger_speed = atoi(strtok(NULL,"#"));
            int analog_direction = atoi(strtok(NULL,"!"));
            moveBackLeft(analog_direction, trigger_speed);
        } else
        if(strncmp(command, "frente", 6) == 0){
            int trigger_speed = atoi(strtok(NULL, "!"));
            int light = trigger_speed/60;
            analogWrite(4, light);
            moveForward(trigger_speed);
        } else
        if(strncmp(command, "tras", 4) == 0){
            int trigger_speed = atoi(strtok(NULL,"!"));
            moveBack(trigger_speed);
        }
    } else {
        motorStop();
        analogWrite(4, 0);
    }
} 

char http_command[32] = {0,};
int handlesHTTPCommand(char * variable){
    strcpy(http_command, variable);
    if(!strcmp(variable, "accelerate")) {
        moveForward(200);
        return 0;
    }
    else 
    if(!strcmp(variable, "reverse")) {
        moveBack(200);
        return 0;
    }
    else 
    // if(!strcmp(variable, "stop")) {
    //     motorStop();
    //     return 0;
    // }
    // else
    if(!strcmp(variable, "left")){
        moveForwardLeft(0, 220);
        return 0;
    }
    else 
    if(!strcmp(variable, "right")){
        moveForwardRight(0, 220);
        return 0;
    }
    else {
        return -1;
    }
}


void serialReceiver (void * parameter){
    while(1){
        if (handlesHTTPCommand(http_command) == 0){
            // NADA
        } else
        if (Serial1.available() > 0){
            String message = Serial1.readStringUntil('\n');
            handlesCommand((char *)message.c_str());
        } 
    }
}
