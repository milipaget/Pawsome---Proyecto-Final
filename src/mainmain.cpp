/********************************************************************************
   @file    main.cpp
   @brief   Aplicación principal
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
**********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "../include/Sensor ultrasonico/sensor_ultra.hpp"
#include "../include/Sensor infrarrojo/sensor_infra.hpp"
#include "../include/Balanza/balanza.hpp"
#include "../include/Pinout/pinout.hpp"
#include "../include/Notificaciones/notificaciones.hpp"
#include "../include/Motor/motor.hpp"
#include "../include/FSM/fsm.hpp"
#include "../include/Timer/timer.hpp"
#include "../include/Electrovalvula/electrovalvula.hpp"
#include "../include/Variables/variables.hpp"
#include <stdio.h>
#include <stdint.h>
#include <Arduino.h>

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/


/*******************************************************************************
 * VARIABLE PROTOTYPES WITH LOCAL SCOPE
 ******************************************************************************/
static Variables variables;

/*******************************************************************************
 * FUNCTION DEFINITIONS WITH LOCAL SCOPE
 ******************************************************************************/

/**
 * @brief En esta función se realizan todas las inicializaciones necesarias para
 *        poder tener el funcionamiento completo del programa.
 * @return void
 */
 /*
void setup(){
    initSensorUltrasonico();
    initSensorInfrarrojo();
    initBalanzas();
    initMotor();
    initNotificaciones();
    initElectrovalvula();
    initVariables();
    FSM_GetInitState(variables); // Inicializo la FSM con el estado inicial
}

/**
 * @brief Esta función ejecuta todas las funciones que se encargan de hacer andar
 *        el programa.
 * @return void
 *//*
void loop(){
	fsm(variables.mode);
    updateTimers();
}

void initVariables(void){
    //En principio inicializo con cualquier cosa
    variables.setMode(DEMANDA);
    variables.setTimerDuration(0);
    variables.resetFoodCounter();
}

void updateVariables(void){
    //Función que lea la data base o lo que sea donde tengamos las variables
}*/