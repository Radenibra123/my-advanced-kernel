#ifndef INTERRUPT_H
#define INTERRUPT_H

typedef struct {
    unsigned short low;
    unsigned short selector;
    unsigned char zero;
    unsigned char flags;
    unsigned short high;
} __attribute__((packed)) idt_entry_t;

typedef struct {
    unsigned short limit;
    unsigned int base;
} __attribute__((packed)) idtr_t;

void init_idt();
void load_idt(idtr_t* idtr);
void divide_by_zero_handler();

#endif
