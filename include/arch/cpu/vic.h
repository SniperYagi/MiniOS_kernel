#ifndef VIC_H
#define VIC_H

#include <stdint.h>


#define VIC_BASE_ADDR (0x10140000)

#define SIC_BASE_ADDR (0x10003000)


#define VIC_INT_SOURCE31 (1 << 31)
#define VIC_INT_SOURCE28 (1 << 28)
#define VIC_INT_SOURCE27 (1 << 27)
#define VIC_INT_SOURCE26 (1 << 26)
#define VIC_INT_SOURCE25 (1 << 25)
#define VIC_INT_SOURCE24 (1 << 24)
#define VIC_INT_SOURCE22 (1 << 22)
#define VIC_INT_SOURCE21 (1 << 21)

#define VIC_MBX         (1 << 19)
#define VIC_PWR_FAIL    (1 << 18)
#define VIC_DMA         (1 << 17)
#define VIC_CLCD        (1 << 16)
#define VIC_SCIO        (1 << 15)
#define VIC_UART2       (1 << 14)
#define VIC_UART1       (1 << 13)
#define VIC_UART0       (1 << 12)
#define VIC_SSP         (1 << 11)
#define VIC_RTC         (1 << 10)
#define VIC_TIMER2_3    (1 << 5)
#define VIC_TIMER1_0    (1 << 4)
#define VIC_SWI         (1 << 2)
#define VIC_WATCHDOG    (1 << 0)



typedef volatile struct __attribute__((packed)) {
    const uint32_t pic_irq_status;
    const uint32_t pic_fiq_status;
    const uint32_t pic_raw_intr;
    uint32_t pic_int_select;
    uint32_t pic_int_enable;
    uint32_t pic_int_en_clear;
    uint32_t pic_soft_int;
    uint32_t pic_soft_int_clear;
    uint32_t pic_protect;
    uint32_t pic_vect_add;
    uint32_t pic_defvect_addr;
    struct {
        uint32_t pic_vect_addr0;
        uint32_t pic_vect_addr1;
        uint32_t pic_vect_addr2;
        uint32_t pic_vect_addr3;
        uint32_t pic_vect_addr4;
        uint32_t pic_vect_addr5;
        uint32_t pic_vect_addr6;
        uint32_t pic_vect_addr7;
        uint32_t pic_vect_addr8;
        uint32_t pic_vect_addr9;
        uint32_t pic_vect_addr10;
        uint32_t pic_vect_addr11;
        uint32_t pic_vect_addr12;
        uint32_t pic_vect_addr13;
        uint32_t pic_vect_addr14;
        uint32_t pic_vect_addr15;
    } pic_vect_addr[60];
    
    struct {
        uint32_t pic_vect_cntl0;
        uint32_t pic_vect_cntl1;
        uint32_t pic_vect_cntl2;
        uint32_t pic_vect_cntl3;
        uint32_t pic_vect_cntl4;
        uint32_t pic_vect_cntl5;
        uint32_t pic_vect_cntl6;
        uint32_t pic_vect_cntl7;
        uint32_t pic_vect_cntl8;
        uint32_t pic_vect_cntl9;
        uint32_t pic_vect_cntl10;
        uint32_t pic_vect_cntl11;
        uint32_t pic_vect_cntl12;
        uint32_t pic_vect_cntl13;
        uint32_t pic_vect_cntl14;
        uint32_t pic_vect_cntl15;
    } pic_vect_cntl[60];
};


#define SIC_USB     (1 << 26)
#define SIC_ETHER   (1 << 25)
#define SIC_AACI    (1 << 24)
#define SIC_MMCIOA  (1 << 22) /* Multi Media Card */
#define SIC_DOC     (1 << 21) /* Disk on Chip */
#define SIC_KEYPAD  (1 << 9)
#define SIC_TCHSCR  (1 << 8)
#define SIC_KMI1    (1 << 4)
#define SIC_KMI0    (1 << 3)
#define SIC_MMCIOB  (1 << 1) /* Multi Media Card */
#define SIC_SOFTINT (1 << 0)

typedef volatile struct __attribute__((packed)) {
    const uint32_t sic_status;
    const uint32_t sic_raw_stat;
    const uint32_t sic_enable;
    uint32_t sic_enset;
    uint32_t sic_enclr;
    uint32_t sic_soft_int_set;
    uint32_t sic_soft_int_clr;
    const uint32_t sic_pic_enable;
    uint32_t sic_picen_set;
    uint32_t sic_picen_clr;
};

#endif