#include "sensor_ultra.hpp"
#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(PIN_led, OUTPUT);
  pinMode(PIN_trigger, OUTPUT);
  pinMode(PIN_echo, INPUT);
  digitalWrite(PIN_trigger, LOW);
}

void loop() {
  long t; // tiempo que demora en llegar el eco
  long d; // distancia en cm

  digitalWrite(PIN_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_trigger, LOW);

  t = pulseIn(PIN_echo, HIGH);
  d = t/59;

  if(d<10){
    digitalWrite(PIN_led, HIGH);
  }
  else{
    digitalWrite(PIN_led, LOW);
  }

  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.println();
  delay(100);
}
