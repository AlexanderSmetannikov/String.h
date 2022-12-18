#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "s21_string.h"
#include <getopt.h>

#define _GNU_SOURCE

char* parser(char* format) {
   int res = 0;
   while ( (res = getopt(, format, "ab:C::d")) != -1){
		switch (rez) {
		case 'c': printf("found argument \"a\".\n"); break;
		case 'd': printf("found argument \"b = %s\".\n", optarg); break;
		case 'i': printf("found argument \"C = %s\".\n", optarg); break;
		case 'f': printf("found argument \"d\"\n"); break;
        case 's': printf("found argument \"d\"\n"); break;
        case 'u': printf("found argument \"d\"\n"); break;
        case '%': printf("found argument \"d\"\n"); break;
		case '.': printf("Error found !\n"); break;

		} // switch
	} // while
}

int s21_sprintf(char* buf, const char* format, ...) {
    va_list ptr;
    va_start(ptr, format);
    while(*format) {
        ()
    }
}

void s21_printf(char* format, ...) {
  va_list ptr;
  va_start(ptr, format);
  while (*format) {
        if (*format == 'i') printf("число - %d\n", va_arg(ptr, int));
        if (*format == 's') printf("строка - %s\n", va_arg(ptr, char*));
        if (*format == 'd') printf("число с пл. точкой - %f\n", va_arg(ptr, double));
        format++;
    }
  va_end(ptr);
}

int main() {
    s21_printf("isd", 12, "это тестовая строка", 12.12);
    return 0;
}