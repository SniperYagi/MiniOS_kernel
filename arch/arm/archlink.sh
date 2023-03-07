#!/bin/bash

#
# arch/arm/archlink.sh - Kernel linker tool
#

# Get the target kernel name passed by the Makefile
KERNEL_TARGET="$1"
KERNEL_LINKER="arch/arm/kernel.ld"
KERNEL_LDFLAGS="-nostdlib -lgcc -lm"

KERNEL_PARTIAL="arch/arm/kernel_partial.o"
KERNEL_FINAL="kernel.elf"
KERNEL_BINARY="kernel.bin"

CC="arm-none-eabi-gcc"
LD="$CC"
OBJCOPY="arm-none-eabi-objcopy"



$LD -T $KERNEL_LINKER $KERNEL_PARTIAL -o $KERNEL_FINAL $KERNEL_LDFLAGS

# Don't create binary copy. VersatilePB board only supports ELF loading in QEMU when passing -kernel option
#$OBJCOPY -Obinary $KERNEL_FINAL $KERNEL_BINARY