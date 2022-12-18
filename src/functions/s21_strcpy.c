#include "../s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
    while (*src) *dest++ = *src++;
    return dest;
}
