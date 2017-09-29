// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */

void display( unsigned int oneByte) { //this function takes a single byte and puts it on the portB
	
	PORTB = oneByte;
	_delay_ms(200);
} 

int main(void) {

  
  DDRB |= 0xFF;            /* Data Direction Register B:
                                   writing a one to the bit
                                   enables output. */

  // ------ Event loop ------ //
  while (1) {

    display(0b11111111);
	display(0b00000010);
	display(0b00000100);
	display(0b00001000);
	display(0b00010000);
	display(0b00100100);
	display(0b01010000);
	display(0b10000000);
	
	 //PORTB = 0;
	// _delay_ms(10);
  }                                                  
  return 0;    
  }