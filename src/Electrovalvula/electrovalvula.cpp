/*******************************************************************************
   @file    electrovalvula.cpp
   @brief   Funciones para hacer funcionar la electroválvula
   @author  Paget, Milagros
  	  	  	   Voss, Maria de Guadalupe
********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "../../include/Electrovalvula/electrovalvula.hpp"
#include "../../include/Timer/timer.hpp"
#include "../../include/Pinout/pinout.hpp"
#include <stdio.h>
#include <stdint.h>
#include <Arduino.h>

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH LOCAL SCOPE
 ******************************************************************************/
bool isOpen;

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH LOCAL SCOPE
 ******************************************************************************/
void closeElectrovalvula(void);

/*******************************************************************************
 * FUNCTION DEFINITIONS WITH GLOBAL SCOPE
 ******************************************************************************/
void initElectrovalvula(void){
   pinMode(PIN_ELECTROVALVULA, OUTPUT);
   digitalWrite(PIN_ELECTROVALVULA, LOW); //Si esto hace que se abra entonces cambiarlo
   isOpen = false;
}

void openElectrovalvula(int seconds){
   if(!isOpen){
      digitalWrite(PIN_ELECTROVALVULA, HIGH);
      isOpen = true;
      startTimer(ELECTROVALVULA_TIMER, SEC_2_MSEC(seconds), closeElectrovalvula);
   }
}

void closeElectrovalvula(void){
   digitalWrite(PIN_ELECTROVALVULA, LOW);
   isOpen = false;
}


/*******************************************************************************
 ******************************************************************************/