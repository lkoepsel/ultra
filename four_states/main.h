/* Finite State Machine Lock - uses a FSM to act as a binary locking mechanism
Requires 3 LEDs/resistors to be connected to pins 3/5/6
Requires 2 push buttons to be connected to pins 10/11 INPUT_PULLUP Mode
Correct button presses will cycle through FSM
Final correct button press will blink all three LEDs
*/

#ifndef MAIN_H
#define MAIN_H

/* Put your #includes here */
#include <stdio.h>
#include <stdlib.h>

#include "sysclock.h"
#include "button.h"
#include "pinMode.h"
#include "digitalRead.h"
#include "digitalWrite.h"
#include "delay.h"
#include "state0.h"
#include "state1.h"
#include "state2.h"
#include "state3.h"
#include "state4.h"
#include "state5.h"
#include "state6.h"
#include "state7.h"

/* Put your global variables here */
#define UP 0
#define ENTER 1
// state contains the current state of the FSM
extern int state;

extern int LED_bit0;
extern int LED_bit1;
extern int LED_bit2;

extern int buttonState0;
extern int BUTTON0;
extern int priorState0;

extern int buttonState1;
extern int BUTTON1;
extern int priorState1;

extern button buttons[max_buttons];

/* Main */ 
int main();
#endif