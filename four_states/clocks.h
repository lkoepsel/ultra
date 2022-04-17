/*
* clocks - provides all clocks required for ultra, used instead of sysclock
* 
* The three Timer/Counters are used in the following manner:
* T/C 0 - drives BLUE LED, indicates sound (audible/ultra 1/ultra 2)
* T/C 1 - drives speaker sound (audible/ultra 1/ultra 2)
* T/C 2 - is a 1 millisecond timer, millis() and a debounce clock
*/
#ifndef clocks_h
#define clocks_h

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "main.h"

uint16_t micros();
uint16_t millis();
uint16_t ticks();

void init_sysclock_2 (void);
void init_RESET(void);

void blue_led(uint8_t intensity);
void sound(uint16_t freq) ;
void off();

uint8_t is_RESET_pressed();
uint8_t read_RESET();

#endif
