AS := aarch64-linux-gnu-as
AR := aarch64-linux-gnu-ar
CC := aarch64-linux-gnu-gcc
LD := aarch64-linux-gnu-gcc
OBJCOPY := aarch64-linux-gnu-objcopy


C_OBJS := \
	arch/arm/arch.o \
	init/main.o \
	kernel/string.o

OBJS := $(ASM_OBJS) $(C_OBJS)

TARGET := kernel

ASFLAGS := -g
CFLAGS := -g -Wall -nostdlib -fno-stack-protector -ffreestanding -Iinclude -fPIC
LDFLAGS := -nostdlib -lgcc -Wl,-Map=$(TARGET).map

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