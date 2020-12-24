/*
 * SPI_Master.c
 *
 * Created: 12/21/2020 9:17:54 AM
 * Author : Salamony
 */ 

#include "SPI.h"
#include "UART.h"
#define  F_CPU  8000000
#include <util/delay.h>



int main(void)
{
	
	uint8 rec_data = 0 ;
	uint8 read_data_bluetooth = 0 ;
	
	UART_Init();
	SPI_Master_Init();
	SPI_Master_Init_Trans();
	_delay_ms(1000);
	
	DIO_SetPinDir(DIO_PORTD , DIO_PIN4 , DIO_PIN_OUTPUT);
	
	while (1)
	{
		
		read_data_bluetooth = UART_Rx();
		DIO_SetPinVal(DIO_PORTD , DIO_PIN4 , DIO_PIN_HIGH);
		rec_data = SPI_Transiver (read_data_bluetooth);
		
		_delay_ms(1000);
		
	}
}


