#include <Arduino.h>

class Attiny85IO
{
public:
    template <uint8_t pin, uint8_t mode>
    void pinMode();

    template <uint8_t pin, uint8_t value>
    void analogWrite();

    template <uint8_t pin>
    uint16_t analogRead();

    template <uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder>
    uint8_t shiftIn();

    template <uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder>
    void shiftOut(uint8_t val);

    template <uint8_t PIN, uint8_t VALUE>
    void digitalWrite();

    template <uint8_t PIN>
    uint8_t digitalRead();
};

template <uint8_t pin, uint8_t mode>
void Attiny85IO::pinMode()
{
    ::pinMode(pin, mode);
}

template <uint8_t pin, uint8_t value>
void Attiny85IO::analogWrite()
{
    ::analogWrite(pin, value);
}

template <uint8_t pin>
uint16_t Attiny85IO::analogRead()
{
    return ::analogRead(pin);
}

template <uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder>
uint8_t Attiny85IO::shiftIn()
{
    uint8_t value = 0;
    uint8_t i;

    const uint8_t _dataPin = (uint8_t)digitalPinToBitMask(dataPin);
    const uint8_t _clockPin = (uint8_t)digitalPinToBitMask(clockPin);

    for (i = 0; i < 8; ++i)
    {
        PORTB |= _clockPin;
        if (bitOrder == LSBFIRST)
            value |= (!!(PINB & _dataPin)) << i;
        else
            value |= (!!(PINB & _dataPin)) << (7 - i);
        PORTB &= ~(_clockPin);
    }
    return value;
}

template <uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder>
void Attiny85IO::shiftOut(uint8_t val)
{
    uint8_t i;

    const uint8_t _dataPin = (uint8_t)digitalPinToBitMask(dataPin);
    const uint8_t _clockPin = (uint8_t)digitalPinToBitMask(clockPin);

    for (i = 0; i < 8; i++)
    {
        if (bitOrder == LSBFIRST)
        {
            if (!!(val & (1 << i)) == 0)
                PORTB &= ~(_clockPin);
            else
                PORTB |= _clockPin;
        }
        else
        {
            if (!!(val & (1 << (7 - i))) == 0)
                PORTB &= ~(_clockPin);
            else
                PORTB |= _clockPin;
        }

        PORTB |= _dataPin;
        PORTB &= ~(_dataPin);
    }
}

template <uint8_t PIN, uint8_t VALUE>
void Attiny85IO::digitalWrite()
{
    bitWrite(PORTB, PIN, VALUE);
}

template <uint8_t PIN>
uint8_t Attiny85IO::digitalRead()
{
    return bitRead(PORTB, PIN);
}
