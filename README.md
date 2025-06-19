# My Advanced Kernel
A simple educational OS kernel with VGA display, interrupt handling, memory management, and multitasking.

## Features
- Multiboot-compliant bootloader
- VGA text mode display
- Interrupt handling
- Basic memory management
- Round-robin multitasking

## Prerequisites
```bash
sudo apt update
sudo apt install -y build-essential nasm qemu-system-x86 grub-pc-bin grub2-common xorriso git nano
export PATH=$PATH:/mnt/c/i686-elf-tools/bin
