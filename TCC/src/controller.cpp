#include <XboxSeriesXControllerESP32_asukiaaa.hpp>
#include <Arduino.h>
#include <math.h>
#include "movementCom.h"
#include "feedback.h"

#define TO_PWM 250/1024
#define TO_ADC 250/65536
#define LEFT_HYSTERESIS 30000
#define RIGHT_HYSTERESIS 35536
#define AXIS_COMPENSATION 125

// Connect to my Xbox Controller
XboxSeriesXControllerESP32_asukiaaa::Core
xboxController("44:16:22:bc:17:64");

// Feedback initialization
XboxSeriesXHIDReportBuilder_asukiaaa::ReportBase repo;

// any xbox controller
// XboxSeriesXControllerESP32_asukiaaa::Core xboxController;

void movementFeedback(float trigger_speed, bool side){
    // SIDE: right = true / left = false
    repo.v.select.center = true;
    repo.v.select.shake = true;
    repo.v.timeActive = 10;
    repo.v.power.center = round(pow(getZAcceleration(),4.0)*1.2);
    repo.v.power.shake = repo.v.power.center;

    if(side){
        repo.v.select.left = false;
        repo.v.select.right = true;
        repo.v.power.right = round(pow(getXAcceleration(),3.0)*1.5);
    } else {
        repo.v.select.left = true;
        repo.v.select.right = false;
        repo.v.power.left = round(pow(getXAcceleration(),3.0)*1.5);
    }
    xboxController.writeHIDReport(repo);
    delay(10);
}

void handleXboxController(void * parameter){

    // XboxSeriesXControllerESP32_asukiaaa::Core
    // xboxController("44:16:22:bc:17:64");

    xboxController.begin();

    float trigger_speed, analog_direction;

    while(true){
        xboxController.onLoop();
        if (xboxController.isConnected()) {
            if (xboxController.isWaitingForFirstNotification()) {
                //Serial.println("waiting for first notification");
            } else {
                //Serial.println("Address: " + xboxController.buildDeviceAddressStr());
                xboxController.buildDeviceAddressStr();
                //Serial.print(xboxController.xboxNotif.toString());
                xboxController.xboxNotif.toString();
                unsigned long receivedAt = xboxController.getReceiveNotificationAt();
            
                //joystickMax -> Max joystick displacement
                uint16_t joystickMax = XboxControllerNotificationParser::maxJoy;

                //If Xbox Controller is OK, then...
                if((float)xboxController.xboxNotif.trigRT>0){
                    trigger_speed = (float)xboxController.xboxNotif.trigRT*TO_PWM;

                    if((float)xboxController.xboxNotif.joyLHori<LEFT_HYSTERESIS){
                        analog_direction = AXIS_COMPENSATION - (float)xboxController.xboxNotif.joyLHori*TO_ADC;
                        sendMoveForwardLeft(analog_direction, trigger_speed);
                    } else 
                    if((float)xboxController.xboxNotif.joyLHori>RIGHT_HYSTERESIS){
                        analog_direction = (float)xboxController.xboxNotif.joyLHori*TO_ADC - AXIS_COMPENSATION;
                        sendMoveForwardRight(analog_direction, trigger_speed);
                    } else
                        sendMoveForward(trigger_speed);
                    movementFeedback(trigger_speed, true);
                } else 
                if((float)xboxController.xboxNotif.trigLT>0){
                    trigger_speed = (float)xboxController.xboxNotif.trigLT*TO_PWM;
                  
                    if((float)xboxController.xboxNotif.joyLHori<LEFT_HYSTERESIS){
                        analog_direction = AXIS_COMPENSATION - (float)xboxController.xboxNotif.joyLHori*TO_ADC;
                        sendMoveBackLeft(analog_direction, trigger_speed);
                    } else 
                    if((float)xboxController.xboxNotif.joyLHori>RIGHT_HYSTERESIS){
                        analog_direction = (float)xboxController.xboxNotif.joyLHori*TO_ADC - AXIS_COMPENSATION;
                        sendMoveBackRight(analog_direction, trigger_speed);
                    } else
                        sendMoveBack(trigger_speed);
                    movementFeedback(trigger_speed, false);
                } else {sendMotorStop();}
            }
        }else{
            //Serial.println("not connected");
            if (xboxController.getCountFailedConnection() > 2) {
            ESP.restart();
            }
        }
    }
}
