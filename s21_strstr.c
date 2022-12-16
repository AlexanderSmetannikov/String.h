#include "s21_string.h"
// #include <string.h>
// int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
//     while(n-- && *str1 && (*str1 == *str2)) {
//         str1++;
//         str2++;
//     }
//     return *str1 - *str2;
// }

// s21_size_t s21_strlen(const char *str) {
//     s21_size_t strLength = 0;
//   for (; str[strLength]; strLength++);
//   return strLength;
// }

char *s21_strstr(const char *destptr, const char *srcptr) {
    size_t srcptrLength = s21_strlen(srcptr);
    char *res = s21_NULL;
    for (; *destptr; destptr++) {
        if (strncmp(destptr, srcptr, srcptrLength) == 0) {
            res = (char*)destptr;
            break;
        }
    }
    return res;
}

// int main() {    

//     char str1 [11]="0129456123";
//     char str2 [10]="123";

//     char *istr;
//     char *ssss;

//     istr = strstr(str1,str2);
//     ssss = s21_strstr(str1, str2);

//     printf("%d %d\n", istr - str1 + 1, ssss - str1 + 1);
//     if (istr == ssss) printf("Yes");
//     return 0;
// }
