/*
 * BitTwiddling.c
 *
 * Created: 9/29/2017 11:10:03 AM
 * Author : MagedAbdou
 *here will cycle with our code 
 */

#include <avr/io.h> //here we are defining pins, ports, etc
#include <util/delay.h> //function to introduce the delay and time

#define DELAYTIME 85
#define LED_PORT PORTB
#define LED_PIN PINB
#define LED_DDR DDRB


int main(void)
{
    /* Replace with your application code */
	unsigned int i=0; //
	LED_DDR = 0xff; //Here we have set all the data direction register to be output
	
	while (1) {
    while (i<7) 
    {
		LED_PORT=(1 << i); //illuminate only pin number i
		_delay_ms(DELAYTIME);
		i = i + 1; //move to the next LED
    }
	
	while ( i > 0) {
		LED_PORT = ( 1 << i); //illuminate pin i
		_delay_ms(DELAYTIME),
		i = i - 1; //move to the previous LED
	}
}

return (0);
}
