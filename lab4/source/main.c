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


enum States{ Start, s0, s1, s2, s3} L_state;

void Tick()
{
unsigned char A0;

A0 = PINA & 0x01;

switch(L_state)
{
case Start:
L_state = s0;
break;

case s0:
if(!A0)
{ L_state = s0;}
else if(A0)
{L_state = s1;}
break;

case s1:
if(A0)
{ L_state = s1;}
else if(!A0)
{L_state = s2;}
break;

case s2:
if(!A0)
{ L_state = s2;}
else if(A0)
{L_state = s3;}
break;

case s3:
if(A0)
{ L_state = s3;}
else if(!A0)
{L_state = s1;}
break;

default:
L_state = Start; 
break;



}// transitions

switch(L_state) {

case s0:
PORTB = 0x01;
break;

case s1:
PORTB = 0x02;
break;

case s2:
PORTB = 0x02;
break;

case s3:
PORTB = 0x01;
break;

default:
break;
}// state actions 


}




int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00;  PORTA = 0xFF;
DDRB = 0xFF;  PORTB = 0x00;
L_state = Start;
//unsigned char A0 = PINA;
    /* Insert your solution below */
    while (1) {
Tick();
    }
    return 1;
}
