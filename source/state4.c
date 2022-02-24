#include "state4.h"

void state4() {
    digitalWrite(LED_bit0, LOW);
    digitalWrite(LED_bit1, LOW);
    digitalWrite(LED_bit2, HIGH);
    uint8_t unpressed = 1;

    while(unpressed) {
        // Up Button
        if (buttons[0].pressed) {
            state = 5;
            unpressed = 0;
        }
        // Down Button
        if (buttons[1].pressed) {
            state = 3;
            unpressed = 0;
        }
    }
    printf("Exiting State 4, state = %d\n", state);
    return;
}	
