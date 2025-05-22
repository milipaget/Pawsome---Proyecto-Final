/*******************************************************************************
   @file    variables.hpp 
   @brief   Este archivo es para definir las variables que se pueden configurar
            desde la página web.
   @author  Paget, Milagros
  	  	  	   Voss, Maria de Guadalupe
********************************************************************************/

#ifndef VARIABLES_HPP
#define VARIABLES_HPP

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
enum{DEMANDA, TIEMPO};

struct Variables {
    bool mode;
    unsigned long timerDuration; //Cada cuanto gira el motor si modo tiempo :D, en SEGUNDOS!
    int foodCounter; //Contador de cuantas veces dio de comer por día :D

    void setMode(bool newMode) {
        mode = newMode;
    }

    void setTimerDuration(unsigned long duration) {
        timerDuration = duration;
    }

    void incrementFoodCounter() {
        foodCounter++;
    }

    void resetFoodCounter() {
        foodCounter = 0;
    }
};

/*******************************************************************************
 ******************************************************************************/

 #endif // VARIABLES_HPP