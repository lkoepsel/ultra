#include "state0.h"

void state0() {
    digitalWrite(LED_bit0, LOW);
    digitalWrite(LED_bit1, LOW);
    digitalWrite(LED_bit2, LOW);
    uint8_t unpressed = 1;

    while(unpressed) {
        // Up Button
        if (buttons[0].pressed) {
            state = 1;
            unpressed = 0;
        }
        // Down Button
        if (buttons[1].pressed) {
            state = 7;
            unpressed = 0;
        }
    }
    printf("Exiting State 0, state = %d\n", state);
    return;
}	
