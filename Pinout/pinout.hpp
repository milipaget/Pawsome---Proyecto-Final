/*******************************************************************************
   @file     pinout.h
   @brief    Archivo que contiene el pinout de la ESP32
   @author Paget, Milagros
  	  	   Voss, Maria de Guadalupe
********************************************************************************/

#ifndef _PINOUT_H_
#define _PINOUT_H_

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
/*Sensores de ultrasonido*/
#define PIN_trigger 13  //uso el mismo trigger para ambos sensores
#define PIN_echo1 12
#define PIN_echo2 15
/*Sensor infrarrojo*/
#define PIN_infrarrojo 8
/*Balanzas*/
#define PIN_DT1 2
#define PIN_SCK1 3
#define PIN_DT2 4
#define PIN_SCK2 5

/*******************************************************************************
 ******************************************************************************/

#endif // _PINOUT_H_
