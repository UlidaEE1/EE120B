
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
    	 DDRA = 0x00; PORTA = 0xFF ; // INPUT
	DDRC = 0xFF ; PORTC = 0x00; // OUTPUT
	unsigned char tempA = 0x00; // temporaery
	unsigned char tempB = 0x00; 
	unsigned char cnt = 0x00;  // variable for bit manipulation 
	unsigned char i = 0x00;
	unsigned char x = 0x00;
    /* Insert your solution below */
    while (1) {
	tempA = PINA & 0x0F;
	x = tempA;

	if (tempA == 0x0F)
		{PORTC = 0x80;}
	else{
	for ( i = 0x00 ; i < 0x04; i= i + 0x01)
		{
	 

		tempB  = tempA & 0x01;
			if( tempB == 0x00) 
				{ cnt =( cnt + 0x01);}
		tempA =( tempA >> 0x01);
		
		
			 }	
		PORTC = cnt;
		cnt = 0;
    }}
	
    return 0;
}
