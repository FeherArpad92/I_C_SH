/******************************************************************************
 * Created: 
 * Author :
******************************************************************************/
 /******************************************************************************
* Include files
******************************************************************************/
#include <avr/io.h>

#define F_CPU 8000000UL
#include <avr/delay.h>

#include <inttypes.h>

/******************************************************************************
* Macros
******************************************************************************/


/******************************************************************************
* Constants
******************************************************************************/


/******************************************************************************
* Global Variables
******************************************************************************/
uint8_t counter = 0; 
uint8_t enable_counter = 0;
/******************************************************************************
* External Variables
******************************************************************************/


/******************************************************************************
* Local Function Declarations
******************************************************************************/
void set_pin_direction_on_PORTA(int bit_position, int direction);
void set_pull_up_resisistor_on_PORTA(int bit_position, int state);
void set_voltage_level(int bit_position, int level);
int get_voltage_level_from_PORTA(int bit_position);
/******************************************************************************
* Local Function Definitions
******************************************************************************/
void set_pin_direction_on_PORTA(int bit_position, int direction)
{
	if(direction)
	{
		DDRA = DDRA | (1<<bit_position);
	}
	else
	{
		DDRA = DDRA & (~(1<<bit_position));
	}
}

void set_pull_up_resisistor_on_PORTA(int bit_position, int state)
{
	if(state)
	{
		PORTA = PORTA | (1<<bit_position);
	}
	else
	{
		PORTA = PORTA & (~(1<<bit_position));
	}
}

void set_voltage_level(int bit_position, int level)
{
	if(level)
	{
		PORTA = PORTA | (1<<bit_position);
	}
	else
	{
		PORTA = PORTA & (~(1<<bit_position));
	}
}

int get_voltage_level_from_PORTA(int bit_position)
{
	int voltage_level = 0;
	voltage_level = PINA & (1<<bit_position);
	if(voltage_level != 0) return 1;
	return 0;
}

/******************************************************************************
* Function:         int main(void)
* Description:      main function
* Input:            
* Output:           
* Notes:            
******************************************************************************/
int main(void)
{
	
	//excersises 1-5
	//DDRA = 0b11111111;
	//PORTA = 0xFF;
	
	//DDRB = 0b01111110;
	//PORTB = 0xff;
	
	
	//excersise 6.
	//DDRA = 0b11111111; // all pin set as output in PORTA
	
	//DDRB = 0b11110000; // set high 4 bits to output, set low 4 bits to input
	//PORTB = 0b11111111; // set all pull-up resistors
	
	//excercise 7. 
	set_pin_direction_on_PORTA(1,1);
	//set_voltage_level(0,1);
	
	set_pin_direction_on_PORTA(7,0);
	set_pull_up_resisistor_on_PORTA(7,1);
	
	set_pin_direction_on_PORTA(4,0);
	set_pull_up_resisistor_on_PORTA(4,1);
	
	
	
	
	
	/* Replace with your application code */
	while(1)
	{
		int pa7_state, pa4_state;
		pa7_state = get_voltage_level_from_PORTA(7);
		pa4_state = get_voltage_level_from_PORTA(4);
		
		if(pa7_state || pa4_state)
		{
			set_voltage_level(1,1);
		}
		else
		{
			set_voltage_level(1,0);
		}
		//_delay_ms(500);
		//if((PINB & 0b00000001) == 0)
		//{
		//	enable_counter = 1;
		//}
		
		//if((PINB & 0b00000010) == 0)
		//{
		//	enable_counter = 0;
		//}
		
		//if((PINB & 0b00000100) == 0)
		//{
		//	counter = 0;
		//}
		
		//counter = counter +1;
		//if(enable_counter == 1)
		//{
		//	counter++;
		//}
		
		
		//PORTA = counter;
		
		
		
		
		////excersises 1-5
		//if(PINB == 0b01111110)
		//{
		//	PORTA = PORTA ^ 0xff;
		//}
		//_delay_ms(500);
		
	}
}


/******************************************************************************
* Interrupt Routines
******************************************************************************/








