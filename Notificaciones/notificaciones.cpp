/********************************************************************************
   @file    notificaciones.cpp
   @brief   Notificaciones
   @author  Paget, Milagros
  	  	    Voss, Maria de Guadalupe
**********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "notificaciones.hpp"
#include <Arduino.h>

/*******************************************************************************
 * FUNCTION DEFINITION WITH GLOBAL SCOPE
 ******************************************************************************/

void initNotificaciones(void) {
    // Inicializa la comunicación serie
    Serial.begin(115200);
}

void notify(char* message) {
    Serial.println(message);
}
