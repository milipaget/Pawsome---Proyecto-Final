/*******************************************************************************
   @file    timer.hpp 
   @brief   timers 
   @author  Paget, Milagros
  	  	  	   Voss, Maria de Guadalupe
********************************************************************************/

#ifndef _TIMER_H_
#define _TIMER_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define SEC_2_MSEC(x) ((x)*1000)
#define MOTOR_TIMER 1
#define ELECTROVALVULA_TIMER 2
#define FOOD_TIMER 3

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Se encarga de iniciar el temporizador.
 * @return void
 */
void startTimer(int id, unsigned long miliseconds, void (*callback)());

/**
 * @brief Se encarga de parar el temporizador.
 * @return void
 */
void stopTimer(int id);

/**
 * @brief Revisa el estado de los temporizadores y muestra el tiempo restante.
 * @return void
 */
void updateTimers();


/*******************************************************************************
 ******************************************************************************/

#endif // _TIMER_H_
