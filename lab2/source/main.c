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
	DDRB = 0xFF ; PORTB = 0x00; // OUTPUT
	unsigned char tempA = 0x00; // temporaery 
	unsigned char tempB = 0x00;  // variable for bit manipulation 

    /* Insert your solution below */
    while (1) {
	tempA = PINA;

	if( tempA ==  0x00)
		{
			tempB = 0x00;
		}
	else if( tempA ==  0x01)
                {
                        tempB = 0x01;
                }
	else if( tempA ==  0x02)
                {
                        tempB = 0x00;
                }
	else if( tempA ==  0x03)
                {
                        tempB = 0x00;
                }
	PORTB = tempB;



    }
    return 1;
}
