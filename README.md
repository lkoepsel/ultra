# ultra: ultrasonic speaker
## Description
Uses an Arduino Uno, electronic components and a finite state machine (*FSM*) to create a multimodal ultrasonic speaker.

### Microcontroller
Currently uses an Arduino Uno powered by a 1000mAH battery, USB switch and USB cable. A perma-proto board attached to the Uno contains:
* (2) push buttons, UP (Uno 2) and Enter (Uno 4), UP cycles thru states, ENTER enters state
* (3) LEDs with current limiting resistors, Bit0 (Uno 3), Bit1 (Uno 5) and Blue (Uno 6). Bit0/1 indicate state and Blue indicates the indicates the speaker is being driven, and shows by way of intensity, State1 dim, audible frequencies, State2 medium, low ultrasonic random frequencies for a random time and State3 bright, constant 28KHz. 
* (1) low power audio speaker
* tbd audio amplifier circuit, not yet implemented

### Overview
Uses a 4-state FSM to determine which routine to run. The two buttons cycle through the FSM (up or down) and each state drives a particular routine:

* State 0: Null state
* State 1: Audible state, frequencies from  for a random time
* State 2: Low Ultrasonic frequencies from  for a random time
* State 3: Constant ultrasonic frequency of 28KHz


## Software
**clocks**
* clocks - provides all clocks required for ultra, used instead of sysclock
* 
* The three Timer/Counters are used in the following manner:
* T/C 0 - drives BLUE LED, indicates sound (audible/ultra 1/ultra 2)
* T/C 1 - drives speaker sound (audible/ultra 1/ultra 2)
* T/C 2 - is a 1 millisecond timer, millis() and a debounce clock

* sound()
	* Uses T/C 1 to drive speaker sound (audible/ultra 1/ultra 2)
	* Speaker, Audible and ultrasonic Audio
	* frequency based on (freq)
	* PWM_freq = 16000000 / (2 * prescalar * OCR1A) DSpage 137
	* OC1A toggles at PWM_freq, effectively a divide by 2
	* speaker freq = 16x10^6 / (2 * 1 * OCR1A * 2)
	* Example frequencies: OCR1A = 4x10^6/frequency or 4000/(freq in kHz)
	* 5kHz = 800 (or 4000/5)
	* 10kHz = 400
	* 20kHz = 200
	* 28kHz = 143

**main**
Finite State Machine Lock - uses a FSM to cycle through 4 states
* Requires 3 LEDs/resistors to be connected to pins 3/5/6
* Requires 2 push buttons to be connected to pins 2/4 INPUT_PULLUP Mode
* UP increments through states
* ENTER enters the state:

**state0**
Null state, does nothing, provides capability to boot into "safe" state

**state1**
Audible state, random audible freq for random time

**state2**
Ultrasonic state, random audible freq for random time

**state3**
Ultrasonic state, fixed 28KHz freq
