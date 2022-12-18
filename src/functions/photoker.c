#include "../s21_string.h"
#include <stdio.h>
#include <string.h>

s21_size_t s21_strlen(const char *str) {
  s21_size_t strLength = 0;
  for (; str[strLength]; strLength++);
  return strLength;
}

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
    const char* s1 = str1;
    const char* s2 = str2;
    int res = 0;
    if (s1 != s21_NULL && s2 != s21_NULL) {
        while (n-- && res == 0) res = *s1++ - *s2++; 
    }
    return res;
}

void* s21_memmove(void* dest, const void* src, s21_size_t n) {
    char* ds = dest;
    const char* source = src;
    if (ds < source) {
        for(s21_size_t i = 0; i < n; i++) *ds++ = *source++;
    } else {
        char* dsend = ds + (n-1);
        const char* sourceend = source + (n-1);
        for(int i = (int)n-1; i >= 0; i--) *dsend-- = *sourceend--;
    }
    return dest;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char* ds = dest;
    const char* source = src;
    for(s21_size_t i = 0; i < n; i++) *ds++ = *source++;
    return dest;
}

void* s21_memset(void* str, int c, s21_size_t n) {
    char* s = str;
    for (s21_size_t i = 0; i < n; i++) *s++ = (char)c;
    return str;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    while(n-- && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int s21_strcmp(const char *str1, const char *str2){
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char *s21_strcpy(char *dest, const char *src) {
    while (*src) *dest++ = *src++;
    return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    while (*src && n--) *dest++ = *src++;
    return dest;
}

char *s21_strchr(const char *str, int symbol) {
    int i = 0;
    while (str[i] && str[i] != symbol) i++;
    return symbol == str[i] ? (char*)str + i : s21_NULL;
}

char *s21_strcat(char *dest, const char *src) {
    int len = 0;
    while (*dest) {
        dest++;
        len++;
    }
    while(*src) {
        *dest++ = *src++;
        len++;
    }
    *dest = '\0';
    dest -= len; 
    return dest;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
    int len = 0;
    while (*dest) {
        dest++;
        len++;
    }
    while(*src && n--) {
        *dest++ = *src++;
        len++;
    }
    *dest = '\0';
    dest -= len; 
    return dest;
}

int is_delim(char c, const char* delim) {
    int ans = 0;
    while (*delim && !ans) {
        if(c == *delim) ans = 1;
        delim++;
    }
    return ans;
}

s21_size_t s21_strcspn(const char *str, const char *keys) {
    s21_size_t res = 0;
    while(!s21_strchr(keys, *str) && *str != '\0') {
        str++;
        res++;
    }
    return res;
}

char *s21_strtok(char *str, const char *delim) {
    static char* back_str;
    
    if(!str) str = back_str;
    if(!str) return NULL;
    while(1) {
        if(is_delim(*str, delim)) {
            str++;
            continue;
        }
        if(*str == '\0') return NULL; 
        break;
    }
    char *ret = str;
    while(1) {
        if(*str == '\0') {
            back_str = str;
            return ret;
        }
        if(is_delim(*str, delim)) {
            *str = '\0';
            back_str = str + 1;
            return ret;
        }
        str++;
    }
}

int main() {
    // const char s1[] = "atoms\0\0\0\0";
    // const char s2[] = "atoms\0abc";
    // const char s3[] = "atomsaaa";
    // printf("%d\n", s21_strcmp(s1, s2));
    // printf("%d\n", s21_strcmp(s1, s3));
    // printf("%d\n", s21_memcmp(s1, s3, 5));
    // printf("%d\n", s21_memcmp(s1, s2, 8));
    // printf("%d\n", s21_strncmp(s1, s2, 8));
    // printf("%d\n", s21_strncmp(s1, s3, 5));

    // printf("\n%d\n", strcmp(s1, s2));
    // printf("%d\n", strcmp(s1, s3));
    // printf("%d\n", memcmp(s1, s3, 5));
    // printf("%d\n", memcmp(s1, s2, 8));
    // printf("%d\n", strncmp(s1, s2, 8));
    // printf("%d\n", strncmp(s1, s3, 5));

    //const char s1[] = "atoms\0fdsf0\0";
    //char s2[] = "atoms\0abc";
//    const char s3[] = "atom";
//     char s4[] = "atom";

    // s21_strcpy(s2, s1);
    // strcpy(s4, s3);
    // printf("%s\n", s2);
    // printf("%s\n", s4);
//     char app[1024]="вторая строка ";
//    // Массив приемник данных
//     char dst[1024]="первая строка";
//     // s21_strcat(s2, s1);
//     strncat(dst, app, 2);
//     // printf("%s\n", s2);
//     printf("%s\n", dst);

    char str [44]="test1/test2/test3/test4,/test5";
   // Набор символов, которые должны входить в искомый сегмент
   char sep [10]="/,";
   // Переменная, в которую будут заноситься начальные адреса частей
   // строки str
   char *istr;

   printf ("Исходная строка: %s\n", str);
   printf ("Результат разбиения:\n");
   // Выделение первой части строки
   istr = s21_strtok (str,sep);

   // Выделение последующих частей
   while (istr != NULL)
   {
      // Вывод очередной выделенной части
      printf ("%s\n",istr);
      // Выделение очередной части строки
      istr = s21_strtok(NULL,sep);
   }
    return 0;
}