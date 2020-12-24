/*
 * UART.h
 *
 * Created: 12/4/2020 4:33:28 PM
 *  Author: Salamony
 */ 


#ifndef UART_H_
#define UART_H_

#include "ATmega_Registers.h"
#include "BIT_Math.h"

void UART_Init(void);

void UART_Tx(uint8 data);

void UART_TxString(uint8* data);

uint8 UART_Rx(void);





#endif /* UART_H_ */