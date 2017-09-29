/*******************************************
Project 		Skeleton code to be used as starting point for applications
Target 			ATmega1281 on STK300
Program			Skeleton_1281_C.c
Author			Richard Anthony
Date			14th September 2013

Fuse settings	System clock: Use the internal RC oscillator at 8.0MHz and CKDIV8 fuse programmed, resulting in 1.0MHz system clock.
				Fuse settings should be: CKSEL = "0010", SUT = "10", CKDIV8 = "0"

Function		Performs basic setup - no application logic included
*******************************************/
#include <avr/io.h>
#include <util/delay.h>

void InitialiseGeneral();
unsigned char iterate; //iterate through my function
unsigned int i,j;
unsigned char letters (unsigned char letter)
				{ //from 1 to a according to the wiring of my arduino
						switch(letter)
							{	//afbgc0de 
								case 0:
									return 0b11101011;
									break;
									
								case 1:
									return 0b00101000;
									break;
								case 2:
									return 0b10110011;
									break;
								case 3:
										   //afbgc0de
									return 0b10111010;
									break;
								case 4:
									return 0b01111000;
									break;
								case 5:
										   //afbgc0de
									return 0b11011010;
									break;
								case 6:
										   //afbgc0de
									return 0b11011011;
									break;		
								case 7:
									return 0b10101000;
									break;	
								case 8:
									return 0b11111011;
									break;	
								case 9:
									return 0b11111000;
									break;	
								case 10:
									return 0b11111001;
									break;
									
									default:
										return 0b11111111;
										break;	
				}
				}

void InitialiseGeneral()
{
	// Ports are configured by default to Port B output and Port D input - change as necessary
	DDRB = 0xFF;	// Set port B direction OUTPUT (connected to the on-board LEDs)
	PORTB = 0xFF;	// This is the output of the screen

	DDRD = 0xFF;	// Set port D direction OutPut (connected to the on-board SWITCHs)
	PORTD= 0xFC;    // these are controlling the 4 segment display output
	iterate = 0;
}

int main( void )
{
	InitialiseGeneral();

	
	PORTB = letters(iterate);

	while(1)
	{

                         for(i=0;i<=9;i++)
                                {
                                       iterate=letters[i];
                                for(j=0;j<=9;j++)
                                          {
                                                    iterate=letters[j];
                                                    delay(50);
                                           }
                                  }

}
}

		//PORTD= 0xFE;
		//PORTB = letters(iterate);
		//
		//iterate++;
		//_delay_ms(4000);
//
//if  (iterate == 11) {
			//iterate=0;
		//}
//
		//
		//}
	//}
	//
	//

		
		
		//
		//if(iterate < 10) {
		//iterate++;
		//_delay_ms(5000);
		//
		//}
		//
		//else {
			//iterate=0;
		//}
	//}
//}
