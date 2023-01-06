#include "s21_sprintf.h"

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "./src/s21_string.h"

#define N_DECIMAL_POINTS_PRECISION (1000000)

typedef long long ll;

typedef struct Token {
  int width;
  int length;
  char sign;
} Token;

// s21_size_t s21_strlen(const char* str) {
//   s21_size_t strLength = 0;
//   for (; str[strLength]; strLength++)
//     ;
//   return strLength;
// }

// int flag_implementation(char* buf, Token* tok) {
//   int res = 0;
  
//   return res;
// }

int s21_getchar(const char* str, char* c) {
  int result  = *str ? 1 : 0;
  *c = *str;
  return result;
}

// int s21_putnumber(char* buf, ll num, Token* tok) {
//   int res = 0;
//   if (tok->sign) num *= -1;
//   res += flag_implementation(buf, tok);
//   ll div = 1;
//   while (num / div != 0) div *= 10;
//   div /= 10;
//   ll ostatok = 0;
//   while (num % div >= 0) {
//     ostatok = num / div;
//     res += s21_putchar(buf, (char)('0' + ostatok));
//     num = num % div;
//     div /= 10;
//     if (div == 0) break;
//   }
//   return res;
// }

int is_spec(char c) {
  return (c == 'c' || c == 'd' || c == 'i' || c == 'f' || c == 's' ||
          c == 'u' || c == '%' || c == 'G' || c == 'g' || c == 'o' || c == 'x' ||
          c = 'X' || c == 'p' || c == 'n' || c == 'e' || c == 'E');
}

int token_config(char** fmt, Token* tk, va_list* args) {
  int res = 0;
  int len = 0;
  while (**fmt) {
    if (**fmt == '*') { 
      tk -> width = 
    }
    if (is_digit(*fmt)) {
      tk->width = s21_stoi(fmt);
      res += numLength(tk->width);
    }
    if (**fmt == '%') {
      res = 0;
      break;
    }
    if (is_spec(**fmt)) {
      (*fmt)--;
      break;
    }
    (*fmt)++;
  }
  return res;
}

int s21_getstring(const char* str, char* string) {
  int res  = *str ? 1 : 0;
  while (*str) {
    s21_getchar(str, string);
    string++;
    str++;
  }
  return res;
}

// int s21_putfloat(char* buf, double num, Token* tok) {
//   int res = 0;
//   ll pr =
//       tok->precision > 0 ? pow(10, tok->precision) : N_DECIMAL_POINTS_PRECISION;
//   int integerPart = (int)num;
//   ll decimalPart = ((ll)(num * pr) % pr);
//   res += s21_putnumber(buf, integerPart, tok);
//   if (tok->precision >= 0 && decimalPart) {
//     res += s21_putchar(buf, '.');
//     res += s21_putnumber(buf, decimalPart, tok);
//   }
//   return res;
// }

// int s21_stoi(const char* str) {
//   int res = 0;
//   while (*str >= '0' && *str <= '9') {
//     res *= 10;
//     res += (*str - '0');
//     str++;
//   }
//   return res;
// }

// int numLength(int num) {
//   int res = 1;
//   while (num / 10 > 0) {
//     res++;
//     num /= 10;
//   }
//   return res;
// }

// int is_digit(char c) { return (c >= '0' && c <= '9'); }

// int is_spec(char c) {
//   return (c == 'c' || c == 'd' || c == 'i' || c == 'f' || c == 's' ||
//           c == 'u' || c == '%');
// }

// int is_special_symbols(char c) {
//   return (c == '\\' || c == '\a' || c == '\b' || c == '\f' || c == '\n' ||
//           c == '\r' || c == '\t' || c == '\v');
// }

// int spec_config(const char* fmt, Token* tok) {
//   int res = 0;
//   int len = 0;
//   while (*fmt) {
//     if (*fmt == '+') {
//       tok->flag |= flag_plus;
//       res++;
//     }
//     if (*fmt == '-') {
//       tok->flag |= flag_minus;
//       res++;
//     }
//     if (*fmt == ' ') {
//       tok->flag |= flag_space;
//       res++;
//     }
//     if (is_digit(*fmt)) {
//       tok->width = s21_stoi(fmt);
//       res += numLength(tok->width);
//     }
//     if (*fmt == '.') {
//       fmt++;
//       res++;
//       if (is_digit(*fmt)) {
//         tok->precision = s21_stoi(fmt);
//         len = numLength(tok->precision);
//         res += len;
//         fmt += len - 1;
//       } else
//         tok->precision = 0;
//     }
//     if (*fmt == '%') {
//       res = 0;
//       break;
//     }
//     if (is_spec(*fmt)) {
//       fmt--;
//       break;
//     }
//     fmt++;
//   }
//   return res;
// }

void reset_specs(Token* tok) {
  tok->width = 0;
  tok->length = 0;
  tok->sign = 0;
}

int s21_sscanf(const char* str, const char* format, ...) {
  Token tok = {0};
  char *data = (char*)str,
      *fmt = (char*)format;
  va_list args;
  va_start(args, fmt);
  int res = *str ? 0 : -1;

  while (*fmt) {
    if (!*str) break;
    if (*fmt == '%') {
      fmt++;
      if (*fmt == 'c') {
        res += s21_getchar(data, (char*)va_arg(args, char*));
        str++;
      }
    }
      if (*fmt == 's') {
        char* string = va_arg(args, char*);
        res += s21_getstring(data, string);
        break;
      }
      // if (*fmt == 'd') {
      //   int* num = va_arg(args, int*);
      //   // if (num < 0) tok.sign = -1;
      //   res += s21_getnumber(str, num, &tok);
      // }
      // if (*fmt == 'i') {
      //   int* num = va_arg(args, int*);
      //   // if (num < 0) tok.sign = -1;
      //   res += s21_getnumber(str, num, &tok);
      // }
    //   if (*fmt == 'u') {
    //     ll num = va_arg(args, unsigned int);
    //     if (num < 0) tok.sign = -1;
    //     res += s21_putnumber(buf, num, &tok);
    //   }
    //   if (*fmt == 'f') {
    //     double num = va_arg(args, double);
    //     if (num < 0) tok.sign = -1;
    //     res += s21_putfloat(buf, num, &tok);
    //   }
    //   if (*fmt == '%') {
    //     res += s21_putchar(buf, *fmt);
    //   }
    // } else
    //   res += s21_putchar(buf, *fmt);
    fmt++;
  }
  va_end(args);
  return res;
}

int main() {
      
      char buf11[80];
    char buf21[80];

      char buf12;
    char buf22;

      char buf13;
    char buf23;

    int res_1 = s21_sscanf("f 234", "%s%c%c", buf11, &buf12, &buf13);
    int res_1_orig = sscanf("fdgdgdg234", "%3s%c%c", buf21, &buf22, &buf23);
    

    printf("res s21 = %d | res_orig = %d\n", res_1, res_1_orig);
    printf("s21_sscanf: %s %c %c\n", buf11, buf12, buf13);
    printf("ori_sscanf: %s %c%c\n", buf21, buf22, buf23);


    //     char buf11;
    // char buf21;

    //  char buf12;
    // char buf22;

    //  char buf13[80];
    // char buf23[80];

    // int res_1 = s21_sscanf("11234", "%c%c%s", &buf11, &buf12, buf13);
    // int res_1_orig = sscanf("11234", "%c%c%s", &buf21, &buf22, buf23);
    

    // printf("res s21 = %d | res_orig = %d\n", res_1, res_1_orig);
    // printf("s21_sscanf: %c %c %s\n", buf11, buf12, buf13);
    // printf("ori_sscanf: %c %c %s\n", buf21, buf22, buf23);

    return 0;
}