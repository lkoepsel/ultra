#include "state3.h"

void state3() {
    digitalWrite(LED_bit0, HIGH);
    digitalWrite(LED_bit1, HIGH);
    uint8_t unpressed = 1;

    while(unpressed) {
        // Up Button
        if (buttons[UP].pressed) {
            state = 0;
            unpressed = 0;
        }
        // Enter Button
        if (buttons[ENTER].pressed) {
            printf("In Enter State 3, state = %d\n", state);

            blue_led(BRIGHT);
            ultra_high(DC_50);

        }
    }
    // Turn off pins and reset Timer 1 each time a new state
    DDRB &= ~_BV(DDB2);
    DDRD &= ~_BV(DDD6);

    TCCR1A = 0;
    TCCR1B = 0;
    OCR1B = 0;
    printf("Exiting State 3, state = %d\n", state);
    return;
}	
