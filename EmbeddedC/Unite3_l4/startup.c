// Startup.c 
// Ziad Osama

#include <stdint.h>
extern int main(void);

void Reset_Handler(void);
void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak,alias ("Default_Handler")));;
void H_fault_Handler(void) __attribute__((weak,alias ("Default_Handler")));;
void MM_fault_Handler(void) __attribute__((weak,alias ("Default_Handler")));;
void Bus_fault(void) __attribute__((weak,alias ("Default_Handler")));;
void Usage_fault_Handler(void) __attribute__((weak,alias ("Default_Handler")));;
// Reserving 1024B using the .bss data section through initializing an array of (256element*4Byte = 1024Bytes)
static unsigned long Stack_top[256];

void(* const GP_fun_Vectors[])() __attribute__((section(".vectors")))=
{
	(void(*)()) ((unsigned long)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler,
	&MM_fault_Handler,
	&Bus_fault,
	&Usage_fault_Handler,
};

extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _E_bss;
extern unsigned int _S_bss;

void Reset_Handler(void){
// This part is  to copy the data memory section from flash to SRAM
	unsigned int DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char *)&_E_text ;
	unsigned char* P_dst = (unsigned char *)&_S_DATA ;
	for (int i = 0; i < DATA_SIZE ; i++)
	{
		*((unsigned char *)P_dst++) = *((unsigned char *)P_src++);
	}
// This part is to initialize .bss section in SRAM at 0
	unsigned int bss_SIZE = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char *)&_S_bss ;
	for (int i = 0; i < bss_SIZE ; i++)
	{
		*((unsigned char *)P_dst++) = (unsigned char)0;
	}	

//Jumping to main()
	main(); 

}
