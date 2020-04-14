
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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00 ; PORTC = 0xFF; //INPUT
	DDRD = 0xFF; PORTD = 0x00;
	unsigned char wA = 0x00; // temporaery
	unsigned char wB = 0x00; 
	unsigned char wC = 0x00;  // variable for bit manipulation 
	unsigned char i = 0x00;
	unsigned char x = 0x00;
    /* Insert your solution below */
    while (1) {
	wA = PINA ;
	wB = PINB ;
	wC = PINC ;
	i = wA + wB + wC ;
	
	if(( wA  + wB + wC) >= 0x8C)
		{ x = 0x01;}
	else { x = 0x00;}
	
	if(( (wA - wC > 80) ||(wC - wA > 80)) )
		{ x = x| 0x02;  }

	PORTD = (i & 0xFC)| x;

	
		
    }
	
    return 0;
}
