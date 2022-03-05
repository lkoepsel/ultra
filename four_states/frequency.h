/* frequency: provides the frequency routines
*	
*/
#ifndef FREQUENCY_H
#define FREQUENCY_H

#include "main.h"

void blue_led(uint8_t intensity);
void sound(uint16_t freq) ;
void ultra_low(uint16_t freq) ;
// void ultra_high(uint16_t duty_cycle) ;
#endif