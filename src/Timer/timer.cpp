/*******************************************************************************
   @file    timer.cpp 
   @brief   timers
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "..\..\include\Timer\timer.hpp"
#include "Arduino.h"
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define NUM_TIMERS 10

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
struct Timer {
    unsigned long duration;
    unsigned long startTime;
    bool isRunning;               // Estado del temporizador
    void (*callback)();           // Función a ejecutar cuando termine
};

/*******************************************************************************
 * FUNCTION DEFINITIONS WITH GLOBAL SCOPE
 ******************************************************************************/
Timer timers[NUM_TIMERS];

void startTimer(int id, unsigned long miliseconds, void (*callback)()) {
    if (id < 0 || id >= NUM_TIMERS) return;
    
    timers[id].duration = miliseconds;
    timers[id].startTime = millis();
    timers[id].isRunning = true;
    timers[id].callback = callback;   // Asignar el callback
    
    Serial.print("Timer ");
    Serial.print(id);
    Serial.println(" started.");
}

void stopTimer(int id) {
    if (id < 0 || id >= NUM_TIMERS) return;
    
    timers[id].isRunning = false;
    Serial.print("Timer ");
    Serial.print(id);
    Serial.println(" stopped.");
}

void updateTimers() {
    for (int i = 0; i < NUM_TIMERS; i++) {
        if (timers[i].isRunning) {
          unsigned long currentTime = millis();
          if (currentTime - timers[i].startTime >= timers[i].duration) {
            timers[i].isRunning = false;   // Marcar el temporizador como detenido
            timers[i].callback();          // Llamar al callback cuando termine
          }
        }
      }
}

/*******************************************************************************
 ******************************************************************************/