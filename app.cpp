/********************************************************************************
   @file    app.cpp
   @brief   Aplicación principal
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
**********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "Sensor ultrasonico/sensor_ultra.hpp"
#include "Balanza/balanza.hpp"
#include "Pinout/pinout.hpp"
#include "Notificaciones/notificaciones.hpp"
#include "FSM/fsm.hpp"
#include <stdio.h>
#include <stdint.h>

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
typedef enum{DEMANDA, TIEMPO};

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
void appInit(void){
    initSensorUltrasonico();
    initBalanza();
    initNotificaciones();

    FSM_GetInitState(); // Inicializo la FSM con el estado inicial
}

/**
 * @brief Esta función ejecuta todas las funciones que se encargan de hacer andar
 *        el programa.
 * @return void
 */
void appRun(void){
	fsm(mode);
}

