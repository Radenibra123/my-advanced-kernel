#include "memory.h"
#include "screen.h"

#define HEAP_SIZE (1024 * 1024) // 1 MB
static char heap[HEAP_SIZE];
static unsigned int heap_pos = 0;

void init_heap() {
    heap_pos = 0;
}

void* kmalloc(unsigned int size) {
    if (heap_pos + size > HEAP_SIZE) {
        puts("Out of Memory!", 0, 2, 0x0C);
        while (1);
    }
    void* ptr = &heap[heap_pos];
    heap_pos += size;
    return ptr;
}
