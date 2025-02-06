#include "minilibmx.h"

char *mx_strcpy(char *dst, const char *src) {
    char *ptr = dst;
    while (*src) {
        *dst++ = *src++;
    }
    *dst = '\0';
    return ptr;
}

