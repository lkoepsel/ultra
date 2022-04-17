#include "state2.h"

void state2() 
{
    digitalWrite(LED_BIT0, LOW);
    digitalWrite(LED_BIT1, HIGH);
    uint8_t unpressed = 1;

    while(unpressed) 
    {
        // Up Button
        if (buttons[UP].pressed) {
            state = 3;
            unpressed = 0;
            printf("2: Up, %d\n", state);
        }
        // Enter Button
        if (buttons[ENTER].pressed) 
        {
            printf("2: Enter, %d\n", state);

            blue_led(MEDIUM);
            while (unpressed) 
            {
                uint16_t rand_freq = random() % 200;
                if (rand_freq >= 80) 
                { 
                    uint16_t pre_millis = millis();
                    uint16_t rand_time = 500 + random() % 2000;
                    printf("%u | %u ", rand_freq, rand_time);
                    sound(rand_freq);
                    while (unpressed && (millis() - pre_millis < rand_time)) 
                    {
                        if (buttons[UP].pressed) 
                        {
                            unpressed = false;
                            printf("UP\n");
                            state = 3;
                        }
                    }
                }
            }
        }
    }
    // Turn off pins and reset Timer 1 each time a new state
    off();
    printf("2: Exit, %d\n", state);
    return;
}	
