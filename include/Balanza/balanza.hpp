/********************************************************************************
   @file    balanza.hpp
   @brief   Driver para la balanza
   @author  Paget, Milagros
  	  	  	   Voss, Maria de Guadalupe
**********************************************************************************/

#ifndef _BALANZA_HPP_
#define _BALANZA_HPP_

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
enum{BALANZA_1, BALANZA_2}; 

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Inicializa el sensor de ultrasonido
 * @return void
 */
void initBalanza(void); 

/**
 * @brief Inicializa el sensor de ultrasonido
 * @return void
 */
bool updateBalanza(int balanzaNum);

/*******************************************************************************
 ******************************************************************************/

#endif // _BALANZA_HPP_