/* Entry point for linker script. By default this should be the reset handler */
ENTRY(_reset)

MEMORY
{
    ram     (rwx)   :   ORIGIN = 0x00010000, LENGTH = 128M
}

SECTIONS
{
    .text : {
        __stext = .;
        *(.text*)
        __etext = .;
    } > ram

    .data : {
        __sdata = .;
        *(.data*)

    } > ram

    .rodata : {
        *(.rodata*)
    } > ram

    .bss (NOLOAD) : {
        *(.bss*)
        *(COMMON)
    } > ram

    /* 215KB stack space */
    . = ALIGN(8);
    . = . + 0x350000;
    __stack_top = .;

    . = ALIGN(8);
    . = . + 0x350000;
    __irq_stack_top = .;

    . = ALIGN(8);
    . = . + 0x350000;
    __fiq_stack_top = .;
}