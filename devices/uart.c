#include <math.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>
#include <devices/uart.h>


static PL011 *uart0 = (PL011 *)UART0_BASE_ADDR;
static const uint32_t refclock = 24000000; /* 24 MHz */


void uart_init(uart_config *cfg) {
    if (cfg->data_bits < 5 || cfg->data_bits > 8) {
        return;
    }

    if (cfg->stop_bits == 0 || cfg->stop_bits > 2) {
        return;
    }

    if (cfg->baud < 110 || cfg->baud > 460800) {
        return;
    }

    /* Disable UART */
    uart0->uartcr &= ~UART_EN;

    /* Finish data transmission */
    while(uart0->uartfr & UART_BUSY);
    uart0->uartlcrh &= ~UART_LCRH_EN;

    /* Initialize baudrate */
    double int_part, fract_part;
    double baud_div = (double)refclock / (16 * cfg->baud);
    fract_part = modf(baud_div, &int_part);

    uart0->uartibrd = (uint16_t)int_part;
    uart0->uartfbrd = (uint8_t)((fract_part * 64) + 0.5);

    uint32_t tmp_lcrh = 0;

    switch(cfg->data_bits) {
        case 5:
            tmp_lcrh |= LCRH_WLEN_5BITS;
            break;
        case 6:
            tmp_lcrh |= LCRH_WLEN_6BITS;
            break;
        case 7:
            tmp_lcrh |= LCRH_WLEN_7BITS;
            break;
        case 8:
            tmp_lcrh |= LCRH_WLEN_8BITS;
            break;
    }

    if (cfg->parity == true) {
        tmp_lcrh |= UART_LCRH_PEN;
        tmp_lcrh |= UART_LCRH_EPS;
        tmp_lcrh |= UART_LCRH_SPS;
    } else {
        tmp_lcrh &= ~UART_LCRH_PEN;
        tmp_lcrh &= ~UART_LCRH_EPS;
        tmp_lcrh &= ~UART_LCRH_SPS;
    }

    if (cfg->stop_bits == 1) {
        tmp_lcrh &= ~UART_LCRH_STP2;
    } else if (cfg->stop_bits == 2) {
        tmp_lcrh |= UART_LCRH_STP2;
    }

    /* Enable FIFO's */
    tmp_lcrh |= UART_LCRH_FEN;
    uart0->uartlcrh = tmp_lcrh;

    /* Enable UART */
    uart0->uartcr |= UART_EN;
}

void uart_putc(char c) {
    while(uart0->uartfr & UART_TXFF);
    uart0->uartdr = c;
}

void uart_puts(char *s) {
    while(*s != '\0') {
        uart_putc(*s);
        s++;
    }
}