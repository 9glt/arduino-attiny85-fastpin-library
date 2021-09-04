# arduino attiny85 fastpin library


example code:
```cpp
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
```

Attiny85IO example:
```
#include <Arduino.h>
#include <Attiny85IO.h>

Attiny85IO io;

void setup(){
  io.pinMode<3,OUTPUT>();
}


// this on my attiny85 with internal 8mhz oscilator gives about 1.35Mhz output.
// uncomment delay to blink LED 
void loop()
{
  io.digitalWrite<3, HIGH>();
  // delay(1000);
  io.digitalWrite<3, LOW>();
  // delay(1000);
}
```