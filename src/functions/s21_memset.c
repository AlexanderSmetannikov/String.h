#include "../s21_string.h"
// #include <stdio.h>
// #include <string.h>

void* s21_memset(void* str, int c, s21_size_t n) {
    char* s = str;
    for (s21_size_t i = 0; i < n; i++) *s++ = (char)c;
    return str;
}

// int main() {
//     char s1[11] = "1234567890";
//     char s2[11] = "1234567890"; 
//     s21_memset(s1, '1', 10);
//     memset(s2, '1', 10);
//     printf("string 1: %s\nstring 2: %s", s1, s2);
//     return 0;
// }