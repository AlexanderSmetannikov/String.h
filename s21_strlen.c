#include "s21_string.h"
// #include "string.h"
s21_size_t s21_strlen(const char *str) {
  for (s21_size_t strLength = 0; str[strLength]; strLength++);
  return strLength;
}

// int main() {
//     int len1, len2;
//     len1 = s21_strlen("this is a test");
//     len2 = strlen("this is a test");
//     printf ("%d %d", len1, len2);
//     return 0;
// }