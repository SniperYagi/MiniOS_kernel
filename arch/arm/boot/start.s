.section .text.boot
.global _vector_start
.global _vector_end

_vector_start:
    b _reset
    b _abort_handler
    b _swi_handler
    b _abort_handler
    b _abort_handler
    nop
    b _irq_handler
    b _fiq_handler
_vector_end:

.equ FIQ_MODE, 0x11
.equ IRQ_MODE, 0x12
.equ SVC_MODE, 0x13

.global _reset
_reset:
    /* Copy the vector table */
    ldr r0, =0x60000000
    ldr r2, =_vector_start
    ldr r4, =_vector_end

vect_copy:
    ldrlt r6, [r2], #4
    strlt r6, [r0], #4
    cmp r0, r4
    blt vect_copy

    /* Remap vector table */
    ldr r0, =0x60000000
    mcr p15, #0, r0, c12, c0, #0

    /* Save current status program register */
    mrs r0, cpsr

    /* Switch to FIQ mode */
    msr cpsr, FIQ_MODE
    ldr r3, =__fiq_stack_top
    mov sp, r3

    /* Switch to IRQ mode */
    msr cpsr, IRQ_MODE
    ldr r3, =__irq_stack_top
    mov sp, r3

    /* Enable IRQ's and return to supervisor mode */
    bic r0, r0, #0x80
    msr cpsr, r0

    /* Initialize kernel stack space */
    ldr r3, =__stack_top
    mov sp, r3

    /* Start kernel */
    bl entry
    b _abort_handler


.global _abort_handler
_abort_handler:
    swi 0xFF

.global _swi_handler
_swi_handler:
    b .

.global _irq_handler
_irq_handler:
    bl .

.global _fiq_handler
_fiq_handler:
    b .
