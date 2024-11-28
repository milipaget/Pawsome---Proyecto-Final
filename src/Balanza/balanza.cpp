/*******************************************************************************
   @file    balanza.cpp
   @brief   Driver de la balanza
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "../include/Balanza/balanza.hpp"
#include "HX711.h"
#include "../include/Pinout/pinout.hpp"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define SCALE 2213.f
#define MIN_weight 0.5

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH LOCAL SCOPE
 ******************************************************************************/
HX711 celda1;
HX711 celda2;

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
void initBalanza(void) {
    Serial.begin(9600);

    celda1.begin(PIN_DT1, PIN_SCK1);
    celda2.begin(PIN_DT2, PIN_SCK2);

    celda1.set_scale(SCALE);
    celda1.tare();

    celda2.set_scale(SCALE);
    celda2.tare();
}

bool updateBalanza(int balanzaNum) {
    if(balanzaNum == BALANZA_1){
        if(celda1.get_units(10) > MIN_weight){
            return false;
        }
        return true;
    }
    else if(balanzaNum == BALANZA_2){
        if(celda2.get_units(10) > MIN_weight){
            return false;
        }
        return true;
    }
    return true;
  
}

/*******************************************************************************
 ******************************************************************************/