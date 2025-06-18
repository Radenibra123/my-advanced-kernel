#include "utility.h"

void strcpy(char* dest, const char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int strlen(const char* str) {
    int len = 0;
    while (str[len]) len++;
    return len;
}

void itoa(int num, char* buffer, int base) {
    if (num == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }
    int i = 0;
    while (num > 0) {
        int digit = num % base;
        buffer[i++] = (digit > 9) ? (digit - 10 + 'A') : (digit + '0');
        num /= base;
    }
    buffer[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - 1 - j];
        buffer[i - 1 - j] = temp;
    }
}

int sprintf(char* str, const char* format, ...) {
    va_list args;
    va_start(args, format);
    char* s = str;
    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'd') {
                int num = va_arg(args, int);
                char buffer[12];
                itoa(num, buffer, 10);
                strcpy(s, buffer);
                s += strlen(buffer);
            } else if (*format == 's') {
                char* str_arg = va_arg(args, char*);
                strcpy(s, str_arg);
                s += strlen(str_arg);
            }
        } else {
            *s++ = *format;
        }
        format++;
    }
    *s = '\0';
    va_end(args);
    return s - str;
}
