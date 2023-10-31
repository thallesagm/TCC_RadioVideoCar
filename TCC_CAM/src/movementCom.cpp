#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include "movement.h"

#include "BluetoothSerial.h"

#define MAX_MESSAGE_LENGTH 20

void handlesCommand (char * command){
    if(!strcmp(command, "para!")){
        motorStop();
        pinMode(12, OUTPUT);
        digitalWrite(12, HIGH);
    } else
    if(strchr(command, '#') != NULL){
        pinMode(13, OUTPUT);
        digitalWrite(13, HIGH);
        strtok(command, "#");
        if(!strcmp(command, "frente")){
            int trigger_speed = atoi(strtok(NULL, "!"));
            moveForward(trigger_speed);
        } else
        if(!strcmp(command, "tras")){
            int trigger_speed = atoi(strtok(NULL,"!"));
            moveBack(trigger_speed);
        } else
        if(strcmp(command,"frente_d") == 0){
            int trigger_speed = atoi(strtok(NULL,"#"));
            int analog_direction = atoi(strtok(NULL, "!"));
            moveForwardRight(analog_direction, trigger_speed);
        } else
        if(strcmp(command,"frente_e") == 0){
            int trigger_speed = atoi(strtok(NULL,"#"));
            int analog_direction = atoi(strtok(NULL,"!"));
            moveForwardLeft(analog_direction, trigger_speed);
        } else
        if(strcmp(command,"tras_d") == 0){
            int trigger_speed = atoi(strtok(NULL,"#"));
            int analog_direction = atoi(strtok(NULL,"!"));
            moveForwardRight(analog_direction, trigger_speed);
        }
    } else {
        pinMode(12, OUTPUT);
        digitalWrite(12, LOW);
        pinMode(13, OUTPUT);
        digitalWrite(13, LOW);
    }
} 

void serialReceiver (void * parameter){
    BluetoothSerial SerialBT;
    SerialBT.begin("ESP32_CAM");
    while(1){
        if (Serial1.available() > 0){
            String message = Serial1.readStringUntil('\n');

            //PRINT PARA VERIFICAR SE ESTA RECEBENDO (ESTÁ OK!)
            SerialBT.println(message);

            //COMPARAÇÕES DO QUE FOI RECEBIDO ABAIXO:
            if(message == "para!"){
                SerialBT.println("PRIMEIRO");
            }

            if(strcmp(message.c_str(), "para!") == 0){
                SerialBT.println("SEGUNDO");
            }
            
            if(message.equals("para!")){
                SerialBT.println("TERCEIRO");
            }

        
        //handlesCommand((char *)message.c_str());

        }   
    }
}
