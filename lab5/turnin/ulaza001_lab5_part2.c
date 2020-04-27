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


#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { Start, s0, s1, s2, s3 } state;
unsigned char cnt;

 
void Tick()
{
  
   unsigned char A0;
   unsigned char A1;

  
 
   A0= ~PINA & 0x01;
   A1= ~PINA & 0x02;
   
   switch(state) {  //  Transitions
     case Start: // Initial transition
        state = s0;
     
        PORTC= PORTC;
        break;

     case s0:
        if ( !A0 && !A1 ) {
           state = s0;
           
        }
        else if (A0 && !A1 ) {
           state = s1;
           if (PORTC < 9) 
                 ++PORTC;
           PORTC = PORTC;
        }
        else if (A0 && A1) {
           state = s3;
        }
        else   //(A1 && !A0)  
        {
          state = s2;
          if (PORTC > 0)
             --PORTC; 
          PORTC = PORTC;
        }
        break;

     case s1:
       if (A0 && !A1) {
           state = s1;
        }
        else if (!A0 && !A1) {
           state = s0;
        }
        else if (A0 && A1)
        {
           state = s3;
        }
        break;
    
    case s2:
        if (!A0 && A1) {
           state = s2;
        }
        else if (!A0 && !A1) {
           state = s0;
        }
        else if (A1 && A0)
        {
           state = s3;
        }
        break;
    
    case s3:
        if ((A0 && A1) || (!A0 && A1) || (A0 && !A1)) {
           state = s3;
        }
        else if (!A0 && !A1) {
           state = s0;
        }
        break;
    
     default:
        state = Start;
        break;
  }// Transitions

  switch(state) {   // State actions
	 
	 case s0:
	 break; 
	  
	  case s1:
	  break;
	  
	  case s2:
	  break;
	  
     case s3:
        PORTC = 0;
        PORTC = PORTC;
        break;

     default:
        break;
   }// State actions
}

void main() {

   DDRA = 0x00; PORTA = 0xFF;
   DDRC = 0xFF; PORTC = 0x7F;

   PORTC = 0x00;             // Initialize outputs
   state = Start;   // Indicates initial call

   while(1) {
      Tick();
   }
}
