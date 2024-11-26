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
#include <stdio.h>
#include <stdint.h>

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
 * @brief En esta función se realizan todas las inicializaciones necesarias para
 *        poder tener el funcionamiento completo del programa.
 * @return void
 */
void setup(){
    initSensorUltrasonico();
    initSensorInfrarrojo();
    initBalanza();
    initMotor();
    initNotificaciones();

    FSM_GetInitState(); // Inicializo la FSM con el estado inicial
}

/**
 * @brief Esta función ejecuta todas las funciones que se encargan de hacer andar
 *        el programa.
 * @return void
 */
void loop(){
	fsm(mode);
}

