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


enum States{ Start, s0, s1, s2, s3, s4}state;


void Tick()
{
unsigned char A;
A = PINA ;
switch(state)
{
case Start:
state = s0;
break;

case s0:
if (A == 0x80)
{ state = s1;}
else{ state = s0;}
break;

case s1:
if(A == 0x04)
{ state = s2;}
else {state = s1;}
break;

case s2:
if(A == 0x04)
{ state = s2;}
else if(A == 0x00)
{state = s3;}
else{ state = s0;}
{ state = s1;}
break;

case s3:
if(A == 0x02)
{ state = s4;}
else{ state = s0;}
break;

case s4:
if(A == 0x00)
{ state = s4;}
else{ state = s0;}
break;



default:
state = Start; 
break;



}// transitions

switch(state) {

case s0:
PORTB = 0;
break;

case s1:
PORTB = 1;
break;

case s2:
PORTB = 1;
break;

case s3:
PORTB = 1;
break;

case s4:
PORTB = 0;
break;

default:
break;
}// state actions 


}



int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00;  PORTA = 0xFF;
DDRB = 0x0F;  PORTB = 0x00 ;
state = Start;
 
//unsigned char A0 = PINA;
    /* Insert your solution below */
    while (1) {

Tick();
    }
   return 1;

}
