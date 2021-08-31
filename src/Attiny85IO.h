#include <Arduino.h>

class Attiny85IO
{

public:
    void pinMode0(uint8_t value);
    void pinMode1(uint8_t value);
    void pinMode2(uint8_t value);
    void pinMode3(uint8_t value);
    void pinMode4(uint8_t value);
    void pinMode5(uint8_t value);

    uint8_t FastReadPin0();
    uint8_t FastReadPin1();
    uint8_t FastReadPin2();
    uint8_t FastReadPin3();
    uint8_t FastReadPin4();
    uint8_t FastReadPin5();

    void FastWritePin0(uint8_t value);
    void FastWritePin1(uint8_t value);
    void FastWritePin2(uint8_t value);
    void FastWritePin3(uint8_t value);
    void FastWritePin4(uint8_t value);
    void FastWritePin5(uint8_t value);

    void AnalogWritePin0(uint8_t value);
    void AnalogWritePin1(uint8_t value);
    void AnalogWritePin4(uint8_t value);

    uint8_t AnalogReadPin0();
    uint8_t AnalogReadPin1();
    uint8_t AnalogReadPin2();
    uint8_t AnalogReadPin3();
    uint8_t AnalogReadPin4();
    uint8_t AnalogReadPin5();
};