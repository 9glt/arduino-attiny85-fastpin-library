#include <Attiny85FasterPin.h>

Attiny85FasterPin::Attiny85FasterPin(uint8_t _pin, uint8_t mode)
{
    pin = _pin;
    pinMode(pin, mode);
    if (pin & 128)
    {
        pin = analogInputToDigitalPin((pin & 127));
    }
    timer = digitalPinToTimer(pin);
    bit = (uint8_t)digitalPinToBitMask(pin);
    port = digitalPinToPort(pin);

    if (port == NOT_A_PIN)
        return;
        
    if (timer != NOT_ON_TIMER)
        turnOffPWM(timer);
}

void Attiny85FasterPin::digitalWrite(uint8_t value)
{
    if (value == LOW)
    {
        uint8_t oldSREG = SREG;
        cli();
        PORTB &= ~bit;
        SREG = oldSREG;
    }
    else
    {
        uint8_t oldSREG = SREG;
        cli();
        PORTB |= bit;
        SREG = oldSREG;
    }
}

bool Attiny85FasterPin::digitalRead()
{
    if (port == NOT_A_PIN)
        return LOW;
    if (timer != NOT_ON_TIMER)
        turnOffPWM(timer);

    if (PINB & bit)
        return HIGH;
    return LOW;
}

void Attiny85FasterPin::turnOffPWM(uint8_t timer)
{
#if defined(TCCR0A) && defined(COM0A1)
    if (timer == TIMER0A)
    {
        cbi(TCCR0A, COM0A1);
        //cbi(TCCR0A, COM0A0);
    }
    else
#endif

#if defined(TCCR0A) && defined(COM0B1)
        if (timer == TIMER0B)
    {
        cbi(TCCR0A, COM0B1);
        //cbi(TCCR0A, COM0B0);
    }
    else
#endif

#if defined(TCCR1A) && defined(COM1A1)
        if (timer == TIMER1A)
    {
        cbi(TCCR1A, COM1A1);
        //cbi(TCCR1A, COM1A0);
    }
    else
#endif
#if defined(TCCR1E) //attiny861
        if (timer == TIMER1A)
    {
        // disconnect pwm to pin on timer 1, channel A
        cbi(TCCR1C, COM1A1S);
        cbi(TCCR1C, COM1A0S);
        //cbi(TCCR1A,PWM1A);
    }
    else if (timer == TIMER1B)
    {
        // disconnect pwm to pin on timer 1, channel B
        cbi(TCCR1C, COM1B1S);
        cbi(TCCR1C, COM1B0S);
        //cbi(TCCR1A,PWM1B);
    }
    else if (timer == TIMER1D)
    {
        // disconnect pwm to pin on timer 1, channel D
        cbi(TCCR1C, COM1D1);
        cbi(TCCR1C, COM1D0);
        //cbi(TCCR1A,PWM1D);
    }
    else
#endif
#if defined(TCCR1) && defined(COM1A1)
        if (timer == TIMER1A)
    {
        cbi(TCCR1, COM1A1);
        //cbi(TCCR1, COM1A0);
#ifdef OC1AX
        cbi(TCCR1D, OC1AX);
#endif
    }
    else
#endif

#if defined(TCCR1A) && defined(COM1B1)
        if (timer == TIMER1B)
    {
        cbi(TCCR1A, COM1B1);
        //cbi(TCCR1A, COM1B0);
#ifdef OC1BV
        cbi(TCCR1D, OC1BV);
#endif
    }
    else
#endif

#if defined(TCCR1) && defined(COM1B1)
        if (timer == TIMER1B)
    {
        cbi(GTCCR, COM1B1);
        //cbi(GTCCR, COM1B1);
    }
    else
#endif

    {
    }
}
