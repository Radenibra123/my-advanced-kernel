global load_idt
load_idt:
    mov eax, [esp+4]    ; Ambil parameter idtr pointer
    lidt [eax]          ; Load IDT
    sti                 ; Aktifkan interrupt
    ret
