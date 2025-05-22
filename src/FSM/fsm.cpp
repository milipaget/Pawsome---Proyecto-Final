/********************************************************************************
   @file    fsm.cpp
   @brief   Máquina de estados
   @author  Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
**********************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include "../include/FSM/fsm.hpp"
#include "../include/Sensor ultrasonico/sensor_ultra.hpp"
#include "../include/Balanza/balanza.hpp"
#include "../include/Notificaciones/notificaciones.hpp"
#include "../include/Sensor infrarrojo/sensor_infra.hpp"
#include "../include/Motor/motor.hpp"
#include "../include/Timer/timer.hpp"
#include "../include/Electrovalvula/electrovalvula.hpp"
#include <Arduino.h>

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
enum{NO_FOOD, NO_WATER, NO_FOOD_NO_WATER};
enum{NO_ERROR, NOT_FED, NOT_WATERED, NOT_EVERYTHING, EMPTY_FOOD, EMPTY_WATER, EMPTY_EVERYTHING};
/*Enumeración de estados posibles:
    1. IDLE: Cambia de estado dependiendo del modo de funcionamiento activado. Si está en modo A DEMANDA se
        debe fijar si la mascota se encuentra frente al dispenser. En caso de estar en modo POR TIEMPO, se 
        debe fijar si se acabo el tiempo calculado. En ambos casos que sean TRUE, se pasa al siguiente estado
        FILL_PLATES.
    2. FILL_PLATES: En este estado debe chequearse si hay o no comida/agua en el plato. En caso que haya
        comida/agua se vuelve a IDLE, si está vacío se pasa al estado PLATES_EMPTY.
    3. PLATES_EMPTY: En este estado debe chequearse si hay comida/agua en los contenedores. Si no hay
        comida/agua se pasa directamente a REPORT_ERROR, en cambio si hay se pasa al estado CHECKCONTAINER
        y se dispensa la comida/agua.
    4. CHECK_CONTAINERS: En este estado chequeamos si el contenedor (luego de dar comida/agua) sigue teniendo.
        En caso de tener comida se pone foodAvailable y/o waterAvailable en TRUE y se pasa a IDLE. En caso de
        que estén vacíos se pone el flag correspondiente en FALSE y se pasa a REPORT_ERROR.
    5. REPORT_ERROR: Se notifica al dueño del error ocurrido.
*/
enum{IDLE, FILL_PLATES, PLATES_EMPTY, CHECK_CONTAINERS, REPORT_ERROR};

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH LOCAL SCOPE
 ******************************************************************************/
static bool foodAvailable;
static bool waterAvailable;
static int balanzaState = NO_FOOD_NO_WATER;
static int errorState;
static int currentState;
static bool foodTimerReady;

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH LOCAL SCOPE
 ******************************************************************************/
/**
 * @brief Esta función no hace nada.
 * @return void
 */
static void do_nothing(void);

/**
 * @brief Esta función se encarga de poner el motor en marcha.
 * @return void
 */
static void startFilling(void);

/**
 * @brief Esta función se encarga de enviar el mensaje de notificación.
 * @return void
 */
static void sendMessage(void);

/**
 * @brief Esta función se encarga de fijarse si se detecta a la mascota.
 * @return bool
 */
static bool findPet(void);

/**
 * @brief Esta función se encarga de ver si terminó el timer.
 * @return bool
 */
static void foodTimerCallback (void);

/**
 * @brief Esta función se encarga de ver si los platos ya tienen comida.
 * @return bool
 */
static bool weightPlates(void);

/**
 * @brief Esta función se encarga de ver si los contenedores tienen comida o agua.
 * @return bool
 */
static bool isThereSomething(void);

/**
 * @brief Esta función se encarga de ver el estado de foodAvailable y waterAvailable.
 * @return void
 */
static bool checkAvailability(void);


/*******************************************************************************
 * FUNCTION DEFINITIONS WITH GLOBAL SCOPE
 ******************************************************************************/
void fsm(bool mode){
    switch (currentState)
    {
    case IDLE:
        if(mode?foodTimerReady:findPet()){
            currentState = FILL_PLATES;
            Serial.println("Paso a FILL_PLATES :P");
            if(foodTimerReady){
                foodTimerReady = false; //Reseteo el flag
            }
        }
        break;
    case FILL_PLATES:
        if(!weightPlates()){
            currentState = PLATES_EMPTY;
            Serial.println("Paso a PLATES_EMPTY :P");
        }
        else{
            currentState = IDLE;
        }
        break;
    case PLATES_EMPTY:
        if(checkAvailability()){
            currentState = CHECK_CONTAINERS;
            Serial.println("Paso a CHECK_CONTAINERS :P");
            startFilling();
        }
        else{
            currentState = REPORT_ERROR;
        }
        break;
    case CHECK_CONTAINERS:
        if(!isThereSomething()){
            currentState = REPORT_ERROR;
            Serial.println("Paso a REPORT_ERROR :P");
        }
        else{
            currentState = IDLE;
        }
        break;
    case REPORT_ERROR:
        sendMessage();
        currentState = IDLE;
        break;
    default:
        break;
    }
}

void FSM_GetInitState(Variables variables){
 	currentState = CHECK_CONTAINERS; //Para que inicialice el estado de foodAvailable y waterAvailable 
    foodTimerReady = false;
    if(variables.mode){
        startTimer(FOOD_TIMER, SEC_2_MSEC(variables.timerDuration), foodTimerCallback);
    }
}

/*******************************************************************************
 * FUNCTION DEFINITIONS WITH LOCAL SCOPE
 ******************************************************************************/
//static void do_nothing(void){}

static void startFilling(void){
    //Después hay que pensar un método para que se llene. Tipo pesar en el medio o algo así :D
    //O que con el peso que sacó sepa cuantos segundos abrir :) me gusta más esta
    switch (balanzaState)
    {
    case NO_FOOD:
        motorON(MOTOR_time);
        break;
    case NO_WATER:
        openElectrovalvula(ELECTROVALVULA_time);
        break;
    case NO_FOOD_NO_WATER:
        motorON(MOTOR_time);
        openElectrovalvula(ELECTROVALVULA_time);
        break;
    default:
        break;
    }
}

static void sendMessage(void){
    switch(errorState){
        case NOT_FED:{
            notify("No se pudo alimentar a tu mascota! :(");
            break;
        }
        case NOT_WATERED:{
            notify("No se pudo dar agua a tu mascota! :(");
            break;
        }
        case NOT_EVERYTHING:{
            notify("No se pudo dar agua ni alimentar a tu mascota! :(");
            break;
        }
        case EMPTY_FOOD:{
            notify("Tu contenedor de alimento no tiene comida!");
            break;
        }
        case EMPTY_WATER:{
            notify("Tu contenedor de agua está vacío!");
            break;
        }
        case EMPTY_EVERYTHING:{
            notify("Tus contenedores están vacíos!");
            break;
        }
        default:
        break;
    }
}

static bool findPet(void){
    if(updateSensorInfrarrojo()){
        return true;
    }
    return false;
}

static bool weightPlates(void){
    //Uso BALANZA_1 para comida y BALANZA_2 para agua
    if(updateBalanza(BALANZA_COMIDA)){
        return true;
        if(updateBalanza(BALANZA_AGUA)){
            return true;
        }
        else{
            balanzaState = NO_WATER;
        }
    }
    else if(updateBalanza(BALANZA_AGUA)){
        balanzaState = NO_FOOD;
    }
    else{
        balanzaState = NO_FOOD_NO_WATER;
    }
    return false;
}

static bool isThereSomething(void){
    foodAvailable = updateSensorUltrasonico(SENSOR_1);
    waterAvailable = updateSensorUltrasonico(SENSOR_2);
    if(!foodAvailable){
        if(!waterAvailable){
            errorState = EMPTY_EVERYTHING;
        }
        errorState = EMPTY_FOOD;
    }
    else if(!waterAvailable){
        errorState = EMPTY_WATER;
    }
    return foodAvailable && waterAvailable;
}

static bool checkAvailability(void){
    switch (balanzaState)
    {
    case NO_FOOD:
        if(foodAvailable){
            return true;
        }
        errorState = NOT_FED;
        break;
    case NO_WATER:
        if(waterAvailable){
            return true;
        }
        errorState = NOT_WATERED;
        break;
    case NO_FOOD_NO_WATER:
        if(waterAvailable && foodAvailable){
            return true;
        }
        errorState = NOT_EVERYTHING;
        break;
    
    default:
        break;
    }
    return false;
}

void foodTimerCallback (void){
    currentState = IDLE;
    foodTimerReady = true;
}