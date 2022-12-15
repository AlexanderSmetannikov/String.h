#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  for (s21_size_t strLength = 0; str[strLength]; strLength++);
  return strLength;
}

int s21_strcmp(const char *str1, const char *str2){
    
}