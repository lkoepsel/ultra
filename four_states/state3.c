#include "state3.h"

void state3() 
{
    digitalWrite(LED_BIT0, HIGH);
    digitalWrite(LED_BIT1, HIGH);
    uint8_t unpressed = 1;

    while(unpressed) 
    {
        // Up Button
        if (buttons[UP].pressed) 
        {
            state = 0;
            unpressed = 0;
            printf("3: Up, %d\n", state);
        }
        // Enter Button
        if (buttons[ENTER].pressed) 
        {
            printf("3: Enter, %d\n", state);

            blue_led(BRIGHT);
            // hard-coded to frequency 28K
            sound(143);
        }
    }
    // Turn off pins and reset Timer 1 each time a new state
    off();
    printf("3: Exit, %d\n", state);
    return;
}	
