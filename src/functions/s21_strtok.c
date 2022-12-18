#include "../s21_string.h"

int is_delim(char c, const char* delim) {
    int ans = 0;
    while (*delim && !ans) {
        if(c == *delim) ans = 1;
        delim++;
    }
    return ans;
}

// s21_size_t s21_strcspn(const char *str, const char *keys) {
//     s21_size_t res = 0;
//     while(!s21_strchr(keys, *str) && *str != '\0') {
//         str++;
//         res++;
//     }
//     return res;
// }

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
