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
#define PIN_trigger  13  //uso el mismo trigger para ambos sensores
#define PIN_echo1 12
#define PIN_echo2 15
/*Sensor infrarrojo*/
#define PIN_infrarrojo  22
/*Balanzas*/
#define PIN_DT1   16
#define PIN_SCK1  17
#define PIN_DT2   18
#define PIN_SCK2  19
/*Motor*/
#define PIN_ENA   25
#define PIN_IN1   26
#define PIN_IN2   27

/*******************************************************************************
 ******************************************************************************/

#endif // _PINOUT_H_
