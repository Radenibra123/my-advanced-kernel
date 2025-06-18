bits 32
section .multiboot_header
header_start:
    dd 0x1BADB002           ; Magic number Multiboot
    dd 0x00000003           ; Flags (align modules on page boundaries + provide memory info)
    dd -(0x1BADB002 + 0x00000003) ; Checksum
header_end:

section .text
global _start
extern kernel_main
_start:
    mov esp, stack_top      ; Inisialisasi stack
    push ebx                ; Simpan pointer ke struct multiboot
    call kernel_main        ; Panggil kernel_main
    cli                     ; Nonaktifkan interrupt
    hlt                     ; Hentikan CPU

section .bss
    resb 16384             ; Stack size 16 KB
stack_top:
