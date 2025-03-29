/********************************************************************************
   @file    testTimer.cpp
   @brief   Prueba del timer
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
**********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "../include/Timer/timer.hpp"
#include <stdio.h>
#include <stdint.h>
#include <Arduino.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define SECONDS_2_MILISECONDS(x) ((x)*1000) //Macro para pasar de segundos a milisegundos

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/


/*******************************************************************************
 * VARIABLE PROTOTYPES WITH LOCAL SCOPE
 ******************************************************************************/
int prueba = 0;

/*******************************************************************************
 * FUNCTION DEFINITIONS WITH LOCAL SCOPE
 ******************************************************************************/
void callback(void){
    Serial.println("Sip, funciona el callback");
}

/**
 * @brief En esta función se realizan todas las inicializaciones necesarias para
 *        poder tener el funcionamiento completo del programa.
 * @return void
 */
/*void setup(){
    Serial.begin(115200);
    Serial.println("ES EL NUEVO");
}*/

/**
 * @brief Esta función ejecuta todas las funciones que se encargan de hacer andar
 *        el programa.
 * @return void
 */
/*void loop(){
    prueba += 1;
    delay(1000);
    if(prueba == 3){
        startTimer(1, SECONDS_2_MILISECONDS(5), callback);
        Serial.println("Arrancó eh");
    }
    updateTimers();
}*/

