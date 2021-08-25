#include<stdint.h>
#include<MK66F18.h>
#define SRAM_START 0x20000000U
#define SRAM_SIZE (256 * 1024) //256KB
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

#define STACK_START  SRAM_END

extern void SystemInit(void);
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

//prototype of main
extern int main(void);

void Reset_Handler(void);
void NMI_Handler(void)                          __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)                   __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)                          __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)                       __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)                      __attribute__((weak, alias("Default_Handler")));

void DMA0_DMA16_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA1_DMA17_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA2_DMA18_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA3_DMA19_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA4_DMA20_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA5_DMA21_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA6_DMA22_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA7_DMA23_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA8_DMA24_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA9_DMA25_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA10_DMA26_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void DMA11_DMA27_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void DMA12_DMA28_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void DMA13_DMA29_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void DMA14_DMA30_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void DMA15_DMA31_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void DMA_Error_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));
void MCM_IRQHandler(void)                       __attribute__((weak, alias("Default_Handler")));
void FTFE_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void Read_Collision_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void LVD_LVW_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler")));
void LLWU_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void WDOG_EWM_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler")));
void RNG_IRQHandler(void)                       __attribute__((weak, alias("Default_Handler")));
void I2C0_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void I2C1_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void SPI0_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void I2S0_Tx_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler")));
void I2S0_Rx_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler")));
void Reserved46_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler")));
void UART0_RX_TX_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void UART0_ERR_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));
void UART1_RX_TX_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void UART1_ERR_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));
void UART2_RX_TX_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void UART2_ERR_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));
void UART3_RX_TX_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void UART3_ERR_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));
void ADC0_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void CMP0_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void CMP1_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void FTM0_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void FTM1_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void FTM2_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void CMT_IRQHandler(void)                       __attribute__((weak, alias("Default_Handler")));
void RTC_IRQHandler(void)                       __attribute__((weak, alias("Default_Handler")));
void RTC_Seconds_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void PIT0_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void PIT1_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void PIT2_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void PIT3_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void PDB0_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void USB0_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void USBDCD_IRQHandler(void)                    __attribute__((weak, alias("Default_Handler")));
void Reserved71_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler")));
void DAC0_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler"))); 
void MCG_IRQHandler(void)                       __attribute__((weak, alias("Default_Handler")));
void LPTMR0_IRQHandler(void)                    __attribute__((weak, alias("Default_Handler")));
void PORTA_IRQHandler(void)                     __attribute__((weak, alias("Default_Handler")));
void PORTB_IRQHandler(void)                     __attribute__((weak, alias("Default_Handler")));
void PORTC_IRQHandler(void)                     __attribute__((weak, alias("Default_Handler")));
void PORTD_IRQHandler(void)                     __attribute__((weak, alias("Default_Handler")));
void PORTE_IRQHandler(void)                     __attribute__((weak, alias("Default_Handler")));
void SWI_IRQHandler(void)                       __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void UART4_RX_TX_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void UART4_ERR_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));
void Reserved84_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler")));
void Reserved85_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler")));
void CMP2_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void FTM3_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void DAC1_IRQHandler(void)        	        __attribute__((weak, alias("Default_Handler")));
void ADC1_IRQHandler(void)         	        __attribute__((weak, alias("Default_Handler")));
void I2C2_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));  
void CAN0_ORed_Message_buffer_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void CAN0_Bus_Off_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void CAN0_Error_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void CAN0_Tx_Warning_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void CAN0_Rx_Warning_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void CAN0_Wake_Up_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void SDHC_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void ENET_1588_Timer_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void ENET_Transmit_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void ENET_Receive_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void ENET_Error_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void LPUART0_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler")));
void TSI0_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void TPM1_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void TPM2_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void USBHSDCD_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler")));
void I2C3_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void CMP3_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void USBHS_IRQHandler(void)                     __attribute__((weak, alias("Default_Handler")));
void CAN1_ORed_Message_buffer_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void CAN1_Bus_Off_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void CAN1_Error_IRQHandler(void)                __attribute__((weak, alias("Default_Handler")));
void CAN1_Tx_Warning_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void CAN1_Rx_Warning_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void CAN1_Wake_Up_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));

uint32_t vectors[256] __attribute__((section(".isr_vector"))) = {

	STACK_START,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&HardFault_Handler,
	(uint32_t)&MemManage_Handler,
	(uint32_t)&BusFault_Handler,
	(uint32_t)&UsageFault_Handler,
	0,
	0,
	0,
	0,
	(uint32_t)&SVC_Handler,
	(uint32_t)&DebugMon_Handler,
	0,
	(uint32_t)&PendSV_Handler,
	(uint32_t)&SysTick_Handler, 
	(uint32_t)&DMA0_DMA16_IRQHandler,
	(uint32_t)&DMA1_DMA17_IRQHandler,
	(uint32_t)&DMA2_DMA18_IRQHandler,
	(uint32_t)&DMA3_DMA19_IRQHandler,
	(uint32_t)&DMA4_DMA20_IRQHandler,
	(uint32_t)&DMA5_DMA21_IRQHandler,
	(uint32_t)&DMA6_DMA22_IRQHandler,
	(uint32_t)&DMA7_DMA23_IRQHandler,
	(uint32_t)&DMA8_DMA24_IRQHandler,
	(uint32_t)&DMA9_DMA25_IRQHandler,
	(uint32_t)&DMA10_DMA26_IRQHandler,
	(uint32_t)&DMA11_DMA27_IRQHandler,
	(uint32_t)&DMA12_DMA28_IRQHandler,
	(uint32_t)&DMA13_DMA29_IRQHandler,
	(uint32_t)&DMA14_DMA30_IRQHandler,	
	(uint32_t)&DMA15_DMA31_IRQHandler,
        (uint32_t)&DMA_Error_IRQHandler,	
        (uint32_t)&MCM_IRQHandler,	
        (uint32_t)&MCM_IRQHandler,	
        (uint32_t)&FTFE_IRQHandler,	
        (uint32_t)&Read_Collision_IRQHandler,	
        (uint32_t)&LVD_LVW_IRQHandler,	
        (uint32_t)&LLWU_IRQHandler,	
        (uint32_t)&WDOG_EWM_IRQHandler,	
        (uint32_t)&RNG_IRQHandler,	
        (uint32_t)&I2C0_IRQHandler,	
        (uint32_t)&I2C1_IRQHandler,	
        (uint32_t)&SPI0_IRQHandler,	
        (uint32_t)&SPI1_IRQHandler,	
        (uint32_t)&I2S0_Tx_IRQHandler,	
        (uint32_t)&I2S0_Rx_IRQHandler,	
	0,
        (uint32_t)&UART0_RX_TX_IRQHandler,	
        (uint32_t)&UART0_ERR_IRQHandler,	
        (uint32_t)&UART1_RX_TX_IRQHandler,	
        (uint32_t)&UART1_ERR_IRQHandler,	
        (uint32_t)&UART2_RX_TX_IRQHandler,	
        (uint32_t)&UART2_ERR_IRQHandler,	
        (uint32_t)&UART3_RX_TX_IRQHandler,	
        (uint32_t)&UART3_ERR_IRQHandler,	
        (uint32_t)&ADC0_IRQHandler,	
        (uint32_t)&CMP0_IRQHandler,	
        (uint32_t)&CMP1_IRQHandler,	
        (uint32_t)&FTM0_IRQHandler,	
        (uint32_t)&FTM1_IRQHandler,	
        (uint32_t)&FTM2_IRQHandler,	
        (uint32_t)&CMT_IRQHandler,	
        (uint32_t)&RTC_IRQHandler,	
        (uint32_t)&RTC_Seconds_IRQHandler,	
        (uint32_t)&PIT0_IRQHandler,	
        (uint32_t)&PIT2_IRQHandler,	
        (uint32_t)&PIT3_IRQHandler,	
        (uint32_t)&PDB0_IRQHandler,	
        (uint32_t)&USB0_IRQHandler,	
        (uint32_t)&USBDCD_IRQHandler,	
	0,
        (uint32_t)&DAC0_IRQHandler,	
        (uint32_t)&MCG_IRQHandler,	
        (uint32_t)&LPTMR0_IRQHandler,	
        (uint32_t)&PORTA_IRQHandler,	
        (uint32_t)&PORTB_IRQHandler,	
        (uint32_t)&PORTC_IRQHandler,	
        (uint32_t)&PORTD_IRQHandler,	
        (uint32_t)&PORTE_IRQHandler,	
        (uint32_t)&SWI_IRQHandler,	
        (uint32_t)&SPI2_IRQHandler,	
        (uint32_t)&UART4_RX_TX_IRQHandler,	
        (uint32_t)&UART4_ERR_IRQHandler,	
	0,
	0,
        (uint32_t)&CMP2_IRQHandler,	
        (uint32_t)&FTM3_IRQHandler,	
        (uint32_t)&DAC1_IRQHandler,	
        (uint32_t)&ADC1_IRQHandler,	
        (uint32_t)&I2C2_IRQHandler,	
        (uint32_t)&CAN0_ORed_Message_buffer_IRQHandler,	
        (uint32_t)&CAN0_Bus_Off_IRQHandler,	
        (uint32_t)&CAN0_Error_IRQHandler,	
        (uint32_t)&CAN0_Tx_Warning_IRQHandler,	
        (uint32_t)&CAN0_Rx_Warning_IRQHandler,	
        (uint32_t)&CAN0_Wake_Up_IRQHandler,	
        (uint32_t)&SDHC_IRQHandler,	
        (uint32_t)&ENET_1588_Timer_IRQHandler,	
        (uint32_t)&ENET_Transmit_IRQHandler,	
        (uint32_t)&ENET_Receive_IRQHandler,	
        (uint32_t)&ENET_Error_IRQHandler,	
        (uint32_t)&LPUART0_IRQHandler,	
        (uint32_t)&TSI0_IRQHandler,	
        (uint32_t)&TPM1_IRQHandler,	
        (uint32_t)&TPM2_IRQHandler,	
        (uint32_t)&USBHSDCD_IRQHandler,	
        (uint32_t)&I2C3_IRQHandler,	
        (uint32_t)&CMP3_IRQHandler,	
        (uint32_t)&USBHS_IRQHandler,	
        (uint32_t)&CAN1_ORed_Message_buffer_IRQHandler,	
        (uint32_t)&CAN1_Bus_Off_IRQHandler,	
        (uint32_t)&CAN1_Error_IRQHandler,	
        (uint32_t)&CAN1_Tx_Warning_IRQHandler,	
        (uint32_t)&CAN1_Rx_Warning_IRQHandler,	
        (uint32_t)&CAN1_Wake_Up_IRQHandler,	
};

uint32_t flash_config [4] __attribute((section(".flashConfiguration"))) =
{
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFE
};

void Default_Handler(void)
{
    while(1);
}

void Reset_Handler(void)
{
  //   asm volatile ("cpsid i");	
     SystemInit();
     
    //copy .data section to SRAM
    uint32_t size = &_edata - &_sdata;

    uint8_t *pDst = (uint8_t*)&_sdata; //sram
    uint8_t *pSrc = (uint8_t*)&_etext; //flash

    for(uint32_t i = 0; i < size ; i++)
    {
        *pDst++ = *pSrc++;
    }

     
    //initialise the .bss section to zero in SRAM
    size = &_ebss - &_sbss;
    pDst = (uint8_t*)&_sbss;
	 
    for(uint32_t i = 0; i < size ; i++)
    {
        *pDst++ = 0;
    }
    
    // call init function of standard library
    


//    asm volatile ("cpsie i");
    // call main()
    main();
    

    
} 
