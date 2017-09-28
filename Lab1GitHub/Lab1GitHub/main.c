#include <avr/io.h>
#include <util/delay.h>

void InitialiseGeneral();
unsigned char uCountvalue;	// Create the variable that will hold the count value

void InitialiseGeneral()
{
	// Configure Ports
	DDRB = 0xFF;		// Set port B direction OUTPUT (connected to the on-board LEDs)
	PORTB = 0xFF;		// Set all LEDs initially off (inverted on the board, so '1' = off)

	uCountvalue  = 0;	// Initialize the count value to 0
}

int main( void )
{
	InitialiseGeneral();

	while(1)
	{
		// Use F9 to place a breakpoint on the line below
		PORTB = ~uCountvalue;	// Write the data value to Port B (the ~ performs 1s compliment
		// because the switch values are inverted in the STK300 board hardware)
		
		uCountvalue++;			// Increment the count value

		// The delay statement below has been commented out because it complicates the debugging process –
		// especially for beginners
		// Note that if running the code without debug mode you should un-comment the statement otherwise
		// the display changes too quickly to see what is happening

		//_delay_ms(500);			// Add a delay so we can see the pattern change
	}
}
