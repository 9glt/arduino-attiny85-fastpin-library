#include <Arduino.h>
#include <wiring_private.h>

#ifndef analogInputToDigitalPin(p)
#define analogInputToDigitalPin(p)  (((p) == 0) ? 5 : (((p) == 1) ? 2 : (((p) == 2) ? 4 :(((p) == 3) ? 3 : -1))))
#endif


class Attiny85FasterPin {
    private:
        uint8_t timer;
        uint8_t bit;
        uint8_t port;
        uint8_t pin;
        void turnOffPWM(uint8_t timer);
    public:
    Attiny85FasterPin(uint8_t pin, uint8_t mode);
    bool digitalRead();
    void digitalWrite(uint8_t value); // __attribute__((always_inline));
};
