#include "clocks.h"
#include "unolib.h"
#include "button.h"
#include <util/atomic.h>
#include <avr/interrupt.h>

volatile uint16_t sys_ctr_2 = 0;
volatile uint8_t bounce_delay = BOUNCE_DIVIDER;
extern button buttons[MAX_BUTTONS];

// ISR for sysclock_2
// Provides millis() counter and clock for debouncing of buttons()
// Number of buttons to check will slightly increase execution time of millis()
ISR (TIMER2_COMPA_vect)      
{

    sys_ctr_2++;

    //  BOUNCE_DIVIDER for millis() or buttons checked too often
    bounce_delay--;
    if (bounce_delay == 0) 
    {
        for (uint8_t i=0; i < MAX_BUTTONS; i++) 
        {
            buttons[i].pressed = is_button_pressed(i);
        }
        bounce_delay = BOUNCE_DIVIDER;
    }
}

uint16_t millis() {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        return(sys_ctr_2);
    }
    return 0;   
}

void blue_led(uint8_t intensity) {

    // Uses T/C 0 to drive BLUE LED, indicates sound being output
    // T/C 0: Fast PWM, Top = 0xFF, PD6, 1/64 prescalar => 976.6Hz
    // Blue LED Indicator, DIM, MED, BRIGHT
    // set blue LED intensity, duty cycle based on (intensity)
    DDRD |=  _BV(LED_BLUE);
    
    // TCCR0A [ COM0A1 COM0A0 COM0B1 COM0B0 0 0 WGM01 WGM00 ] = 11000010
    TCCR0A |= (_BV(COM0A1) | _BV(WGM01) | _BV(WGM00));

    // TCCR0B [ FOC0A FOC0B 0 0 WGM02 CS02 CS01 CS00 ] = 00000011
    TCCR0B |=  (_BV(CS01) | _BV(CS00));

    OCR0A = intensity;
return;
}   

void sound(uint16_t freq) 
    {
        // Uses T/C 1 to drive speaker sound (audible/ultra 1/ultra 2)
        // Speaker, Audible Audio
        // set speaker to output, frequency based on (freq)
        // freq = 16000000 / (2 * prescalar * OCR1A) DSpage 137
        // OC1A toggles at freq, effectively a divide by 2
        // speaker freq = 16x10^6 / (2 * 1 * OCR1A * 2)
        // Example frequencies: OCR1A = 4x10^6/frequency or 4000/freq in kHz
        // 5kHz = 800
        // 10kHz = 400
        // 20kHz = 200
        // 28kHz = 143
        DDRB |=  _BV(SPEAKER_PIN - 8); // Translate Uno pin to Port B
        // PWM, Phase and Frequency Correct, TOP=OCR1A, no prescalar
        // TCCR1A [ COM1A1 COM1A0 COM1B1 COM1B0 0 0 WGM11 WGM10  ] = 00100001
        TCCR1A |= (_BV(COM1A0) | _BV(WGM10));
        // TCCR1B [ 1CNC1 1CES1 0 WGM13 WGM12 CS12 CS11 CS10 ] = 00010001
        TCCR1B |= (_BV(WGM13) | _BV(CS10));

        OCR1A = freq;
    return;
    }	

void init_sysclock_2 (void)          
{
    /* Initialize timer 2
    * TCCR2A [ COM2A1 COM2A0 COM2B1 COM2B0 0 0 WGM21 WGM20 ] = 00000001
    * WGM22 WGM20 => PWM, Phase Correct, TOP = OCRA
    * TCCR2B [ FOC2A FOC2B 0 0 WGM22 CS22 CS21 CS20 ]
    * CS22 CS20 => scalar of 32
    * Frequency = 16 x 10^6 / 32 / 255 = 2000Hz
    * -1 to account for overhead = 254
    * Counter performs another divide by 2 => 1000hz
    * Test using example/millis (delay(1000) = 999 ticks)
    * Manual adjustment to 251, most accurate comparison to delay(1000)
    */
    TCCR2A |= (_BV(WGM20));
    TCCR2B |= ( _BV(WGM22) | _BV(CS21) | _BV(CS20) ) ;
    OCR2A = 251;
    TIMSK2 |= _BV(OCIE2A);
    sei ();
}

void off() 
    {
        // Turn off pins and reset Timer 1 each time a new state
        DDRD &= ~_BV(LED_BLUE);
        DDRB &= ~_BV(SPEAKER_PIN - 8); // Translate Uno pin to Port B

        // TCCR1A = 0;
        // TCCR1B = 0;
        // OCR1B = 0;
    }