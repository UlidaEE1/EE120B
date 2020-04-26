/*	Author: ulaza001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *    link: https://drive.google.com/open?id=14RYijDy3T0XgaiNpDmyfxJsASNJS5CsM
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

 

enum States{ Start, s0, s1, s2, s3, s4,s5 }state;


void Tick()
{

	unsigned char A0;
	unsigned char A1;

	
	
	A0= ~PINA & 0x01;
	A1= ~PINA & 0x02;


	
	switch(state)
	{
		case Start:
		state = s0;
		break;

		case s0:
		if(!A0 && !A1 )
		{ state = s0;}
		else if ( A0 && !A1 )
		{ state = s1;}
		else if( !A0 && A1)
		{ state = s3;}
		break;

		case s1:
		if(A0 && !A1)
		{ state = s1;}
		else if(!A0)
		{state = s2;}
			if ( A0 && A1)
			{ state = s0;}
		
		break;

		case s2:
		{ state = s5;}
		break;

		case s3:
		if(A1)
		{ state = s3;}
		else if(!A1)
		{ state = s4;}
			
			if ( A0 && A1)
			{ state = s0;}
		break;

		case s4:
		{ state = s5;}
		break;
			
		case s5:
		if ( A0 && A1)
		{ state = s0;}
		else if( A0 && !A1)
		{state = s1;}
		else if (!A0 && A1)
		{ state = s3;}
		break;

		default:
		state = Start;
		break;



	}

	switch(state) {

		case s0:
		PORTC = 0;
		break;

		case s1:
		break;

		case s2:
		if (PORTC <9)
		{
			PORTC = PORTC + 0x01;
		}
		else{ PORTC = PORTC;}
		break;

		case s3:
		break;

		case s4:
		if ( PORTC > 0)
		{
			PORTC = PORTC - 0x01;
		}
		else{ PORTC = PORTC;}
		break;

		case s5:
		PORTC = PORTC;
		break;

		default:
		break;
	}


}



int main(void) {
	
	DDRA = 0x00;  PORTA = 0xFF;
	DDRC = 0xFF;  PORTC = 0x00 ;
	state = Start;
	
	while (1) {

		Tick();
	}
	return 0;

}


