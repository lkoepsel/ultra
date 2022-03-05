#include "frequency.h"

void blue_led(uint8_t intensity) {

    // Blue LED Indicator, Dim
    // set UNO pin 6/PD6 to output, 976.6Hz, 12% duty cycle
    DDRD |=  _BV(DDD6);
    
    // TCCR0A [ COM0A1 COM0A0 COM0B1 COM0B0 0 0 WGM21 WGM20 ] = 11000010
    TCCR0A |= (_BV(COM0A1) | _BV(WGM21) | _BV(WGM20));

    // TCCR0B [ FOC2A FOC2B 0 0 WGM22 CS22 CS21 CS20 ]
    TCCR0B |=  (_BV(CS21) | _BV(CS20));

    OCR0A = intensity;
return;
}   

void audible(uint8_t d_c) {
    // Speaker, Audible Audio
    // set UNO pin 10/PB2 to output, 7.8kHz, 50% duty cycle
    DDRB |=  _BV(DDB2);
    
    // TCCR1A [ COM1A1 COM1A0 COM1B1 COM1B0 0 0 WGM11 WGM10  ] = 00100001
    TCCR1A |= (_BV(COM1B1) | _BV(WGM10));

    // TCCR1B [ 1CNC1 1CES1 0 WGM13 WGM12 CS12 CS11 CS10 ]
    TCCR1B |= (_BV(WGM12) | _BV(CS12) | _BV(CS10));

    OCR1B = d_c;
return;
}	

void ultra_low(uint8_t d_c) {
    // Speaker, Low Ultrasonic
    // set UNO pin 10/PB2 to output, 32.2kHz, 50% duty cycle
    DDRB |=  _BV(DDB2);
    
    // TCCR1A [ COM1A1 COM1A0 COM1B1 COM1B0 0 0 WGM11 WGM10  ] = 00100010
    TCCR1A |= (_BV(COM1B1) | _BV(WGM11));

    // TCCR1B [ 1CNC1 1CES1 0 WGM13 WGM12 CS12 CS11 CS10 ]
    TCCR1B |= (_BV(WGM12) | _BV(CS10));

    // OCR1A = 65536/2;
    OCR1B = 256;
}

void ultra_high(uint8_t d_c) {
    // Speaker, High Ultrasonic
    // set UNO pin 10/PB2 to output, 62.4kHz, 50% duty cycle
    DDRB |=  _BV(DDB2);

    // TCCR1A [ COM1A1 COM1A0 COM1B1 COM1B0 0 0 WGM11 WGM10  ] = 00100001
    TCCR1A |= (_BV(COM1B1) | _BV(WGM10));

    // TCCR1B [ 1CNC1 1CES1 0 WGM13 WGM12 CS12 CS11 CS10 ]
    TCCR1B |= (_BV(WGM12) | _BV(CS10));

    OCR1B = 127;
}
