#include "s21_string.h"
// #include "string.h"

char *s21_strchr(const char *str, int symbol) {
    int i = 0;
    while (str[i] && str[i] != symbol) i++;
    return symbol == str[i] ? (char*)str + i : NULL;
}

// int main() {
//     char str [11]="dhdhdhhdhdh";
//     int ch = 'h';
//     char *ach;
//     char *ssss;
//     ssss = s21_strchr(str, ch);
//     ach = strchr(str,ch);
//     if (ssss == NULL) {
//         printf("ERROR\n");
//     } else {
//         printf("%d %d", ach, ssss);
//     }
//     return 0;
// }