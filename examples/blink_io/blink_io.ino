#include <Arduino.h>
#include <Attiny85IO.h>

Attiny85IO io;

void setup(){
  io.pinMode3(OUTPUT);
}

void loop()
{
  io.FastWritePin3(HIGH);
  delay(1000);
  io.FastWritePin3(LOW);
  delay(1000);
}