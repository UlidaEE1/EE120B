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
DDRD = 0x00;  PORTD = 0xFF;
DDRB = 0x01;  PORTB = 0x01;
DDRC = 0xFF;  PORTC = 0x00;
//unsigned char cnt = 0x00;
unsigned char tempA = 0x00;
unsigned char tempB = 0x00;
//unsigned char tempC = 0x00;
//unsigned char i = 0x00;
    /* Insert your solution below */
    while (1) {

        tempA = PIND; 
	tempB = PINB & 0x01;
	
	if( tempA >= 23 && tempB == 0x00)
		{ PORTB =  0x02;  	}
	if(( tempA >= 0x02 && tempB == 0x01) && ( (tempA <= 23 ))) 
		{ PORTB = 0x03;}

	//PORTC = (PINA & 0x0F) <<4;
	//PORTB = tempB;
	tempA = 0;
        tempB = 0;
	
    }
    return 1;
}
