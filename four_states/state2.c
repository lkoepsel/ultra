#include "state2.h"

void state2() {
    digitalWrite(LED_bit0, LOW);
    digitalWrite(LED_bit1, HIGH);
    uint8_t unpressed = 1;

    while(unpressed) {
        // Up Button
        if (buttons[UP].pressed) {
            state = 3;
            unpressed = 0;
        }
        // Enter Button
        if (buttons[ENTER].pressed) {
            printf("In Enter State 1, state = %d\n", state);

            // Blue LED Indicator, Medium
            // set UNO pin 6/PD6 to output, 975kHz, 25% duty cycle, MEDIUM
            DDRD |=  _BV(DDD6);
            
            // TCCR0A [ COM0A1 COM0A0 COM0B1 COM0B0 0 0 WGM21 WGM20 ] = 11000010
            TCCR0A |= (_BV(COM0A1) | _BV(WGM21) | _BV(WGM20));

            // TCCR0B [ FOC2A FOC2B 0 0 WGM22 CS22 CS21 CS20 ]
            TCCR0B |=  (_BV(CS21) | _BV(CS20));

            OCR0A = MEDIUM;

            // Speaker, Low Ultrasonic
            // set UNO pin 10/PB2 to output, 32.2kHz, 50% duty cycle
            DDRB |=  _BV(DDB2);
            
            // TCCR1A [ COM1A1 COM1A0 COM1B1 COM1B0 0 0 WGM11 WGM10  ] = 00100001
            TCCR1A |= (_BV(COM1B1) | _BV(WGM11));

            // TCCR1B [ 1CNC1 1CES1 0 WGM13 WGM12 CS12 CS11 CS10 ]
            TCCR1B |= (_BV(WGM12) | _BV(CS10));

            // OCR1A = 65536/2;
            OCR1B = 256;
        }
    }
    // Turn off pins and reset Timer 1 each time a new state
    DDRB &= ~_BV(DDB2);
    DDRD &= ~_BV(DDD6);

    TCCR1A = 0;
    TCCR1B = 0;
    OCR1B = 0;
    printf("Exiting State 2, state = %d\n", state);
    return;
}	
