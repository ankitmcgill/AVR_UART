//////////////////////////////////////////////
// AVR UART LIBRARY
// FOR ATMEGA8
//
// ONLY IMPLEMENTS THE ASYNCHRONOUS MODE
//
// DECEMBER 26, 2016
//
// ANKIT BHATNAGAR
// ANKIT.BHATNAGARINDIA@GMAIL.COM
//////////////////////////////////////////////

#include "AVR_UART_ATMEGA8.h"

int8_t AVR_UART_Init(uint16_t baud, uint8_t data_size, uint8_t parity, uint8_t stop_bits, uint8_t u2x)
{
	//INTIALIZE UART PERIPHERAL
	//WITH THE SPECIFIED PARAMETERS
	
	//SET BAUDRATE
	uint16_t ubbr_val = (F_CPU / (baud * 16UL)) - 1;
	UBRRH = (uint8_t)(AVR_UART_URSEL_UBRRH | (ubbr_val >> 8)); //set UBRR register
	UBRRL = (uint8_t)ubbr_val;
	
	//SET REMAINING PARAMETERS
	UCSRC |= (AVR_UART_URSEL_UCSRC | parity);
	UCSRC |= (AVR_UART_URSEL_UCSRC | stop_bits);

	//SET U2X IF ENABLED
	UCSRA |= u2x;

	switch(data_size)
	{
		case AVR_UART_DATASIZE_5:	//NOTHING REQUIRED
									break;
		
		case AVR_UART_DATASIZE_6:	
									UCSRC |= (AVR_UART_URSEL_UCSRC | (1 << 1));
									break;
		
		case AVR_UART_DATASIZE_7:	
									UCSRC |= (AVR_UART_URSEL_UCSRC | (1 << 2));
									break;

		case AVR_UART_DATASIZE_8:	
									UCSRC |= (AVR_UART_URSEL_UCSRC | (1 << 2) | (1 << 1));
									break;

		case AVR_UART_DATASIZE_9:	
									UCSRC |= (AVR_UART_URSEL_UCSRC | (1 << 2) | (1 << 1));
									UCSRB |= (1 << 2);
									break;
		default:
									return AVR_UART_ERROR;
	}
	return AVR_UART_OK;
}

int8_t AVR_UART_Enable(void)
{
	//ENABLE (CLOCK TO) UART PERIPHERAL
	//ENABLE BOTH TX AND RX

	UCSRB |= ((1 << 4) | (1 << 3));
	return AVR_UART_OK;
}

int8_t AVR_UART_Disable(void)
{
	//DISBALE (CLOCK TO) UART PERIPHERAL
	//DISABLE BOTH TX AND RX

	UCSRB &= ~((1 << 4) | (1 << 3));
	return AVR_UART_OK;
}

int8_t AVR_UART_Data_Tx(uint8_t data)
{
	//SEND SINGLE BYTE OF DATA THROUGH THE
	//UART PERIPHERAL

	//ENSURE UART TX DATA REGISTER EMPTY
	while((UCSRA & (1 << UDRE)) == 0);
	UDR = data;

	return AVR_UART_OK;
}

int8_t AVR_UART_Data_Tx_Block(uint8_t* data_block, uint8_t size)
{
	//SEND MULTIPLE BYTES OF DATA THROUGH UART PERIPHERAL

	while(size != 0)
	{
		AVR_UART_Data_Tx(*data_block++);
		size--;
	}
	return AVR_UART_OK;
}

int8_t AVR_UART_Data_Rx_Blocking(uint8_t* data)
{
	//RECEIVE SINGLE BYTE OF DATA THROUGH UART PERIPHERAL
	//BLOCKS TILL DATA AVAILABLE

	//WAIT FOR DATA TO BE AVAILABLE
	while((UCSRA & (1 << RXC)) == 0);
	*data = UDR;

	return AVR_UART_OK;
}

int8_t AVR_UART_Data_Rx_Non_Blocking(uint8_t* data)
{
	//RECEIVE SINGLE BYTE OF DATA THROUGH UART PERIPHERAL
	//NON BLOCKING. RETURNS ERROR IF NO DATA AVAILABLE

	//CHECK IF DATA AVAILABLE
	if((UCSRA & (1 << RXC)) != 0)
	{
		*data = UDR;
	}
	else
	{
		return AVR_UART_ERROR;
	}
	return AVR_UART_OK;
}

int8_t AVR_UART_Data_Rx_Block(uint8_t* data_block, uint8_t* size)
{
	//RECEIVE MULTIPLE BYTES OF DATA THROUGH UART PERIPHERAL
	//GET DATA TILL UART SIGNALS RX DATA PRESENT
	//THEN COMPARE THE NUMBER OF BYTES RECEIVED WITH NO OF BYTES
	//REQUESTED AND DEPENDING ON THAT, RETURN OK OR (ERROR + MODIFY
	//SIZE PARAMETER POINTER TO THE NUMBER OF BYTES ACTUALLY READ
	
	uint8_t counter = 0;
	
	while(counter != (*size))
	{
		AVR_UART_Data_Rx_Blocking(data_block);

		//AVR_UART_data_tx(*data_block);

		counter++;
		data_block++;
	}

	//AVR_UART_data_tx('\n');

	return AVR_UART_OK;
}
