AS := arm-none-eabi-as
AR := arm-none-eabi-ar
CC := arm-none-eabi-gcc
LD := arm-none-eabi-gcc


ASM_OBJS := \
	arch/arm/boot/start.o

C_OBJS := \
	arch/arm/arch.o \
	devices/uart.o \
	init/main.o

OBJS := $(ASM_OBJS) $(C_OBJS)

CFLAGS := -g -Wall -nostdlib -fno-stack-protector -ffreestanding -fPIC -Iinclude
LDFLAGS := -nostdlib -lgcc -lm -Wl,-Map=$(TARGET).map

TARGET := kernel


.SUFFIXES: .s .c .o .elf .bin

$(TARGET).elf: $(OBJS)
	@echo "  LD $@"
	@$(LD) -T arch/arm/kernel.ld $^ -o $@ $(LDFLAGS)


.c.o:
	@echo "  CC $<"
	@$(CC) -c $< $(CFLAGS) -o $@

.s.o:
	@echo "  AS $<"
	@$(AS) -g $< -o $@


clean:
	@rm -f $(OBJS) *.elf *.bin *.map *.txt *.dat