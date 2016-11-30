//////////////////////////////////////////////
// AVR UART LIBRARY
//
// NOVEMBER 30, 2016
//
// ANKIT BHATNAGAR
// ANKIT.BHATNAGARINDIA@GMAIL.COM
//////////////////////////////////////////////

#ifndef _AVR_UART_H_
#define _AVR_UART_H_

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

int8_t AVR_UART_init(void);

int8_t AVR_UART_enable(void);
int8_t AVR_UART_disable(void);

int8_t AVR_UART_data_send(uint8_t data);
int8_t AVR_UART_data_send_block(uint8_t* data_block, uint8_t size);

int8_t AVR_UART_data_receive(uint8_t* data);
int8_t AVR_UART_data_receive_block(uint8_t* data_block, uint8_t size);

#endif
