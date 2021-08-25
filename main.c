#include <stdint.h>
#include<MK66F18.h>

volatile uint32_t* const SIM_SCGC5 = (uint32_t*) 0x40048038;
volatile uint32_t* const PORTC_PCR9 = (uint32_t*) 0x4004B024;
volatile uint32_t* const GPIOC_PDDR = (uint32_t*) 0x400FF094;
volatile uint32_t* const GPIOC_PSOR = (uint32_t*) 0x400FF0C4;
volatile uint32_t* const GPIOC_PCOR = (uint32_t*) 0x400FF0C8;
volatile uint32_t* const GPIOC_PTOR = (uint32_t*) 0x400FF08C;
volatile uint32_t msTicks = 0;

void SysTick_Handler(void)
{
	msTicks++;
}


int main(void)
{
    uint32_t returnCode;

    returnCode = SysTick_Config(SystemCoreClock /1000);

    // use SIM_SCGC5 register to enable PORTC clock 
    *SIM_SCGC5 |= (1u << 11u); 	

    //use GPIOC_PCR9 to set up the required pin as a GPIO
    uint32_t moder = *PORTC_PCR9;
    moder &= ~(1u << 10u);
    moder &= ~(1u << 9u);
    moder |= (1u << 8u);
    *PORTC_PCR9 = moder;

    // use GPIOC_PDDR regiser to set PTC9 as GPIO output	    
    *GPIOC_PDDR |= (1u << 9u);

    //turn on led
    *GPIOC_PSOR |= (1u << 9u);


    if(returnCode == 0)
    {
	// uses GPIOC_PSOR register to turn on led    
        //*GPIOC_PSOR |= (1u << 9u);
	//DoWait();

	//uses GPIOC_PCOR register to clear the pin
	//*GPIOC_PCOR |= (1u << 9u);
	//DoWait();
	
	//Toggle led  
        *GPIOC_PTOR |= (1u << 9u);
	
    }

    while(1);   
}
