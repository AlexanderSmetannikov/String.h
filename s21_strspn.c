#include <stdio.h>
#include <string.h>
int main(void) {
    int len;
    len = strspn("siht is a test", "siht");
    printf ("%d", len);
    return 0;
}

// #include "../s21_string.h"

// s21_size_t s21_strspn(const char *str, const char *keys) {

// }
