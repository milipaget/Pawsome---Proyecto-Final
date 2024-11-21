#include "sensor_ultra.hpp"
#include "../Pinout/pinout.hpp"
#include <Arduino.h>

void initSensorUltra() {
  Serial.begin(9600);
  pinMode(PIN_led, OUTPUT);
  pinMode(PIN_trigger, OUTPUT);
  pinMode(PIN_echo1, INPUT);
  pinMode(PIN_echo2, INPUT);
  digitalWrite(PIN_trigger, LOW);
}

bool sensorUpdate(int sensorNum) {
  long t; // tiempo que demora en llegar el eco
  long d; // distancia en cm

  digitalWrite(PIN_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_trigger, LOW);

  if(sensorNum == SENSOR_1){
    t = pulseIn(PIN_echo1, HIGH);
  }
  else if(sensorNum == SENSOR_2){
    t = pulseIn(PIN_echo2, HIGH);
  }

  d = t/59;

  if(d<MAX_distance){
    return true;
  }
  else{
    return false;
  }
}
