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


enum States{ Start, s0, s1, s2, s3} state;


void Tick()
{
unsigned char A;
unsigned char cnt;
A = PINA & 0x03;
switch(state)
{
case Start:
state = s0;
PORTC = 7;
break;

case s0:
if (A== 0x00)
{ state = s0;
PORTC = 0x07;}
else if(A == 0x01)
{ state = s1;
PORTC = 0x07 ; }
else if(A == 0x02 )
{state = s2;}
else if(A == 0x03)
{ state = s3;}
break;

case s1:
if(A == 0x01)
{ state = s1;}
else if(A == 0x02)
{state = s2;}
else if (A == 0x03)
{ state = s3;}
break;

case s2:
if(A == 0x01)
{ state = s1;}
else if(A == 0x02)
{state = s2;}
else if( A == 0x03)
{ state = s3;}
else if ( A == 0x00)
{ state = s0;}
break;

case s3:
if(A == 0x01)
{ state = s1;}
else if(A == 0x02)
{state = s2;}
else if( A == 0x03)
{ state = s3;}
break;

default:
state = Start; 
break;



}// transitions

switch(state) {

case s0:
PORTC = 7;
break;

case s1:
if(PORTC < 9)
{PORTC = PORTC + 1;}
break;

case s2:
if( PORTC > 0)
{
PORTC = --PORTC ;
}
break;

case s3:
PORTC = 0x00;
break;

default:
break;
}// state actions 


}



int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00;  PORTA = 0xFF;
DDRC = 0x0F;  PORTC = 0x00 ;
state = Start;
PORTC = 0; 
//unsigned char A0 = PINA;
    /* Insert your solution below */
    while (1) {

Tick();
    }
   return 0;
}
