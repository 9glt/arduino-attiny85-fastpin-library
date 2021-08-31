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
  io.pinMode3(OUTPUT);
}

void loop()
{
  io.FastWritePin3(HIGH);
  delay(1000);
  io.FastWritePin3(LOW);
  delay(1000);
}
```