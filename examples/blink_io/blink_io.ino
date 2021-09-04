#include <Arduino.h>
#include <Attiny85IO.h>

Attiny85IO io;

void setup(){
  io.pinMode<3, OUTPUT>();
}

void loop()
{
  io.digitalWrite<3, HIGH>();
  delay(1000);
  io.digitalWrite<3, LOW>();
  delay(1000);
}