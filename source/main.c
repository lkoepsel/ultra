#include "main.h"
#include "uart.h"

/* Put your global variables here */
// state contains the current state of the FSM
int state = 0;

int LED_bit0 = 4;
int LED_bit1 = 3;
int LED_bit2 = 2;

// int buttonState0;
// int BUTTON0 = 8;
// int priorState0 = 0;

// int buttonState1;
// int BUTTON1 = 9;
// int priorState1 = 0;

/* Main */ 
int main() {

   init_serial();
   pinMode(LED_bit0, OUTPUT);
   pinMode(LED_bit1, OUTPUT);
   pinMode(LED_bit2, OUTPUT);
   // pinMode(BUTTON0, INPUT_PULLUP);
   // pinMode(BUTTON1, INPUT_PULLUP);

   uint8_t i = 0;
   buttons[i].uno = 8;
   pinMode(buttons[i].uno, INPUT_PULLUP);
   ++i;
   buttons[i].uno = 9;
   pinMode(buttons[i].uno, INPUT_PULLUP);

   init_sysclock_2 ();

// while(1) loop routine runs over and over again forever:
    while(1) {
        /* execution code goes here */
        delay(5);
        // buttonState0 = buttons[0].pressed;
        // buttonState1 = buttons[1].pressed;
        printf("Entering Switch, state = %d\n", state);
        switch (state)
        {
             case 0:
             // Power on State
                puts("state0");
                state0();
                break;
             ;
             case 1:
             // Audible State
                puts("state1");
                state1();
                break;
             ;
             case 2:
             // Audible State
                puts("state2");
                state2();
                break;
             ;
             case 3:
             // Audible State
                puts("state3");
                state3();
                break;
             ;
             case 4:
             // Audible State
                puts("state4");
                state4();
                break;
             ;
             case 5:
             // Audible State
                puts("state5");
                state5();
                break;
             ;
             case 6:
             // Audible State
                puts("state6");
                state6();
                break;
             ;
             case 7:
             // Audible State
                puts("state7");
                state7();
                break;
             ;
             default:
               puts("Default found");
             //C Statements
             ;
        }
    }
    return(0);
}
