#include "../s21_string.h"
// #include <string.h>

s21_size_t s21_strspn(const char *str, const char *keys) {
  size_t n;
  const char* j;
  for(n = 0; *str; str++, n++) {
    for(j = keys; *j && *j != *str; j++);
    if (!*j)
      break;
  }
  return n;
}

// int main(void) {
//     int len, gen;
//     len = strspn("hff siht te sihtst siht ", "siht ");
//     gen = s21_strspn("hff siht te sihtst siht ", "siht ");
//     printf ("%d %d", len, gen);
//     return 0;
// }