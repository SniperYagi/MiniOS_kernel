#!/bin/bash


CC="arm-none-eabi-gcc"
LD="$CC"

LINKER="arch/arm/kernel.ld"


$LD -T $LINKER arch/arm/kernel.o -o kernel.elf -nostdlib -lgcc -lm