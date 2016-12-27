//////////////////////////////////////////////
// AVR UART LIBRARY
// FOR ATMEGAxx8 SERIES
//
// ONLY IMPLEMENTS THE ASYNCHRONOUS MODE
// IN UART0
//
// UART 1 NOT SUPPORTED
//
// NOVEMBER 30, 2016
//
// ANKIT BHATNAGAR
// ANKIT.BHATNAGARINDIA@GMAIL.COM
//////////////////////////////////////////////

#ifndef _AVR_UART_ATMEGA328_H_
#define _AVR_UART_ATMEGA328_H_

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#define AVR_UART_B2400		2400
#define AVR_UART_B4800		4800
#define AVR_UART_B4800		4800
#define AVR_UART_B9600		9600
#define AVR_UART_B115200	115200

#define AVR_UART_OK			0
#define AVR_UART_ERROR		-1

#define AVR_UART_DATASIZE_5	5
#define AVR_UART_DATASIZE_6	6
#define AVR_UART_DATASIZE_7	7
#define AVR_UART_DATASIZE_8	8
#define AVR_UART_DATASIZE_9	9

#define AVR_UART_PARITY_NO		(0)
#define AVR_UART_PARITY_EVEN	(1<<5)
#define AVR_UART_PARITY_ODD		((1<<5)|(1<<4))

#define AVR_UART_STOPBITS_1	(0)
#define AVR_UART_STOPBITS_2	(1<<3)

#define AVR_UART_U2X_OFF	(0)
#define AVR_UART_U2X_ON		(1<<1)

int8_t AVR_UART_Init(uint16_t baud, uint8_t data_size, uint8_t parity, uint8_t stop_bits, uint8_t u2x);

int8_t AVR_UART_Enable(void);
int8_t AVR_UART_Disable(void);

int8_t AVR_UART_Data_Tx(uint8_t data);
int8_t AVR_UART_Data_Tx_Block(uint8_t* data_block, uint8_t size);

int8_t AVR_UART_Data_Rx_Blocking(uint8_t* data);
int8_t AVR_UART_Data_Rx_Non_Blocking(uint8_t* data);
int8_t AVR_UART_Data_Rx_Block(uint8_t* data_block, uint8_t* size);

#endif
