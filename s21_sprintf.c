#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "./src/s21_string.h"
#include "s21_sprintf.h"

#define N_DECIMAL_POINTS_PRECISION (1000000)
#define flag_plus 2
#define flag_minus 4
#define flag_space 8

typedef struct flags {
    int precision;
    int flags;
    int width;
    int length;
} flags;

int s21_putchar(char* str, char c) {
    while(*str) str++;
    *str++ = c;
    *str = '\0';
    return 1;
}

int s21_putnumber(char* buf, int num) {
    int res = 0;
    int div = 1;
    while (num / div != 0) div *= 10;
    div /= 10; 
    int ostatok = 0;
    while (num % div >= 0) {
        ostatok = num / div;
        res += s21_putchar(buf, (char)('0' + ostatok));
        num = num % div;
        div /= 10;
        if(div == 0) break;
    }
    return res; 
}

int s21_putstring(char* buf, char* str) {
    int res = 0;
        while( *str ) {
            res += s21_putchar(buf, *str);              
            str++;
        }
    return res;    
}

int s21_putfloat(char* buf, float num) {
    int res = 0;
    int integerPart = (int)num;
    int decimalPart = ((int)(num*N_DECIMAL_POINTS_PRECISION)%N_DECIMAL_POINTS_PRECISION);
    res += s21_putnumber(buf, integerPart);
    res += s21_putchar(buf, '.');
    res += s21_putnumber(buf, decimalPart);
    return res; 
}

int s21_stoi(char* str) {
    int res = 0;
    while(*str >= '0' && *str <= '9') {
        res *= 10;
        res += (*str - '0');
        str++;
    }
    return res;
}

void spec_config (char* format, flags* fl) {
    while(*format || *format != '%'){
        if(*format == '+') fl->flags += flag_plus;
        if(*format == '+') fl->flags += flag_minus;
        else if(*format == ' ') fl->flags += flag_space;
        if(*format >= '0' && *format <= '9') fl-> length = s21_atoi(format);
        format++;
    }
}

int s21_sprintf(char* buf, const char* format, ...) {
    flags fl = {0};
    buf[0] = '\0';
    va_list args;
    va_start (args, format);
    int res = 0;
    while (*format) {
        if (*format == '%') {
            format++;
            if(*format == 'c') {
                res += s21_putchar(buf, (char)va_arg(args, int));
            }
            if(*format == 's') {
                char* str = va_arg(args, char*);
                res += s21_putstring(buf, str);
            }
            if(*format == 'd') {
                int num = va_arg(args, int);
                res += s21_putnumber(buf, num);
            }
            if(*format == 'i') {
                int num = va_arg(args, int);
                res += s21_putnumber(buf, num);
            }
            if(*format == 'u') {
                int num = (int)va_arg(args, unsigned int);
                res += s21_putnumber(buf, num);
            }
            if(*format == 'f') {
                float num = (float)va_arg(args, double);
                res += s21_putfloat(buf, num);
            }
            if(*format == '%') {
                res += s21_putchar(buf, *format);
            }
        } else res += s21_putchar(buf, *format);
        format++;
    }
    va_end(args);
    return res;
}

int main() {
    char str[80] = {'\0'};
    char str_orig[80] = {'\0'};
    // char b = 'A';
    int res_1 = s21_sprintf(str, "%c %s %d %c %u %% %% %f", 'A', "dsf1dsf", 1123213, 'B', 12, 12.123);
    int res_1_orig = sprintf(str_orig, "%c %s %d %c %u %% %% %f", 'A', "dsf1dsf", 1123213, 'B', 12, 12.123);

    // int res_1 = s21_sprintf(str, "%c %s %d %c %u %% %%", 'A', "dsf1dsf", 1123213, 'B', 12);
    // int res_1_orig = sprintf(str_orig, "%c %s %d %c %u %% %%", 'A', "dsf1dsf", 1123213, 'B', 12);

    printf("res s21 = %d | res_orig = %d\n", res_1, res_1_orig);
    printf("s21_sprint: %s\n", str);
    printf("s_original: %s\n", str_orig);
    strcmp(str, str_orig) == 0 ? printf("STRINGS ARE EQUAL") : printf("STRINGS ARE DIFFERENT");
    return 0;
}