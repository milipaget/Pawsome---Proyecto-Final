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
#include "../include/Timer/timer.hpp"
#include "Arduino.h"
#include "../include/Pinout/pinout.hpp"

/*******************************************************************************
 * LOCAL FUNCTION DEFINITION
 ******************************************************************************/
void motorOFF(void);

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH LOCAL SCOPE
 ******************************************************************************/
bool motorStatus;

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
    motorStatus = false;
}

void motorON(int seconds){
    if (!motorStatus){
        digitalWrite(PIN_ENA, HIGH);
        startTimer(MOTOR_TIMER, SEC_2_MSEC(seconds), motorOFF);
        motorStatus = true;
    }
}

void motorOFF(void){
    digitalWrite(PIN_ENA, LOW);
    Serial.println("chau motor");
    motorStatus = false;
}

void turnMotor(void){
    digitalWrite(PIN_ENA, HIGH);
    delay(MOTOR_time);
    Serial.println("motor on :D");
    digitalWrite(PIN_ENA, LOW);
    Serial.println("chau motor");
}

/*******************************************************************************
 ******************************************************************************/