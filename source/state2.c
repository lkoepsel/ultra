#include "state2.h"

void state2() {
    digitalWrite(LED_bit0, LOW);
    digitalWrite(LED_bit1, HIGH);
    digitalWrite(LED_bit2, LOW);
    uint8_t unpressed = 1;

    while(unpressed) {
        // Up Button
        if (buttons[0].pressed) {
            state = 3;
            unpressed = 0;
        }
        // Down Button
        if (buttons[1].pressed) {
            state = 1;
            unpressed = 0;
        }
    }
    printf("Exiting State 2, state = %d\n", state);
    return;
}	
