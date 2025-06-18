#ifndef SCREEN_H
#define SCREEN_H

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY ((volatile unsigned short*)0xB8000)
#define VGA_COLOR_DEFAULT 0x0F

void clear_screen();
void putch(char c, int x, int y, char color);
void puts(const char* str, int x, int y, char color);
void set_cursor(int x, int y);

#endif
