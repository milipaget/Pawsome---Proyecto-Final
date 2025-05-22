/*******************************************************************************
   @file    motor.hpp
   @brief   Driver del motor
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
********************************************************************************/

#ifndef _MOTOR_H_
#define _MOTOR_H_

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define MOTOR_time   3000//en milisegundos

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Esta función se encarga de inicializar el motor.
 * @return void
 */
void initMotor(void);

/**
 * @brief Esta función hace que el motor gire por un tiempo determinado.
 * @return void
 */
void turnMotor(void);

/**
 * @brief Prende el motor y su timer.
 * @return void
 */
void motorON(int seconds);

/*******************************************************************************
 ******************************************************************************/

#endif // _MOTOR_H_