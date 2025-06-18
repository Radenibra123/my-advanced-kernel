#include "screen.h"
#include "interrupt.h"
#include "memory.h"
#include "task.h"
#include "utility.h"

void task1() {
    static unsigned int count = 0;
    char buffer[40];
    sprintf(buffer, "Task 1: %d", count++);
    puts(buffer, 0, 5, 0x0D); // Magenta
}

void task2() {
    static unsigned int count = 0;
    char buffer[40];
    sprintf(buffer, "Task 2: %d", count++);
    puts(buffer, 40, 5, 0x0E); // Kuning
}

void kernel_main() {
    clear_screen();
    puts("Welcome to My Advanced Kernel!", 0, 0, 0x0A); // Hijau
    puts("Press any key to continue...", 0, 1, 0x09); // Biru

    init_idt();
    init_heap();

    char* buffer = kmalloc(100);
    strcpy(buffer, "Dynamic Memory Allocated!");
    puts(buffer, 0, 4, 0x0B); // Cyan

    add_task(task1);
    add_task(task2);

    while (1) {
        schedule();
    }
}
