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

extern unsigned int _stack_top;

uint32_t vectors[] __attribute__((section(".vectors")))= {
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_fault_Handler,
	(uint32_t) &Bus_fault,
	(uint32_t) &Usage_fault_Handler,

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
