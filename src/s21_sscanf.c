#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>

#include "s21_string.h"
#define s21_NULL ((void *)0)

#define s21_size_t unsigned long long

// typedef struct flags {
//   int precision;
//   int flags;
//   int width;
//   int length;
//   int sign;
// } flags;

int s21_sscanf(const char *str, const char *format, ...);
int parse_result(char **f_str, char **str, va_list args, int *res);
int parse_string(char **str, va_list args);

int s21_sscanf(const char *str, const char *format, ...) {
    int result = *str ? 0 : -1;
    va_list args;
    va_start(args, format);
    char *s_str = (char*)str;
    char *f_str = (char*)format;
    while (*s_str && *f_str) {
          printf("YES");

    if (*f_str == '%') {
        f_str++;
        if (*f_str != '%') {
            // parse_spec(&f_str);
            result += parse_result(&f_str, &s_str, args, &result);
        } else {
            if (*s_str == '%') {
                s_str++;
                f_str++;
            } else {
                result = -1;
            }
        }
    } else if (*f_str == ' ') {
            while (*f_str == ' ')
                f_str++;
            while (*s_str == ' ')
                s_str++;
        }
    }
    va_end(args);
    return result;
}


int parse_result(char **f_str, char **str, va_list args, int *res) {
  int result = 0;
  while (**str == ' ') {
    // printf("YES");
    (*str)++;
  }
  if (**str) {
     if (**f_str == 'c') {
            result += parse_string(str, args);
          }
  } else {
    *res = -1;
  }
  return result;
}

int parse_string(char **str, va_list args) {
  int result = 0;
  while (**str) {
    char *d = va_arg(args, char *);
    *d = **str;
    (*str)++;
    result++;
  }

  return result;
}

int main() {
    char buf11;
    char buf21;

     char buf12;
    char buf22;

     char buf13;
    char buf23;
    // char b = 'A';
    int res_1 = s21_sscanf("1ds", "%c%c%c", &buf11, &buf12, &buf13);
    int res_1_orig = sscanf("1dsfdsf", "%c%c%c", &buf21, &buf22, &buf23);
    

    printf("res s21 = %d | res_orig = %d\n", res_1, res_1_orig);
    printf("s21_sscanf: %c %c %c\n", buf11, buf12, buf13);
    printf("s_original: %c %c %c\n", buf21, buf22, buf23);
    //strcmp(buf1, buf2) == 0 ? printf("STRINGS ARE EQUAL") : printf("STRINGS ARE DIFFERENT");
    return 0;
}
