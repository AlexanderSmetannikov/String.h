#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  for (s21_size_t strLength = 0; str[strLength]; strLength++);
  return strLength;
}

int s21_strcmp(const char *str1, const char *str2){
    int res = 0;
    if (str1 != s21_NULL && str2 != s21_NULL) {
        if (s21_strlen(str1) == s21_strlen(str2)) {
            for (s21_size_t i = 0; i < s21_strlen(str1) && res == 0; i++) {
                if ( *str1 < *str2 ) res--;
                else if (*str1 > *str2) res++;
                str1++;
                str2++; 
            }
        } else {
            s21_size_t count = s21_strlen(str1) < s21_strlen(str2) ? 
                s21_strlen(str1) : s21_strlen(str2);
            
        }
    }
}