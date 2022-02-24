#include "state7.h"

void state7() {
    digitalWrite(LED_bit0, HIGH);
    digitalWrite(LED_bit1, HIGH);
    digitalWrite(LED_bit2, HIGH);
    uint8_t unpressed = 1;

    while(unpressed) {
        // Up Button
        if (buttons[UP].pressed) {
            state = 0;
            unpressed = 0;
        }
        // Enter Button
        if (buttons[ENTER].pressed) {
            state = 6;
            unpressed = 0;
        }
    }
    printf("Exiting State 7, state = %d\n", state);
    return;
}	
