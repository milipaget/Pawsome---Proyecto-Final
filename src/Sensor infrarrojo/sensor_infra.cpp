/********************************************************************************
   @file    sensor_infra.cpp
   @brief   Driver para el sensor infrarrojo
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
**********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "../include/Sensor Infrarrojo/sensor_infra.hpp"
#include "../include/Pinout/pinout.hpp"
#include <Arduino.h>

/*******************************************************************************
 * FUNCTION DEFINITIONS WITH GLOBAL SCOPE
 ******************************************************************************/
void initSensorInfrarrojo() {
    Serial.begin(9600);
    pinMode(PIN_infrarrojo, INPUT);
}

bool updateSensorInfrarrojo() {
    int valor = digitalRead(PIN_infrarrojo);
    if(valor == LOW){
        return true;
    }
    return false;
}