#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "./src/s21_string.h"
#include "s21_sprintf.h"

#define N_DECIMAL_POINTS_PRECISION (1000000)
#define INT_MAX 2147483640;
typedef long long ll;

typedef struct Token {
  int width;
  char width_star;
  char length_l;
  char length_L;
  char length_h;
  char sign;
  char spec;
} Token;

int s21_stoi(char** data, Token* tk) {
  int res = 0;
  if (**data == '-') tk->sign = -1;
  int width = tk->width ? tk->width : INT_MAX;
  while (**data >= '0' && **data <= '9' && width--) {
    res *= 10;
    res += (**data - '0');
    (*data)++;
  }
  return res;
}

int is_digit(char c) { return (c >= '0' && c <= '9'); }

int is_special_symbols(char c) {
  return (c == '\\' || c == '\a' || c == '\b' || c == '\f' || c == '\n' ||
          c == '\r' || c == '\t' || c == '\v');
}

// s21_size_t s21_strlen(const char* str) {
//   s21_size_t strLength = 0;
//   for (; str[strLength]; strLength++)
//     ;
//   return strLength;
// }

int s21_getchar(char** str, char* c) {
  int result = **str ? 1 : 0;
  *c = **str;
  return result;
}

// int s21_getnumber(char** data, ll num, Token* tk) {
//   int res = 0;
//   ll div = 1;
//   while (num / div != 0) div *= 10;
//   div /= 10;
//   ll ostatok = 0;
//   while (num % div >= 0) {
//     ostatok = num / div;
//     res += s21_getchar(buf, (char)('0' + ostatok));
//     num = num % div;
//     div /= 10;
//     if (div == 0) break;
//   }
//   return res * tk->sign;
// }

void get_star_data(va_list* args, Token* tk) {
  if (tk->spec == 'c') {
    char* c = (char*)va_arg(*args, char*);
    // *c = '0';
  }
}

int is_spec(char c) {
  return (c == 'c' || c == 'd' || c == 'i' || c == 'f' || c == 's' ||
          c == 'u' || c == '%' || c == 'G' || c == 'g' || c == 'o' ||
          c == 'x' || c == 'X' || c == 'p' || c == 'n' || c == 'e' || c == 'E');
}

void token_config(char** fmt, Token* tk) {
  while (**fmt) {
    if (**fmt == '*') tk->width_star = 1;
    if (is_digit(**fmt)) {
      tk->width = s21_stoi(fmt, tk);
    }
    if (**fmt == '%') break;
    if (**fmt == 'h') tk->length_h = 1;
    if (**fmt == 'l') tk->length_l = 1;
    if (**fmt == 'L') tk->length_L = 1;
    if (is_spec(**fmt)) {
      tk->spec = **fmt;
      break;
    }
    (*fmt)++;
  }
}

int s21_getstring(char** str, char* string, Token* tk) {
  int res = **str ? 1 : 0;
  int width = tk->width ? tk->width : INT_MAX;
  while (**str && **str != ' ' && width--) {
    s21_getchar(str, string);
    string++;
    (*str)++;
  }
  return res;
}

// int s21_putfloat(char* buf, double num, Token* tok) {
//   int res = 0;
//   ll pr =
//       tok->precision > 0 ? pow(10, tok->precision) :
//       N_DECIMAL_POINTS_PRECISION;
//   int integerPart = (int)num;
//   ll decimalPart = ((ll)(num * pr) % pr);
//   res += s21_putnumber(buf, integerPart, tok);
//   if (tok->precision >= 0 && decimalPart) {
//     res += s21_putchar(buf, '.');
//     res += s21_putnumber(buf, decimalPart, tok);
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

void reset_specs(Token* tk) {
  tk->width = 0;
  tk->width_star = 0;
  tk->length_l = 0;
  tk->length_h = 0;
  tk->length_L = 0;
  tk->sign = 1;
  tk->spec = '\0';
}

int s21_sscanf(const char* str, const char* format, ...) {
  Token tk;
  reset_specs(&tk);
  char *data = (char*)str, *fmt = (char*)format;
  va_list args;
  va_start(args, format);
  int res = *str ? 0 : -1;

  while (*fmt && *data) {  // WARNING: возможно убрать условие с data
    if (*fmt == '%') {
      // format++;
      fmt++;
      token_config(&fmt, &tk);
      get_star_data(&args, &tk);
      switch (tk.spec) {
        case 'c':
          // printf("yes\n");
          s21_getchar(&data, (char*)va_arg(args, char*));
          res++;
          data++;
          break;
        case 's':
          res += s21_getstring(&data, va_arg(args, char*), &tk);
          break;
      }
      // format++;
      fmt++;
    }
    va_end(args);
  }
  return res;
}

int main() {
  char buf11[80];
  char buf21[80];

  char buf12;
  char buf22;

  char buf13;
  char buf23;

  int res_1 = s21_sscanf("fdgdr gdg234", "%3s%c%c", buf11, &buf12, &buf13);
  int res_1_ori = sscanf("fdgdr gdg234", "%3s%c%c", buf21, &buf22, &buf23);

  printf("res s21 = %d | res_orig = %d\n", res_1, res_1_ori);
  printf("s21_sscanf: %s %c %c\n", buf11, buf12, buf13);
  printf("ori_sscanf: %s %c %c\n", buf21, buf22, buf23);

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