#include "state1.h"

void state1() 
{
    digitalWrite(LED_BIT0, HIGH);
    digitalWrite(LED_BIT1, LOW);
    bool unpressed = true;

    while(unpressed) 
    {
        // Up Button
        if (buttons[UP].pressed) 
        {
            state = 2;
            unpressed = false;
            printf("1: Up, %d\n", state);
        }
        // Enter Button
        if (buttons[ENTER].pressed) 
        {
            printf("1: Enter, %d\n", state);
            unpressed = true;
            blue_led(DIM);
            while (unpressed) 
            {
                uint16_t rand_freq = random() % 4000;
                uint16_t rand_time = 500 + random() % 2000;
                printf("%u | %u ", rand_freq, rand_time);
                uint16_t pre_millis = millis();
                sound(rand_freq);
                while (unpressed && (millis() - pre_millis < rand_time)) 
                {
                    if (buttons[UP].pressed) 
                    {
                        unpressed = false;
                        printf("UP\n");
                        state = 2;
                    }
                }
            }
        }
    }
    // Turn off pins and reset Timer 1 each time a new state
    off();
    printf("1: Exit, %d\n", state);
    return;
}	
