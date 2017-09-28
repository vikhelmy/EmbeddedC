#include <avr/io.h>
#include <util/delay.h>

void InitialiseGeneral();
unsigned char uCountvalue;	// Create the variable that will hold the count value

void InitialiseGeneral()
{
	// Configure Ports
	DDRB = 0xFF;		// Set port B direction OUTPUT (connected to the on-board LEDs)
	PORTB = 0xFF;		// Set all LEDs initially off (inverted on the board, so '1' = off)

	DDRD = 0x00; //It is now input
	PORTD = 0xFF; //Pull up the buttom
	uCountvalue  = 1;	// Initialize the count value to 0
}

int main( void )
{
	InitialiseGeneral();

	while(1)
	{
		// Use F9 to place a breakpoint on the line below
		PORTB = uCountvalue;	// Write the data value to Port B (the ~ performs 1s compliment
		// because the switch values are inverted in the STK300 board hardware)
		
		//uCountvalue++;			// Increment the count value
		//uCountvalue--; // Decrement the count value
		
		if(!(PIND & (1<<PD0))) {
			if( uCountvalue<9 ) 
			{
				uCountvalue = uCountvalue<<1;
				_delay_ms(2000);
			}
		
		
			else {
			
				uCountvalue=1;
			}
		}
		else 
			{
				if(uCountvalue>0 ) 
					{
					
					uCountvalue = uCountvalue>>1;
					_delay_ms(2000);
				}
				
				else {
					
					uCountvalue=8;
				}
			}
		
		
		
		

		
	
		// The delay statement below has been commented out because it complicates the debugging process –
		// especially for beginners
		// Note that if running the code without debug mode you should un-comment the statement otherwise
		// the display changes too quickly to see what is happening

					// Add a delay so we can see the pattern change
	}
}
