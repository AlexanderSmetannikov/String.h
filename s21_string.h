#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>
#include <stdlib.h>

#define s21_size_t unsigned long long
#define s21_NULL (void*)0

// копирование
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *str, int c, size_t n);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);

// сравнение
int memcmp(const void *str1, const void *str2, size_t n);
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t n);

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

#endif  // SRC_S21_STRING_H_