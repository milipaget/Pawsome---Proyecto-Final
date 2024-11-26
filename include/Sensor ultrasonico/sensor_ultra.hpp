/********************************************************************************
   @file    sensor_ultra.hpp
   @brief   Driver para el sensor ultrasónico
   @author  Paget, Milagros
  	  	  	   Voss, Maria de Guadalupe
**********************************************************************************/

#ifndef _SENSOR_ULTRA_HPP_
#define _SENSOR_ULTRA_HPP_

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
enum{SENSOR_1, SENSOR_2}; 

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Inicializa el sensor de ultrasonido
 * @return void
 */
void initSensorUltrasonico(void); 

/**
 * @brief Actualiza si la distancia que detecta el sensor es mayor a un cierto valor.
 * @return bool
 */
bool updateSensorUltrasonico(int sensorNum);

/*******************************************************************************
 ******************************************************************************/

#endif // _SENSOR_ULTRA_HPP_
