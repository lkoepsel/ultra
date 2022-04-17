#include "state1.h"

void state1() {
    digitalWrite(LED_BIT0, HIGH);
    digitalWrite(LED_BIT1, LOW);
    uint8_t unpressed = 1;

    while(unpressed) {
        // Up Button
        if (buttons[UP].pressed) {
            state = 2;
            unpressed = 0;
            printf("State1: Up pressed, state = %d\n", state);
        }
        // Enter Button
        if (buttons[ENTER].pressed) {
            printf("In Enter State 1, state = %d\n", state);

            blue_led(DIM);
            while (true) {
                uint16_t rand_f = random() % 4000;
                uint16_t rand_t = 500 + random() % 2000;
                printf("%u | %u ", rand_f, rand_t);
                sound(rand_f);
                delay(rand_t);
            }
            printf("\n");
        }
    }
    // Turn off pins and reset Timer 1 each time a new state
    off();
    // DDRB &= ~_BV(DDB2);
    // DDRD &= ~_BV(DDD6);

    // TCCR1A = 0;
    // TCCR1B = 0;
    // OCR1B = 0;

    printf("Exiting State 1, state = %d\n", state);
    return;
}	
