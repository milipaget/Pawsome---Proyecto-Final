#include "Sensor ultrasonico/sensor_ultra.hpp"
#include "Balanza/balanza.hpp"
#include "Pinout/pinout.hpp"
#include "Notificaciones/notificaciones.hpp"
#include "FSM/fsmtable.hpp"
#include <stdio.h>
#include <stdint.h>

typedef enum{DEMANDA, TIEMPO};

static bool mode = DEMANDA;

void appInit(void){
    initSensorUltra();
    initBalanza();
    initNotificaciones();

    FSM_GetInitState(); // Inicializo la FSM con el estado inicial
}

void appRun(void)
{
	fsm(mode);
}

