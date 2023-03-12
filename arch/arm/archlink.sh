#!/bin/bash


CC="aarch64-linux-gnu-gcc"
LD="$CC"

LINKER="arch/arm/kernel.ld"

echo "  LD kernel.elf"
$LD -T $LINKER arch/arm/kernel.o -o kernel.elf -nostdlib -lgcc -lm