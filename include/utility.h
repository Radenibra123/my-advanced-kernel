#ifndef UTILITY_H
#define UTILITY_H

#include <stdarg.h>

int sprintf(char* str, const char* format, ...);
void strcpy(char* dest, const char* src);
int strlen(const char* str);
void itoa(int num, char* buffer, int base);

#endif
