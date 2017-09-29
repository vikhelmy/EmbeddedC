/*
 * ex1_BitManipulation.c
 *
 * Created: 9/29/2017 1:52:01 PM
 * Author : MagedHelmy //All Credit to Elliot Willams Chapter 4
 * Hi guys here we will do some bit manipulation where we can switch on and off LEDS by 
 * utilizing our knowledge in OR, XOR, AND, NOT.
 *As a summary, The OR is used to set bits to a specific LED without disturbing the other
 *LEDS, the XOR function is used to toggle a LED on and off without changing the rest of the bits
 *and the AND,NOT function will be used to switch a LED off
 *These functions make our code very efficient.
 *I have used Atmega 160 but this code is compatible with any Embedded C compiler
 */ 

#define F_CPU 1000000UL  // 1 MHz, here we are specifying the CPU frequency to be considered
#include <avr/io.h> //this includes all our DDR and PORT macros
#include <util/delay.h> //help us define actual time values rather than use cycles

#define DELAYTIME 85 //by using the define function, I am trying to make the code more readable, in this case we are simpy defining our time
#define LED_PORT PORTB //Replace PORTB with LED_PORT, so when the code grows I refer to the LED_PORT rather than PORT B, this is omportant especially when there is PORT A,B,C,D og sann, this will make it easy to keep track
#define LED_DDR DDRB //The compiler replaces LED_DDR with DDRB anywhere in the code

//The list below is just to make using the OR,XOR,AND,NOT easier to use.
//Feel free to use them to make the code more readable

//#define BV(bit)               (1 << (bit))
//#define setBit(byte, bit)     (byte |= BV(bit))
//#define clearBit(byte, bit)   (byte &= ~BV(bit))
//#define toggleBit(byte, bit)  (byte ^= BV(bit))

int main(void)
{
		uint8_t i; //here the "u" means unsigned, int is a integer of 8 bit, we are specifying to save memory
		uint8_t repeat;
		uint8_t ledNo;
		uint16_t randomNo = 0x1234; 
		LED_DDR= 0xFF; // Make all LED port into output. it means 0b11111111
		
    while (1) 
    {
		for (i = 0; i < 8; i++) { //the first part of the for loop initializes i, then it sets a test condition, then if the test is true it executes the code, then it comes back and does i++
			LED_PORT |= (1 << i); //This is an OR function, and we setting the value 1 to the ith position
			_delay_ms(DELAYTIME); // This code turns led in order from smalled to biggest.
		}
		
		for (i=0; i< 8; i++ ) {
			LED_PORT &= ~( 1 << i); //here we switch the leds off using the AND,NOT starting from the leastbit first.
			_delay_ms( DELAYTIME);
		}
		
		_delay_ms(5*DELAYTIME); // A brief pause.
		
		for (i=7; i < 255; i--) {
			LED_PORT |= (1 <<i); // We are switching on the ports again but from the lowest bits
			_delay_ms(DELAYTIME);// and the reason we do it from 255 instead of 8 is because of a little trick in the AVR
	//if you use i>0 it will not turn off LED 0 and if you use i>=0, it will go to infinite loop as i is unsigned number and it cannot subtract 1 from 0 making i>=0 always true.
		}
		
		for (i=7; i < 255; i--) {
			LED_PORT &= ~(1 <<i); // We are switching on the ports again
			_delay_ms(DELAYTIME);
		}
		
		_delay_ms(5*DELAYTIME);
	
    
	//Now lets toggle between random bits to excerise
	
	for (repeat=0; repeat < 75; repeat ++) { //do this 75 times
		randomNo = 2053 * randomNo + 13849; // Here we are creating a random number
		
		ledNo = (randomNo >> 8) & 0b00000111; //roll it from the high byte side. the 8th pin
		LED_PORT ^= (1 << ledNo); //toggle the led 
		_delay_ms(DELAYTIME);
		
	}
	
	LED_PORT = 0;
	_delay_ms(5*DELAYTIME);
	
}

return 0;
}

