#include <Attiny85IO.h>

void Attiny85IO::pinMode0(uint8_t mode)
{
    pinMode(0, mode);
}

void Attiny85IO::pinMode1(uint8_t mode)
{
    pinMode(1, mode);
}

void Attiny85IO::pinMode2(uint8_t mode)
{
    pinMode(2, mode);
}

void Attiny85IO::pinMode3(uint8_t mode)
{
    pinMode(3, mode);
}

void Attiny85IO::pinMode4(uint8_t mode)
{
    pinMode(4, mode);
}
void Attiny85IO::pinMode5(uint8_t mode)
{
    pinMode(5, mode);
}

uint8_t Attiny85IO::FastReadPin0()
{
    return PINB & 1 << PB0;
}

uint8_t Attiny85IO::FastReadPin1()
{
    return PINB & 1 << PB1;
}

uint8_t Attiny85IO::FastReadPin2()
{
    return PINB & 1 << PB2;
}

uint8_t Attiny85IO::FastReadPin3()
{
    return PINB & 1 << PB3;
}

uint8_t Attiny85IO::FastReadPin4()
{
    return PINB & 1 << PB4;
}

uint8_t Attiny85IO::FastReadPin5()
{
    return PINB & 1 << PB4;
}

void Attiny85IO::FastWritePin0(uint8_t value)
{
    if (value == HIGH)
    {
        PORTB |= 1 << PB0;
    }
    else
    {
        PORTB &= ~(PORTB & 1 << PB0);
    }
}

void Attiny85IO::FastWritePin1(uint8_t value)
{
    if (value == HIGH)
    {
        PORTB |= 1 << PB1;
    }
    else
    {
        PORTB &= ~(PORTB & 1 << PB1);
    }
}

void Attiny85IO::FastWritePin2(uint8_t value)
{
    if (value == HIGH)
    {
        PORTB |= 1 << PB2;
    }
    else
    {
        PORTB &= ~(PORTB & 1 << PB2);
    }
}

void Attiny85IO::FastWritePin3(uint8_t value)
{
    if (value == HIGH)
    {
        PORTB |= 1 << PB3;
    }
    else
    {
        PORTB &= ~(PORTB & 1 << PB3);
    }
}

void Attiny85IO::FastWritePin4(uint8_t value)
{
    if (value == HIGH)
    {
        PORTB |= 1 << PB4;
    }
    else
    {
        PORTB &= ~(PORTB & 1 << PB4);
    }
}

void Attiny85IO::FastWritePin5(uint8_t value)
{
    if (value == HIGH)
    {
        PORTB |= 1 << PB5;
    }
    else
    {
        PORTB &= ~(PORTB & 1 << PB5);
    }
}

void Attiny85IO::AnalogWritePin0(uint8_t value)
{
    analogWrite(0, value);
}

void Attiny85IO::AnalogWritePin1(uint8_t value)
{
    analogWrite(1, value);
}

void Attiny85IO::AnalogWritePin4(uint8_t value)
{
    analogWrite(4, value);
}

uint8_t Attiny85IO::AnalogReadPin0()
{
    return analogRead(0);
}
uint8_t Attiny85IO::AnalogReadPin1()
{
    return analogRead(1);
}
uint8_t Attiny85IO::AnalogReadPin2()
{
    return analogRead(2);
}
uint8_t Attiny85IO::AnalogReadPin3()
{
    return analogRead(3);
}
uint8_t Attiny85IO::AnalogReadPin4()
{
    return analogRead(4);
}
uint8_t Attiny85IO::AnalogReadPin5()
{
    return analogRead(5);
}