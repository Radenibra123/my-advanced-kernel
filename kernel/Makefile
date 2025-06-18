CC = i686-elf-gcc
AS = nasm
LD = i686-elf-ld
OBJCOPY = i686-elf-objcopy

CFLAGS = -m32 -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -fno-builtin -Iinclude

all: kernel.bin

boot.o: boot.asm
	$(AS) -f elf32 boot.asm -o boot.o

kernel.o: kernel.c include/screen.h include/interrupt.h include/memory.h include/task.h include/utility.h
	$(CC) $(CFLAGS) -c kernel.c -o kernel.o

screen.o: screen.c include/screen.h
	$(CC) $(CFLAGS) -c screen.c -o screen.o

interrupt.o: interrupt.c include/interrupt.h
	$(CC) $(CFLAGS) -c interrupt.c -o interrupt.o

interrupt_asm.o: interrupt.asm
	$(AS) -f elf32 interrupt.asm -o interrupt_asm.o

memory.o: memory.c include/memory.h
	$(CC) $(CFLAGS) -c memory.c -o memory.o

task.o: task.c include/task.h
	$(CC) $(CFLAGS) -c task.c -o task.o

utility.o: utility.c include/utility.h
	$(CC) $(CFLAGS) -c utility.c -o utility.o

kernel.bin: boot.o kernel.o screen.o interrupt.o interrupt_asm.o memory.o task.o utility.o
	$(LD) -m elf_i386 -T linker.ld -o kernel.elf $^
	$(OBJCOPY) -O binary kernel.elf kernel.bin

iso: kernel.bin
	mkdir -p iso/boot/grub
	cp kernel.bin iso/boot/kernel.bin
	echo 'menuentry "My Kernel" { multiboot /boot/kernel.bin }' > iso/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso iso

clean:
	rm -rf *.o *.elf *.bin iso myos.iso

run: iso
	qemu-system-x86_64 -cdrom myos.iso
