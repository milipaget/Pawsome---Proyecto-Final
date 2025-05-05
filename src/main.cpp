/*******************************************************************************
   @file    testBalanza.cpp
   @brief   Main para probar la balanza
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "../include/Balanza/balanza.hpp"
#include <stdio.h>
#include <stdint.h>
#include <Arduino.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/


/*******************************************************************************
 * FUNCTION DEFINITIONS WITH GLOBAL SCOPE
 ******************************************************************************/
void setup() {
   Serial.begin(115200);
   initBalanzas();
   Serial.println("Balanzas listas");
 }
 
 void loop() {
   float peso1 = pesar(BALANZA_COMIDA);
   float peso2 = pesar(BALANZA_AGUA);
 
   Serial.print("Balanza 1: ");
   Serial.print(peso1);
   Serial.print(" g | Balanza 2: ");
   Serial.println(peso2);
 
   delay(1000);
 }

/*******************************************************************************
 ******************************************************************************/