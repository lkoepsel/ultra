/* frequency: provides the frequency routines
*	
*/
#ifndef FREQUENCY_H
#define FREQUENCY_H

#include "main.h"

void audible(uint8_t duty_cycle) ;
void ultra_low(uint8_t duty_cycle) ;
void ultra_high(uint8_t duty_cycle) ;
void blue_led(uint8_t intensity);
#endif