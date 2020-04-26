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

 



 enum States{ Start, s0, s1, s2, s3, s4,s5 }state;


 void Tick()
 {

 unsigned char A0;
 
 
 A0= ~PINA & 0x01;

 
 switch(state)
 {
 case Start:
 state = s0;
 break;

 case s0:
	if(!A0)
	{state = s0;}
	else if(A0)
	{ state = s1;
	PORTB = 0x03;}
 break;

 case s1:
 if(A0)
 {state = s1;}
 else if(!A0)
 { state = s2;}
if(PORTB >= 48)
{state = s0;}
 break;

 case s2:
 if(!A0)
 {state = s2;}
 else if(A0)
 { state = s1;
	PORTB = PORTB << 1;}
 break;
 

	

 default:
 state = Start;
 break;



 }

 switch(state) {

 case s0:
 PORTB = 0x00;
 break;

 case s1:
 PORTB = PORTB;
 break;

 case s2:
 PORTB = PORTB;
 break;



 default:
 break;
 }// state actions


 }



 int main(void) {
 DDRA = 0x00;  PORTA = 0xFF;
 DDRB = 0xFF;  PORTB = 0x00 ;
 
 state = Start;
 
 while (1) {

 Tick();
 }
 return 0;

 }

