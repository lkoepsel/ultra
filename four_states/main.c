#include "main.h"
#include "uart.h"

// All references are to Uno pin numbers
// indicator LEDs and speaker, referenced to Port D
const uint8_t LED_BIT0 = 3;
const uint8_t LED_BIT1 = 5;
const uint8_t LED_BLUE = 6;

// button pins, are referenced to Uno pin numbers, also Port D
const uint8_t UP_PIN = 2;
const uint8_t ENTER_PIN = 4;

// ultrasonic transducer, referenced by Uno pin number
const uint8_t SPEAKER_PIN = 9;  // Note this is Port B, pin 1

// state contains the current state of the FSM
uint8_t state = 0;

/* Main */ 
int main() {

   init_serial();
   pinMode(LED_BIT0, OUTPUT);
   pinMode(LED_BIT1, OUTPUT);

   buttons[UP].uno = UP_PIN;
   pinMode(buttons[UP].uno, INPUT_PULLUP);
   buttons[ENTER].uno = ENTER_PIN;
   pinMode(buttons[ENTER].uno, INPUT_PULLUP);

   init_sysclock_2 ();

    while(1) {
        printf("Switch, %d\n", state);
        switch (state)
        {
             case 0:
             // Power on State
                puts("case0");
                state0();
                break;
             ;
             case 1:
             // Audible State
                puts("case1");
                state1();
                break;
             ;
             case 2:
             // Audible State
                puts("case2");
                state2();
                break;
             ;
             case 3:
             // Audible State
                puts("case3");
                state3();
                break;
             ;
             default:
               puts("Default found");
             ;
        }
    }
    return(0);
}
