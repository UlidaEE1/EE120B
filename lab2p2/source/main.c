/*      Author: ulaza001
 *       *  Partner(s) Name:
 *        *      Lab Section:
 *         *      Assignment: Lab #  Exercise #
 *          *      Exercise Description: [optional - include for your own benefit]
 *           *
 *            *      I acknowledge all content contained herein, excluding template or example
 /*             *      code, is my own orginal work.*/
 #include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
   
        DDRA = 0x00; PORTA = 0x0F ; // INPUT
        DDRC = 0xFF ; PORTC = 0x00; // OUTPUT
        unsigned char tempA = 0x00; // temporaery
        unsigned char i = 0x00;  // variable for bit manipulation
	unsigned char cnt = 0x00;
    /* Insert your solution below */
    while (1) {
        tempA = PINA;
	 for(i = 0x00; i <= 4; i++)
		{
		tempA = 
		}
        
        PORTC = cnt;




    }
    return 1;

