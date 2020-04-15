/*	Author: ulaza001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
    /* Insert DDR and PORT initializations */
DDRA = 0x00;  PORTA = 0xFF;
DDRB = 0xFF;  PORTB = 0x00;
DDRC = 0xFF;  PORTC = 0x00;
//unsigned char cnt = 0x00;
unsigned char tempA = 0x00;
unsigned char tempB = 0x00;
unsigned char tempC = 0x00;
//unsigned char i = 0x00;
    /* Insert your solution below */
    while (1) {

        tempA = PINA & 0xF0;
	PORTB = tempA >> 4;

	PORTC = (PINA & 0x0F) <<4;
	//PORTB = tempB;
        tempB = 0;
	
    }
    return 1;
}
