//////////////////////////////////////////////
// AVR UART LIBRARY
//
// NOVEMBER 30, 2016
//
// ANKIT BHATNAGAR
// ANKIT.BHATNAGARINDIA@GMAIL.COM
//////////////////////////////////////////////

#include "AVR_UART.h"

int8_t AVR_UART_init(void)
{
	//INTIALIZE UART PERIPHERAL
	//WITH THE SPECIFIED PARAMETERS
}

int8_t AVR_UART_enable(void)
{
	//ENABLE (CLOCK TO) UART PERIPHERAL
}

int8_t AVR_UART_disable(void)
{
	//DISBALE (CLOCK TO) UART PERIPHERAL

}

int8_t AVR_UART_data_send(uint8_t data)
{
	//SEND SINGLE BYTE OF DATA THROUGH THE
	//UART PERIPHERAL

}

int8_t AVR_UART_data_send_block(uint8_t* data_block, uint8_t size)
{
	//SEND MULTIPLE BYTES OF DATA THROUGH UART PERIPHERAL

}

int8_t AVR_UART_data_receive(uint8_t* data)
{
	//RECEIVE SINGLE BYTE OF DATA THROUGH UART PERIPHERAL

}

int8_t AVR_UART_data_receive_block(uint8_t* data_block, uint8_t size)
{
	//RECEIVE MULTIPLE BYTES OF DATA THROUGH UART PERIPHERAL

}
