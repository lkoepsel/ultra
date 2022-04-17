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
            printf("State2: Up pressed, state = %d\n", state);
        }
        // Enter Button
        if (buttons[ENTER].pressed) 
        {
            printf("In Enter State 2, state = %d\n", state);

            blue_led(MEDIUM);
            while (unpressed) 
            {
                uint16_t rand_freq = random() % 200;
                if (rand_freq >= 80) 
                { 
                    uint16_t rand_time = 500 + random() % 2000;
                    printf("%u | %u ", rand_freq, rand_time);
                    uint16_t pre_millis = millis();
                    sound(rand_freq);
                    while (unpressed && (millis() - pre_millis < rand_time)) 
                    {
                        if (buttons[UP].pressed) 
                        {
                            unpressed = false;
                            printf("UP pressed");
                            state = 3;
                        }
                    }
                }
            }
        }
    }
    // Turn off pins and reset Timer 1 each time a new state
    off();
    // DDRB &= ~_BV(DDB2);
    // DDRD &= ~_BV(DDD6);

    // TCCR1A = 0;
    // TCCR1B = 0;
    // OCR1B = 0;
    printf("Exiting State 2, state = %d\n", state);
    return;
}	
