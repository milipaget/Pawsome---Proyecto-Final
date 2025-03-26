/********************************************************************************
   @file    testMotor.cpp
   @brief   Main para probar el motor
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
**********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "../include/Motor/motor.hpp"
#include <stdio.h>
#include <stdint.h>
#include <Arduino.h>

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
enum{DEMANDA, TIEMPO};

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH LOCAL SCOPE
 ******************************************************************************/
static bool mode = DEMANDA;

/*******************************************************************************
 * FUNCTION DEFINITIONS WITH LOCAL SCOPE
 ******************************************************************************/

/**
 * @brief En esta función se inicializa el motor.
 * @return void
 */
void setup(){
    initMotor();
}

/**
 * @brief Esta función ejecuta todas las funciones que se encargan de probar las
 *        diferentes características necesarias para el motor.
 * @return void
 */
void loop(){
	
}