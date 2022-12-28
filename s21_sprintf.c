#include "s21_sprintf.h"

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "./src/s21_string.h"

#define N_DECIMAL_POINTS_PRECISION (1000000)
#define flag_plus 2
#define flag_minus 4
#define flag_space 8

typedef long long ll;

typedef struct flags {
  int precision;
  char flags;
  int width;
  int length;
  int sign;
} flags;

s21_size_t s21_strlen(const char *str) {
  s21_size_t strLength = 0;
  for (; str[strLength]; strLength++);
  return strLength;
}

int flag_implementation(char* buf, flags* fl) {
    int res = 0;
    // printf("FLAGS: %d\n", fl -> flags);
    switch(fl->flags) {
        case 2:
            if (fl-> sign == 0) s21_putchar(buf, '+');
            res++;
            break;
        // case 4:
        //     break;
        case 8:
            s21_putchar(buf, ' ');
            res++;
            break;
        default:
            if (!fl-> sign == 0) {
                s21_putchar(buf, '-');
                res++;
            }
            break;    
    }
    return res;
}

int s21_putchar(char* str, char c) {
  while (*str) str++;
  *str++ = c;
  *str = '\0';
  return 1;
}

int s21_putnumber(char* buf, ll num, flags* fl) {
  int res = 0;
  if (fl -> sign) num *= -1;
  res += flag_implementation(buf, fl);
  ll div = 1;
  while (num / div != 0) div *= 10;
  div /= 10;
  ll ostatok = 0;
  while (num % div >= 0) {
    ostatok = num / div;
    res += s21_putchar(buf, (char)('0' + ostatok));
    num = num % div;
    div /= 10;
    if (div == 0) break;
  }
  return res;
}

int s21_putstring(char* buf, char* str) {
  int res = 0;
  while (*str) {
    res += s21_putchar(buf, *str);
    str++;
  }
  return res;
}

int s21_putfloat(char* buf, double num, flags* fl) {
  int res = 0;
  ll pr =
      fl->precision > 0 ? pow(10, fl->precision) : N_DECIMAL_POINTS_PRECISION;
  int integerPart = (int)num;
  ll decimalPart = ((ll)(num * pr) % pr);
  res += s21_putnumber(buf, integerPart, fl);
  if (fl->precision >= 0 && decimalPart) {
    res += s21_putchar(buf, '.');
    res += s21_putnumber(buf, decimalPart, fl);
  }
  return res;
}

int s21_stoi(const char* str) {
  int res = 0;
  while (*str >= '0' && *str <= '9') {
    res *= 10;
    res += (*str - '0');
    str++;
  }
  return res;
}

int numLength(int num) {
  int res = 1;
  while (num / 10 > 0) {
    res++;
    num /= 10;
  }
  return res;
}

int is_digit(char c) { return (c >= '0' && c <= '9'); }

int is_spec(char c) {
  return (c == 'c' || c == 'd' || c == 'i' || c == 'f' || c == 's' ||
          c == 'u' || c == '%');
}

int is_special_symbols(char c) {
  return (c == '\\' || c == '\a' || c == '\b' || c == '\f' || c == '\n' ||
          c == '\r' || c == '\t' || c == '\v');
}


int spec_config(const char* format, flags* fl) {
  int res = 0;
  int len = 0;
  while (*format) {
    if (*format == '+') {
        fl->flags |= flag_plus;
        res++;
    }
    if (*format == '-') {
        fl->flags |= flag_minus;
        res++;
    }  
    if (*format == ' ') {
        fl->flags |= flag_space;
        res++;
    }
    if (is_digit(*format)) {
      fl->width = s21_stoi(format);
      res += numLength(fl->width);
    }
    if (*format == '.') {
      format++;
      res++;
      if (is_digit(*format)) {
        fl->precision = s21_stoi(format);
        len = numLength(fl->precision);
        res += len;
        format += len - 1;
      } else
        fl->precision = 0;
    }
    if (*format == '%') {
      res = 0;
      break;
    }
    if (is_spec(*format)) {
        format--;
        break;
    }
    format++;
  }
  return res;
}

void reset_specs(flags* fl) {
  fl->precision = 0;
  fl->flags = 0;
  fl->width = 0;
  fl->length = 0;
  fl->sign = 0;
}

void fill_buff(char* buf, int n){
    for (int i = 0; i < n; i++) s21_putchar(buf, ' ');
}

int s21_sprintf(char* buf, const char* format, ...) {
  flags fl = {0};
  buf[0] = '\0';
  va_list args;
  va_start(args, format);
  int res = 0;
  int move = 0;

//   printf("%d", len);
//   char* copy = (char*)malloc((len+1)*sizeof(char));
//   fill_buff(copy);
  while (*format) {
    if (*format == '%') {
      format++;
      reset_specs(&fl);
      move = spec_config(format, &fl);
      format += move;
      if (*format == 'c') {
        res += s21_putchar(buf, (char)va_arg(args, int));
      }
      if (*format == 's') {
        char* str = va_arg(args, char*);
        res += s21_putstring(buf, str);
      }
      if (*format == 'd') {
        int num = va_arg(args, int);
        if (num < 0) fl.sign = -1;
        res += s21_putnumber(buf, num, &fl);
      }
      if (*format == 'i') {
        int num = va_arg(args, int);
        if (num < 0) fl.sign = -1;
        res += s21_putnumber(buf, num, &fl);
      }
      if (*format == 'u') {
        ll num = va_arg(args, unsigned int);
        if (num < 0) fl.sign = -1;
        res += s21_putnumber(buf, num, &fl);
      }
      if (*format == 'f') {
        double num = va_arg(args, double);
        if (num < 0) fl.sign = -1;
        res += s21_putfloat(buf, num, &fl);
      }
      if (*format == '%') {
        res += s21_putchar(buf, *format);
      }
    } else
      res += s21_putchar(buf, *format);
    format++;
  }
  va_end(args);
  return res;
}

int main() {
  char str[80] = {'\0'};
  char str_orig[80] = {'\0'};
  const char formatter[80] = "%c %2s %.10f %c %u %% %% %.13f %+5d";

  int res_1 = s21_sprintf(str, formatter, 'A', "dsf1dsf",
                          111111.123, 'B', 12, 12.123, 4);
  int res_1_orig = sprintf(str_orig, formatter, 'A',
                           "dsf1dsf", 111111.123, 'B', 12, 12.123, 4);

  printf("res s21 = %d | res_orig = %d\n", res_1, res_1_orig);
  printf("s21_sprint: %s\n", str);
  printf("s_original: %s\n", str_orig);
  strcmp(str, str_orig) == 0 ? printf("STRINGS ARE EQUAL")
                             : printf("STRINGS ARE DIFFERENT");
  return 0;
}