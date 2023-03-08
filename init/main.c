#include <stdint.h>
#include <stdbool.h>
#include <devices/uart.h>


int main(void) {
    uart_puts("MiniOS kernel started\n");
    while(1);
}

int entry(void) {
    /* Initialize UART */
    uart_config ucfg = {
        .data_bits = 8,
        .stop_bits = 1,
        .parity = false,
        .baud = 9600
    };
    uart_init(&ucfg);

    while(1);
}