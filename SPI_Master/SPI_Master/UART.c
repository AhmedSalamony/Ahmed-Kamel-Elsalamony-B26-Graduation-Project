/*
 * UART.c
 *
 * Created: 12/4/2020 4:33:17 PM
 *  Author: Salamony
 */ 


#include "UART.h"
#include "DIO.h"


#define FREQ 80000
#define Desired_Br 96
void UART_Init(void){
	
	uint32 BR_Value = 0;
	
	//Rx & Tx
	DIO_SetPinDir(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);

	BR_Value = ((FREQ)/(16*Desired_Br))-1;
	
	UBRRL = BR_Value;
	
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
	
	// Register UCSRS BIT 7 , 8 BITS TRANSFER, NO PARITY CHECK, 1 BIT STOP
	UCSRC = 0X86;
}

void UART_Tx(uint8 data){
	UDR = data;
	//check flag if data is transmitted
	while(GET_BIT(UCSRA,5)==0);
}

void UART_TxString(uint8* data){
	//Send string 1 byte at a time because it's transfered into ASCII
	
	uint8 i = 0;
	
	while(data[i] != '\0'){
		UART_Tx(data[i]);
		i++;
	}
	
	
}

uint8 UART_Rx(void){
	
	//when data received check flag 
	while(GET_BIT(UCSRA,7)==0);
	
	return UDR;
}
