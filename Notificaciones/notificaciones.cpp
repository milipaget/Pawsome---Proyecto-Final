#include "notificaciones.hpp"
#include <Arduino.h>

void initNotificaciones(void) {
    // Inicializa la comunicación serie
    Serial.begin(115200);
}

void notify(char* message) {
    Serial.println(message);
}
