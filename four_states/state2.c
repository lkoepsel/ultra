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
            printf("In Enter State 2, state = %d\n", state);

            blue_led(MEDIUM);
            sound(FREQ_41K);
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
