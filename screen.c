#include "screen.h"
#include "utility.h"

static int cursor_x = 0, cursor_y = 0;

void clear_screen() {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            VGA_MEMORY[y * VGA_WIDTH + x] = (VGA_COLOR_DEFAULT << 8) | ' ';
        }
    }
    cursor_x = 0;
    cursor_y = 0;
    set_cursor(0, 0);
}

void putch(char c, int x, int y, char color) {
    if (x >= 0 && x < VGA_WIDTH && y >= 0 && y < VGA_HEIGHT) {
        VGA_MEMORY[y * VGA_WIDTH + x] = (color << 8) | c;
    }
}

void puts(const char* str, int x, int y, char color) {
    for (int i = 0; str[i] != '\0'; i++) {
        putch(str[i], x + i, y, color);
    }
    set_cursor(x + strlen(str), y);
}

void set_cursor(int x, int y) {
    cursor_x = x;
    cursor_y = y;
}
