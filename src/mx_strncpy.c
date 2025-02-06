#include "minilibmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    char *ptr = dst;
    while (len-- && (*dst++ = *src++)) {}
    while (len-- > 0) {
        *dst++ = '\0';
    }
    return ptr;
}

