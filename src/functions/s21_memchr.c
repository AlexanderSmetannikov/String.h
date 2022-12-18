#include "../s21_string.h"
// #include <string.h>

void *s21_memchr(const void *str, int symbol, s21_size_t size) {
    const char *ptr = str;
    int res = 0;
    for (s21_size_t n = 0; ptr && res == 0 && n < size; n++) {
        if (ptr[n] == symbol && symbol != '\0') {
            ptr += n;
            res = 1;
        }
    }
	return res ? (void *)ptr : s21_NULL;
}

// int main() {
//     unsigned char src[15]="1234567890";
//     char *sym, *poop;
//     sym = memchr(src, ' ', 10);
//     poop = s21_memchr(src, ' ', 10);
//     if (sym == poop) {
//         printf("Yes");
//     } else {
//         printf("No");
//     }
//     return 0;
// }
