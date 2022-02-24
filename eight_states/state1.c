#include "state1.h"

void state1() {
    digitalWrite(LED_bit0, HIGH);
    digitalWrite(LED_bit1, LOW);
    digitalWrite(LED_bit2, LOW);
    uint8_t unpressed = 1;

    while(unpressed) {
        // Up Button
        if (buttons[UP].pressed) {
            state = 2;
            unpressed = 0;
        }
        // Enter Button
        if (buttons[ENTER].pressed) {
            state = 0;
            unpressed = 0;
        }
    }
    printf("Exiting State 1, state = %d\n", state);
    return;
}	
