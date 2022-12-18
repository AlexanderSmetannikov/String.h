#include "../s21_string.h"
// #include <string.h>

// char *s21_strchr(const char *str, int symbol) {
//     for (; *str != '\0' && *str != symbol; str++);
//     return symbol == *str ? (char*)str : s21_NULL;
// }

char *s21_strpbrk(const char *str, const char *keys) {
    char *res = s21_NULL;
    for (; *str; str++) {
        if (s21_strchr(keys, *str)){
            res = (char*)str;
            break;
        }
    }
    return res;
}

// char *s21_strpbrk(const char *str, const char *keys) {
//     for (; *str != '\0' && !s21_strchr(keys, *str); str++);
//     if (s21_strchr(keys, *str) != s21_NULL) printf("yes\n");
//     return s21_strchr(keys, *str) != s21_NULL  ? (char*)str : s21_NULL;
// }

// int main() {
//     char str [11]="012345";
//     char ch [10] = "999";
//     char *ach;
//     char *ssss;
//     ssss = s21_strpbrk(str, ch);
//     ach = strpbrk(str,ch);
//     // if (ssss == NULL) {
//     //     printf("ERROR\n");
//     // } else {
//         printf("%d %d", ach, ssss);
//     // }
//     return 0;
// }
