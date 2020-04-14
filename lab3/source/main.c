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
DDRB = 0x00;  PORTB = 0xFF;
DDRC = 0xFF;  PORTC = 0x00;
unsigned char cnt = 0x00;
unsigned char tempA = 0x00;
unsigned char tempB = 0x00;
unsigned char tempC = 0x00;
unsigned char i = 0x00;
    /* Insert your solution below */
    while (1) {

        tempA = PINA;
       	tempC = PINB;

        for ( i = 0x01 ; i <= 0x08; i= i + 0x01)
                {
                tempB  = tempA & 0x01;
                        if( tempB == 0x01)
                                { cnt =( cnt + 0x01);}
                tempA =( tempA >> 0x01);
		 
         

                tempB  = tempC & 0x01;
                        if( tempB == 0x01)
                                { cnt =( cnt + 0x01);}
                tempC =( tempC >> 0x01);
            }
                         


                PORTC = cnt;
                cnt = 0;

    }
    return 1;
}
