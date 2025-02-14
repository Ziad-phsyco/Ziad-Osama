#define SYSCTL_RCGC2_R 		*((volatile unsigned long*)(0x400FE108))
#define GPIO_PORTF_DIR_R 	*((volatile unsigned long*)(0x40025400))
#define GPIO_PORTF_DEN_R	*((volatile unsigned long*)(0x4002551C))
#define GPIO_PORTF_DATA_R	*((volatile unsigned long*)(0x400253FC))

int main()
{
	volatile unsigned long delay_count;
	SYSCTL_RCGC2_R = 0x20;
//delay for the clk to get initialized
	for(delay_count = 0; delay_count<20000 ; delay_count++);
	GPIO_PORTF_DIR_R = 1<<3; //for pin3 the direction is set to be output
	GPIO_PORTF_DEN_R = 1<<3;
	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay_count = 0; delay_count<20000 ; delay_count++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_count = 0; delay_count<20000 ; delay_count++);
	}
	return 0;
}
