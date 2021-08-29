#include <Arduino.h>

#include <Attiny85FasterPin.h>

Attiny85FasterPin pin3(3, OUTPUT);

void setup(){}

void loop()
{
  pin3.digitalWrite(HIGH);
  delay(1000);
  pin3.digitalWrite(LOW);
  delay(1000);
}