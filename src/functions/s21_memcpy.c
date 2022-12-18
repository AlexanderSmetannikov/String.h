#include "../s21_string.h"
// #include <stdio.h>

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char* ds = dest;
    const char* source = src;
    for(s21_size_t i = 0; i < n; i++) *ds++ = *source++;
    return dest;
}


// int main() {
//     char s1[10] = "hi";
//     char s2[11];
//     s21_memcpy(s2, s1, 2);
//     printf("string 1: %s \t string 2: %s", s1, s2);
//     return 0;
// }
