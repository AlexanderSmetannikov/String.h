#include "s21_string.h"
// #include "string.h"

char *s21_strchr(const char *str, int symbol) {
    for (; *str != '\0' && *str != symbol; str++);
    return symbol == *str ? (char*)str : s21_NULL;
}

// int main() {
//     char str [11]="dhdhdhhdhdh";
//     int ch = 'd';
//     char *ach;
//     char *ssss;
//     ssss = s21_strchr(str, ch);
//     ach = strchr(str,ch);
//     // if (ssss == NULL) {
//     //     printf("ERROR\n");
//     // } else {
//         printf("%d %d", ach, ssss);
//     // }
//     return 0;
// }
