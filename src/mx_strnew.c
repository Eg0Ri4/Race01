#include "minilibmx.h"
#include <stdlib.h>

char *mx_strnew(int size) {
    if (size < 0) return NULL;
    char *str = (char *)malloc(size + 1);
    if (str) {
        for (int i = 0; i <= size; i++) {
            str[i] = '\0';
        }
    }
    return str;
}

