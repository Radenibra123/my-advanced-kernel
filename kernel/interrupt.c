#include "interrupt.h"
#include "screen.h"

idt_entry_t idt[256];
idtr_t idtr;

void divide_by_zero_handler() {
    clear_screen();
    puts("ERROR: Division by Zero!", 0, 6, 0x0C); // Merah
    while (1); // Hentikan eksekusi
}

void init_idt() {
    for (int i = 0; i < 256; i++) {
        idt[i].low = 0;
        idt[i].selector = 0x08; // Code segment
        idt[i].zero = 0;
        idt[i].flags = 0x8E; // Present + DPL=0 + Interrupt Gate
        idt[i].high = 0;
    }
    unsigned int handler_addr = (unsigned int)divide_by_zero_handler;
    idt[0].low = handler_addr & 0xFFFF;
    idt[0].high = (handler_addr >> 16) & 0xFFFF;
    idt[0].selector = 0x08;
    idt[0].flags = 0x8E;

    idtr.limit = sizeof(idt) - 1;
    idtr.base = (unsigned int)&idt;
    load_idt(&idtr);
}
