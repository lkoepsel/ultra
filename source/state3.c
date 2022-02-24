#include "state3.h"

void state3() {
    digitalWrite(LED_bit0, HIGH);
    digitalWrite(LED_bit1, HIGH);
    digitalWrite(LED_bit2, LOW);
    uint8_t unpressed = 1;

    while(unpressed) {
        // Up Button
        if (buttons[0].pressed) {
            state = 4;
            unpressed = 0;
        }
        // Down Button
        if (buttons[1].pressed) {
            state = 2;
            unpressed = 0;
        }
    }
    printf("Exiting State 3, state = %d\n", state);
    return;
}	
