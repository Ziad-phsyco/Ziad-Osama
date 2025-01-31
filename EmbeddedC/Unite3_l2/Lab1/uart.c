#include "uart.h"

#define UART0DR *((volatile unsigned int* const)((unsigned int*)0x101f1000)) 

void UART_SString(unsigned char* PTX_string)
{
	while(*PTX_string != '\0')
	{
		UART0DR = (unsigned int)(*PTX_string);
		PTX_string++;
	}

}
