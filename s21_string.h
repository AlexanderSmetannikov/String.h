#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>
#include <stdlib.h>

#define s21_NULL ((void *)0)

#define s21_size_t unsigned long long

// Searching
void *s21_memchr(const void *str, int symbol, s21_size_t size);
char *s21_strchr(const char *str, int symbol);
char *s21_strpbrk(const char *str, const char *keys);
char *s21_strrchr(const char *str, int symbol);
char *s21_strstr(const char *destptr, const char *srcptr);

// Calculation
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strspn(const char *str, const char *keys);
s21_size_t s21_strcspn(const char *str, const char *keys);

// Копирование
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

// Сравнение
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

#endif  // SRC_S21_STRING_H_