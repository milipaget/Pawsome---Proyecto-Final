/*******************************************************************************
   @file    electrovalvula.hpp 
   @brief   Funciones para controlar la electroválvula 
   @author  Paget, Milagros
  	  	  	   Voss, Maria de Guadalupe
********************************************************************************/

#ifndef _ELECTROVALVULA_H_
#define _ELECTROVALVULA_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define ELECTROVALVULA_time    3000//en milisegundos

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
 * @brief Initialize vumeter, changing led colors and starting vumeter in "on" mode.
 * @return void
 */
void initElectrovalvula(void);

/**
 * @brief Initialize vumeter, changing led colors and starting vumeter in "on" mode.
 * @return void
 */
void openElectrovalvula(int seconds);

/*******************************************************************************
 ******************************************************************************/

#endif // _ELECTROVALVULA_H_
