#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
    int len = 0;
    while (*dest) {
        dest++;
        len++;
    }
    while(*src && n--) {
        *dest++ = *src++;
        len++;
    }
    *dest = '\0';
    dest -= len; 
    return dest;
}
