/*******************************************************************************
   @file    fsm.h
   @brief   Máquina de estados
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
********************************************************************************/

#ifndef _FSM_H_
#define _FSM_H_

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Esta función se encarga de inicializar la máquina de estados.
 * @return void
 */
void FSM_GetInitState(void);

/**
 * @brief Esta función se encarga de actualizar el estado de la máquina de estados 
 *        y ejecutar la función correspondiente.
 * @return void
 */
void fsm(bool mode);

/*******************************************************************************
 ******************************************************************************/

#endif // _FSM_H_
