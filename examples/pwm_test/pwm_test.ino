#include <Arduino.h>
#include <Attiny85IO.h>

Attiny85IO io;

void setup()
{
    io.pinMode<1, OUTPUT>();
}


// my osciloscope gives about 1.35Mhz frequency with internal 8mhz oscilatos.
void loop()
{
    io.digitalWrite<1, HIGH>();
    io.digitalWrite<1, LOW>();
}
