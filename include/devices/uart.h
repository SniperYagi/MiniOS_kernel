#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stdbool.h>

#define UART0_BASE_ADDR (0x101f1000)
#define UART1_BASE_ADDR (0x101f2000)
#define UART2_BASE_ADDR (0x101f3000)

#define UART_RI     (1 << 8)
#define UART_TXFE   (1 << 7)
#define UART_RXFF   (1 << 6)
#define UART_TXFF   (1 << 5)
#define UART_RXFE   (1 << 4)
#define UART_BUSY   (1 << 3)
#define UART_DCD    (1 << 2)
#define UART_DSR    (1 << 1)
#define UART_CTS    (1 << 0)

#define UART_EN     (1 << 0)
#define UART_CTSEN  (1 << 15)
#define UART_RTSEN  (1 << 14)
#define UART_OUT2   (1 << 13)
#define UART_OUT1   (1 << 12)
#define UART_RTS    (1 << 11)
#define UART_DTR    (1 << 10)
#define UART_RXE    (1 << 9)
#define UART_TXE    (1 << 8)
#define UART_LBE    (1 << 7)

#define UART_LCRH_EN    (1 << 4)
#define UART_LCRH_SPS   (1 << 7)
#define UART_LCRH_FEN   (1 << 4)
#define UART_LCRH_STP2  (1 << 3)
#define UART_LCRH_EPS   (1 << 2)
#define UART_LCRH_PEN   (1 << 1)
#define UART_LCRH_ERK   (1 << 0)
#define LCRH_WLEN_5BITS (0 << 5)
#define LCRH_WLEN_6BITS (1 << 5)
#define LCRH_WLEN_7BITS (2 << 5)
#define LCRH_WLEN_8BITS (3 << 5)

#define UART_ILPR   (1 << 7)
#define UART_IBRD   (1 << 15)
#define UART_FBRD   (1 << 5)


typedef volatile struct __attribute__((packed)) {  
    uint32_t uartdr;                 /* UART_BASE_ADDR + 0x000 */
    uint32_t uartsrcr;               /* UART_BASE_ADDR + 0x004 */
    const uint32_t _reserved0[12];   /* UART_BASE_ADDR + 0x008-0x014 */
    const uint32_t uartfr;           /* UART_BASE_ADDR + 0x018 */
    const uint32_t _reserved1;       /* UART_BASE_ADDR + 0x01C */
    uint32_t uartilpr;               /* UART_BASE_ADDR + 0x020 */
    uint32_t uartibrd;               /* UART_BASE_ADDR + 0x024 */
    uint32_t uartfbrd;               /* UART_BASE_ADDR + 0x028 */
    uint32_t uartlcrh;               /* UART_BASE_ADDR + 0x02C */
    uint32_t uartcr;                 /* UART_BASE_ADDR + 0x030 */
    uint32_t uartifls;               /* UART_BASE_ADDR + 0x034 */
    uint32_t uartimsc;               /* UART_BASE_ADDR + 0x038 */
    const uint32_t uartris;          /* UART_BASE_ADDR + 0x03C */
    const uint32_t uartmis;          /* UART_BASE_ADDR + 0x040 */
    uint32_t uarticr;                /* UART_BASE_ADDR + 0x044 */
    uint32_t uartmacr;               /* UART_BASE_ADDR + 0x048 */
    const uint32_t _reserved2[48];   /* UART_BASE_ADDR + 0x04C-0x07C */
    const uint32_t _reserved3[12];   /* UART_BASE_ADDR + 0x080-0x08C */
    const uint32_t _reserved4[3900]; /* UART_BASE_ADDR + 0x090-0xFCC */
    const uint32_t _reserved5[12];   /* UART_BASE_ADDR + 0xFD0-0xFDC */
    const uint32_t uart_periph_id0;  /* UART_BASE_ADDR + 0xFE0 */
    const uint32_t _reserved6[8];    /* UART_BASE_ADDR + 0xFE4-0xFEC (Unused for now) */
    const uint32_t uart_pcell_id0;   /* UART_BASE_ADDR + 0xFF0 */
    const uint32_t _reserved7[8];    /* UART_BASE_ADDR + 0xFF4-0xFFC (Unused for now) */
} PL011;

typedef struct {
    uint8_t  data_bits;
    uint8_t  stop_bits;
    bool     parity;
    uint32_t baud;
} uart_config;

typedef enum {
    UART_INVAL_DATA_BITS = -1,
    UART_INVAL_STOP_BITS,
    UART_INVAL_PARITY,
    UART_INVAL_BAUD,
} uart_error;


void uart_init(uart_config *cfg);
void uart_putc(char c);
void uart_puts(char *s);

#endif