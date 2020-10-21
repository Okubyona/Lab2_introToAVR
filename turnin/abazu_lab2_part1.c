/*	Author: Andrew Bazua [abazu001]
 *  Partner(s) Name:
 *	Lab Section: 024
 *	Assignment: Lab #02 Exercise #01
 *	Exercise Description: [Garage open at night-- A garage door sensor connects
    to PA0 (1 means door open), and a light sensor connects to PA1 (1 means light
    is sensed). Write a program that illuminates an LED connected to PB0 (1 means
    illuminate) if the garage door is open at night.
]
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
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s

	unsigned char door = 0x00; // Temporary variable to hold the value of door state
	unsigned char lightSense = 0x00; // Temporary variable to hold the value of B
	unsigned char nightLight = 0x00; // Temporary variable to hold the value of C

	while(1) {
			// 1) Read input
			door = PINA & 0x01; 			//PA0
			lightSense = PINA & 0x02;	//PA1

			// 2) Perform computation
			//if PA0 == 1 && PA1 == 0, then PB0 == 0x01;
			if (door && lightSense == 0x00) { nightLight = 0x01; }

			else { nightLight = 0x00;}

			//3) Write Output
			PORTB = nightLight;
	}
    return 1;
}
