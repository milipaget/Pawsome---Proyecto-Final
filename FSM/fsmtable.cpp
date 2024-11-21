#include <stdio.h>
#include "fsmtable.hpp"
#include "../Sensor ultrasonico/sensor_ultra.hpp"
#include "../Balanza/balanza.hpp"
#include "../Notificaciones/notificaciones.hpp"

typedef enum{NO_FOOD, NO_WATER, NO_FOOD_NO_WATER};
typedef enum{NO_ERROR, NOT_FED, NOT_WATERED, NOT_EVERYTHING, EMPTY_FOOD, EMPTY_WATER, EMPTY_EVERYTHING};
typedef enum{IDLE, FILL_PLATES, PLATES_EMPTY, CHECK_CONTEINERS, REPORT_ERROR};

static bool foodAvailable; //Para inicializarla 
static bool waterAvailable;
//static bool mode; // true es TIEMPO, false es DEMANDA
static int balanzaState = NO_FOOD_NO_WATER;
static int errorState;
static int currentState;

//Sensor infrarrojo detecta algo --> me fijo balanza --> si vacio, motor --> chequeo ultra --> fin

/*extern STATE idle[]; // si modo a demanda ---> me fijo si el pet está, si SI ---> feedPet; si modo tiempo ---> timer ---> feedPet
extern STATE fillPlates[]; //tengo el pet enfrente, me fijo si hay comida, si NO ---> foodEmpty, si SI ----> idle
extern STATE platesEmpty[]; //si foodAvailable ---> turnMotor(timer) ---> checkFoodContainer
extern STATE checkContainer[]; // me fijo en el sensor si hay comida o no --> si NO ---> reportError y foodAvailable = false, si SI ---> idle y foodAvailable = true
extern STATE reportError[]; //Siempre vuelve a idle*/

// prototipos

static void do_nothing(void);
static void startFilling(void);
static void sendMessage(void);
static bool findPet(void);
static bool checkTimer(void);
static bool weightPlates(void);
static bool isThereSomething(void);
static bool checkAvailability(void);


/*** tablas de estado ***/
void fsm(bool mode){
    switch (currentState)
    {
    case IDLE:
        if(mode?checkTimer():findPet()){
            currentState = FILL_PLATES;
        }
        break;
    case FILL_PLATES:
        if(!weightPlates()){
            currentState = PLATES_EMPTY;
        }
        else{
            currentState = IDLE;
        }
        break;
    case PLATES_EMPTY:
        if(checkAvailability()){
            currentState = CHECK_CONTEINERS;
            startFilling();
        }
        else{
            currentState = REPORT_ERROR;
        }
        break;
    case CHECK_CONTEINERS:
        if(!isThereSomething()){
            currentState = REPORT_ERROR;
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

//========interfaz=================


void FSM_GetInitState(void){
 	currentState = CHECK_CONTEINERS; //Para que inicialice el estado de foodAvailable y waterAvailable 
}

///=========Rutinas de accion===============

static void do_nothing(void){}

static void startFilling(void){
    switch (balanzaState)
    {
    case NO_FOOD:
        //función que hace que el motor gire :)
        break;
    case NO_WATER:
        //función que hace que la válvula se abra :)
        break;
    case NO_FOOD_NO_WATER:
        //función que hace que el motor gire y la válvula se abra:)
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
    if(/*función que me lee la variable del sensor infrarojo*/true){
        return true;
    }
    else{
        return false;
    }
}

static bool checkTimer(void){
    if(/*función que me lee la variable del timer*/true){
        return true;
    }
    else{
        return false;
    }
}

static bool weightPlates(void){
    //Uso BALANZA_1 para comida y BALANZA_2 para agua
    if(balanzaUpdate(BALANZA_1)){
        if(balanzaUpdate(BALANZA_2)){
            return true;
        }
        else{
            balanzaState = NO_WATER;
        }
    }
    else if(balanzaUpdate(BALANZA_2)){
        balanzaState = NO_FOOD;
    }
    else{
        balanzaState = NO_FOOD_NO_WATER;
    }
    return false;
}

static bool isThereSomething(void){
    foodAvailable = sensorUpdate(SENSOR_1);
    waterAvailable = sensorUpdate(SENSOR_2);
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
