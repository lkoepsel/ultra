/* state1: Audible state, audible frequency through speaker to test system
*	LEDS: LED0: ON LED1: Off Blue: Off on entry, On when ENTER is pressed
* 	Speaker: off on entry, On when ENTER is pressed, audible random frequency 
*/
#ifndef STATE1_H
#define STATE1_H

#include <stdbool.h>
#include "main.h"
#include "clocks.h"

void state1() ;
#endif