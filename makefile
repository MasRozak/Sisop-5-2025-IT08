CC = gcc
NASM = nasm
LD = ld
DD = dd

CFLAGS = -m16 -nostdlib -ffreestanding -fno-pie
LDFLAGS = -m elf_i386 --oformat binary -Ttext 0x0000
NASMFLAGS = -f elf32

all: build

prepare:
	mkdir -p bin
	$(DD) if=/dev/zero of=bin/floppy.img bs=512 count=2880

bootloader:
	$(NASM) -f bin src/bootloader.asm -o bin/bootloader.bin

stdlib:
	$(CC) $(CFLAGS) -c src/std_lib.c -o bin/std_lib.o

shell:
	$(CC) $(CFLAGS) -c src/shell.c -o bin/shell.o

kernel:
	$(CC) $(CFLAGS) -c src/kernel.c -o bin/kernel.o
	$(NASM) $(NASMFLAGS) src/kernel.asm -o bin/kernel_asm.o

link:
	$(LD) $(LDFLAGS) -o bin/kernel.bin bin/kernel.o bin/kernel_asm.o bin/std_lib.o bin/shell.o
	cat bin/bootloader.bin bin/kernel.bin > bin/floppy.img

build: prepare bootloader stdlib shell kernel link

clean:
	rm -rf bin/*
