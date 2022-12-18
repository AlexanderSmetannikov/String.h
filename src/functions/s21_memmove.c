#include "../s21_string.h"
// #include <stdio.h>
// #include <string.h>

void* s21_memmove(void* dest, const void* src, s21_size_t n) {
    char* ds = dest;
    const char* source = src;
    if (ds < source) {
        for(s21_size_t i = 0; i < n; i++) *ds++ = *source++;
    } else {
        char* dsend = ds + (n-1);
        const char* sourceend = source + (n-1);
        for(int i = (int)n-1; i >= 0; i--) *dsend-- = *sourceend--;
    }
    return dest;
}

// int main() {
//     char s1[11] = "1234567890";
//     char s2[11] = "1234567890"; 
//     s21_memmove(&s1[4], &s1[3], 3);
//     memmove(&s2[4], &s2[3], 3);
//     printf("string 1: %s\nstring 2: %s", s1, s2);
//     return 0;
// }