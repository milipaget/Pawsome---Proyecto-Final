/*******************************************************************************
   @file    motor.cpp
   @brief   Driver del motor
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "../include/Motor/motor.hpp"
#include "Arduino.h"
#include "../include/Pinout/pinout.hpp"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define MAX_time    3000//en milisegundos

/*******************************************************************************
 * FUNCTION DEFINITIONS WITH GLOBAL SCOPE
 ******************************************************************************/
void initMotor(void){
    pinMode(PIN_IN1, OUTPUT);
    pinMode(PIN_IN2, OUTPUT);
    pinMode(PIN_ENA, OUTPUT);
    /* IN1|  HIGH   | LOW
       IN2|   LOW   | HIGH
          |IZQUIERDA|DERECHA
    */
    digitalWrite(PIN_IN1, LOW); //Estos pines podrían ir a masa y vcc
    digitalWrite(PIN_IN2, HIGH); 
}

void turnMotor(void){
    digitalWrite(PIN_ENA, HIGH);
    delay(MAX_time);
    Serial.println("motor on :D");
    digitalWrite(PIN_ENA, LOW);
    Serial.println("chau motor");
}

/*******************************************************************************
 ******************************************************************************/