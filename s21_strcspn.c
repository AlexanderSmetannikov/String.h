#include "s21_string.h"
// #include <string.h>

// char *s21_strchr(const char *str, int symbol) {
//     int i = 0;
//     while (str[i] && str[i] != symbol) i++;
//     return symbol == str[i] ? (char*)str + i : NULL;
// }

s21_size_t s21_strcspn(const char *str, const char *keys) {
    s21_size_t res = 0;
    while(!s21_strchr(keys, *str) && *str != '\0') {
        str++;
        res++;
    }
    return res;
}

// int main() {
//    char str [10]="0123456781";
//    char sym [10]="9";

//    printf ("sigment lenght: %d\n", strcspn(str,sym));
//    printf ("sigment lenght: %d\n", s21_strcspn(str,sym));
//    return 0;
// }
