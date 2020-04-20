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

unsigned char A0;
   unsigned char A1;
   unsigned char A2; 
   unsigned char A7;   
  
   A0= PINA & 0x01;
   A1= PINA & 0x02;
   A2= PINA & 0x04;
   A7= PINA & 0x80;


switch(state)
{
case Start:
state = s0;
break;

case s0:
if(!A0 && !A1 && !A2)
{ state = s0;}
else if ( !A0 && !A1 && A2)
{ state = s1;}
break;

case s1:
if(!A0 && !A1 && A2)
{ state = s1;}
else if(!A0 && !A1 && !A2)
{state = s2;}
else{ state = s0;}
break;

case s2:
if(!A0 && A1 && !A2)
{ state = s3;}
else 
{ state = s0;}
break;

case s3:
if(A7)
{ state = s4;}
else
 { state = s3;}
break;

case s4:
if(!A7)
{
state = s0;}



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
PORTB = 0;
break;

case s4:
PORTB = 1;
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
