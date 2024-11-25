/********************************************************************************
   @file    sensor_infra.hpp
   @brief   Driver para el sensor infrarrojo
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
**********************************************************************************/

#ifndef _SENSOR_INFRA_HPP_
#define _SENSOR_INFRA_HPP_

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Inicializa el sensor de infrarrojo
 * @return void
 */
void initSensorInfrarrojo(void); 

/**
 * @brief Verifica si el sensor detecta algo. 
 * @return bool
 */
bool updateSensorInfrarrojo(void);

/*******************************************************************************
 ******************************************************************************/

#endif // _SENSOR_INFRA_HPP_

