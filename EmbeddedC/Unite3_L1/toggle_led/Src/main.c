typedef volatile unsigned int vuint32_t;
#include <stdint.h>

#define RCC_BASE 	0x40021000
#define GPIOA_BASE 	0x40010800
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE +	0x18)
#define GPIOA_CRH	*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR 	*(volatile uint32_t *)(GPIOA_BASE + 0x0C)

#define RCC_IOPAEN 	(1<<2)
#define GPIOA_P13 	(1UL<<13)



typedef union {
		vuint32_t 	all_fields;
		struct {
		vuint32_t 	reserved:13;
		vuint32_t 	P13:1;
		}Pin;
} R_ODR_t;

unsigned char g_var[3] = {1,2,3};
unsigned char const const_var[3] = {1,2,3};



volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);

int main(void){
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH 	&= 0xFF0FFFFF;
	GPIOA_CRH 	|= 0x00200000;
	while(1)
	{
		R_ODR->Pin.P13 = 1;
		for (int i =0; i<5000; i++);
		R_ODR->Pin.P13 = 0;
		for (int i =0; i<5000; i++);
	}
}
