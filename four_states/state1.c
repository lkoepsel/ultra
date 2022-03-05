#include "state1.h"
#include "frequency.h"

void state1() {
    digitalWrite(LED_bit0, HIGH);
    digitalWrite(LED_bit1, LOW);
    uint8_t unpressed = 1;

    while(unpressed) {
        // Up Button
        if (buttons[UP].pressed) {
            state = 2;
            unpressed = 0;
        }
        // Enter Button
        if (buttons[ENTER].pressed) {
            printf("In Enter State 1, state = %d\n", state);

            blue_led(DIM);
            sound(FREQ_32K);

        }
    }
    // Turn off pins and reset Timer 1 each time a new state
    DDRB &= ~_BV(DDB2);
    DDRD &= ~_BV(DDD6);

    TCCR1A = 0;
    TCCR1B = 0;
    OCR1B = 0;

    printf("Exiting State 1, state = %d\n", state);
    return;
}	
