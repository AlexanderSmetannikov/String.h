#include "../s21_string.h"
// #include <string.h>
char *s21_strrchr(const char *str, int symbol) {
    int res = -1;
    for (int i = 0; str[i]; i++)
        if (str[i] == symbol) res = i;
    return res == -1 ? s21_NULL : (char*)str + res;
}

// int main() {
//     char str [11]="0663456769";
//     int ch = ' ';
//     char *ach;
//     char *ssss;
//     ssss = s21_strrchr(str, ch);
//     ach = strrchr(str,ch);
//     // if (ssss == NULL) {
//     //     printf("ERROR\n");
//     // } else {
//         printf("%d %d", ach - str + 1, ssss - str + 1);
//     // }
//     return 0;
// }