#include "s21_string.h"
// #include <stdio.h>
// #include <string.h>

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
    const char* s1 = str1;
    const char* s2 = str2;
    int res = 0;
    if (s1 != s21_NULL && s2 != s21_NULL) {
        for (s21_size_t i = 0; i < n && res == 0; i++) {
            if ( *s1 < *s2 ) res--;
            else if (*s1 > *s2) res++;
            s1++;
            s2++; 
        }
    }
    return res;
}

// int main() {
//     char s1[10] = "hi";
//     char s2[10] = "hidsf";
//     int a = memcmp(s1, s2, 4);
//     int b = s21_memcmp(s1, s2, 4);
//     if (b == 0 && a == 0) printf("equal");
//     else if (b > 0 && a > 0) printf("s1 > s2");
//     else if (b < 0 && a < 0) printf("s1 < s2");
//     else printf("diff");
//     return 0;
// }
