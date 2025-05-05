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
HX711 celdaComida;
HX711 celdaAgua;

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
void initBalanzas(void) {
    Serial.begin(9600);

    celdaComida.begin(PIN_DT_COMIDA, PIN_SCK_COMIDA);
    celdaAgua.begin(PIN_DT_AGUA, PIN_SCK_AGUA);

    celdaComida.set_scale(SCALE);
    celdaComida.tare();

    celdaAgua.set_scale(SCALE);
    celdaAgua.tare();
}

bool updateBalanza(int balanzaNum) {
    if(balanzaNum == BALANZA_COMIDA){
        if(celdaComida.get_units(10) > MIN_weight){
            return false;
        }
        return true;
    }
    else if(balanzaNum == BALANZA_AGUA){
        if(celdaAgua.get_units(10) > MIN_weight){
            return false;
        }
        return true;
    }
    return true;
  
}

float pesar(int balanzaNum){
    if(balanzaNum == BALANZA_COMIDA){
        return celdaComida.get_units(10);
    }
    else if(balanzaNum == BALANZA_AGUA){
        return celdaAgua.get_units(10);
    }
}

/*******************************************************************************
 ******************************************************************************/