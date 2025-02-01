#include "uart.h"

unsigned char string_buffer[100] = "learn-in-depth:ZiadOsama";
unsigned char const string_buffer2[100] = "to creat rodata";

void main()
{
	UART_SString(&string_buffer[0]);
}
