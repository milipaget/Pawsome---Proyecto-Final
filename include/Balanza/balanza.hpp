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
enum{BALANZA_COMIDA, BALANZA_AGUA}; 

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Inicializa el sensor de ultrasonido
 * @return void
 */
void initBalanzas(void); 

/**
 * @brief Inicializa el sensor de ultrasonido
 * @return void
 */
bool updateBalanza(int balanzaNum);

float pesar(int balanzaNum);
/*******************************************************************************
 ******************************************************************************/

#endif // _BALANZA_HPP_