#include "state0.h"

void state0() {
    digitalWrite(LED_BIT0, LOW);
    digitalWrite(LED_BIT1, LOW);
    uint8_t unpressed = 1;

    while(unpressed) {
        // Up Button
        if (buttons[UP].pressed) {
            state = 1;
            unpressed = 0;
            printf("0: Up, %d\n", state);
        }
        // Enter Button
        if (buttons[ENTER].pressed) {
            state = 0;
            unpressed = 0;
            printf("0: Enter, %d\n", state);
        }
    }
    printf("0: Exit, %d\n", state);
    return;
}	
