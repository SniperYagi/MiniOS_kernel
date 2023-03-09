AS := arm-none-eabi-as
AR := arm-none-eabi-ar
CC := arm-none-eabi-gcc
LD := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy


ASM_OBJS := \
	arch/arm/boot/start.o

C_OBJS := \
	arch/arm/arch.o \
	devices/uart.o \
	init/main.o

OBJS := $(ASM_OBJS) $(C_OBJS)

TARGET := kernel

ASFLAGS := -mcpu=arm926ej-s -g
CFLAGS := -mcpu=arm926ej-s -g -Wall -nostdlib -fno-stack-protector -ffreestanding -Iinclude
LDFLAGS := -mcpu=arm926ej-s -nostdlib -lgcc -lm -Wl,-Map=$(TARGET).map

.SUFFIXES: .s .c

$(TARGET).elf: $(OBJS)
	@$(LD) -r $^ -o arch/arm/kernel.o $(LDFLAGS)
	@./arch/arm/archlink.sh

.c.o:
	@echo "  CC $<"
	@$(CC) -c $< $(CFLAGS) -o $@

.s.o:
	@echo "  AS $<"
	@$(AS) -g $< $(ASFLAGS) -o $@


clean:
	@rm -f $(OBJS) *.elf *.bin *.map *.txt *.dat
	@rm -f arch/arm/*.o arch/arm/*.a

run:
	@./scripts/boot