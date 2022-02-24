#include "state6.h"

void state6() {
    digitalWrite(LED_bit0, LOW);
    digitalWrite(LED_bit1, HIGH);
    digitalWrite(LED_bit2, HIGH);
    uint8_t unpressed = 1;

    while(unpressed) {
        // Up Button
        if (buttons[0].pressed) {
            state = 7;
            unpressed = 0;
        }
        // Down Button
        if (buttons[1].pressed) {
            state = 5;
            unpressed = 0;
        }
    }
    printf("Exiting State 6, state = %d\n", state);
    return;
}	
