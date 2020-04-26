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
	DDRA = 0x00;  PORTA = 0xFF;
	DDRC = 0xFF;  PORTC = 0x00;
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	while (1) {
		tempA = ~PINA & 0x0F;
		if (tempA == 0x00)
		{ tempB = 0x00;}
		else if( tempA >= 1 &&  tempA <= 2)
		{ tempB = 0x20;}
		else if( tempA >= 3 &&  tempA <= 4 )
		{ tempB = 0x30;}
		else if( tempA >= 5 &&  tempA <= 6 )
		{ tempB = 0x38;}
		else if( tempA >= 7 &&  tempA <= 9 )
		{ tempB = 0x3C;}
		else if( tempA >= 10&&  tempA <= 12)
		{ tempB = 0x3E;}
		else if( tempA >= 13 &&  tempA <= 15 )
		{ tempB = 0x3F;}
		if( tempA <= 4 && tempA >= 0)
		{ tempB = tempB | 0x40;}
		
		PORTC = tempB;
		

	}
}


