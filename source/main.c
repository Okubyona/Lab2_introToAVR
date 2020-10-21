/*	Author: Andrew Bazua [abazu001]
 *  Partner(s) Name:
 *	Lab Section: 024
 *	Assignment: Lab #02  Exercise #02
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s

	unsigned char cntAvail = 0x4;
	//unsigned char cntAvail = 0x00;
	unsigned char tmpA = 0x00;

	while(1) {
			// 1) Read input
			tmpA = PINA & 0x0F;

			// 2) Perform computation
			for (unsigned char i = 0; i < 4; ++i) {
				if (tmpA % 2 == 1) { --cntAvail; }
				tmpA >>= 1;
			}

			//3) Write Output
			PORTC = cntAvail;
            cntAvail = 4;
	}
    return 1;
}
