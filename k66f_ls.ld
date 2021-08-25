ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 2048K
  SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 256K
}

SECTIONS
{
  .text :
  {
    *(.isr_vector)
    *(.flashConfiguration)
    *(.text*)
    *(.rodata*)
    . = ALIGN(4);
    _etext = . ;
  }>FLASH

  .data :
  {
    _sdata = . ;
    *(.data)
    . = ALIGN(4);
    _edata = . ;
  }>SRAM AT>FLASH

  .bss :
  {
    _sbss = . ;
    *(.bss)
    *(COMMON)
    . = ALIGN(4);
    _ebss = . ;
  }> SRAM

}
