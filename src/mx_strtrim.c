#include "minilibmx.h"

char *mx_strtrim(const char *str) {
    if (!str) return NULL;

    int start = 0;
    while (mx_isspace(str[start])) start++;

    int end = mx_strlen(str) - 1;
    while (mx_isspace(str[end]) && end >= start) end--;

    int len = end - start + 1;
    char *result = mx_strnew(len);
    if (!result) return NULL;

    mx_strncpy(result, str + start, len);
    return result;
}

