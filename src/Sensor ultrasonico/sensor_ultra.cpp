/********************************************************************************
   @file    sensor_ultra.hpp
   @brief   Driver para el sensor ultrasónico
   @author  Paget, Milagros
  	  	  	   Voss, Maria de Guadalupe
**********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "../include/Sensor Ultrasonico/sensor_ultra.hpp"
#include "../include/Pinout/pinout.hpp"
#include <Arduino.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define MAX_distance 20 //en cm

/*******************************************************************************
 * FUNCTION DEFINITIONS WITH GLOBAL SCOPE
 ******************************************************************************/
void initSensorUltrasonico() {
  Serial.begin(9600);
  pinMode(PIN_trigger, OUTPUT);
  pinMode(PIN_echo1, INPUT);
  pinMode(PIN_echo2, INPUT);
  digitalWrite(PIN_trigger, LOW);
}

bool updateSensorUltrasonico(int sensorNum) {
  long t = 0; // tiempo que demora en llegar el eco
  long d = 0; // distancia en cm

  digitalWrite(PIN_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_trigger, LOW);

  if(sensorNum == SENSOR_1){
    t = pulseIn(PIN_echo1, HIGH);
  }
  else if(sensorNum == SENSOR_2){
    t = pulseIn(PIN_echo2, HIGH);
  }

  d = t/59;

  if(d<MAX_distance){
    return true;
  }
  else{
    return false;
  }
}
