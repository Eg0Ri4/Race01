#include "minilibmx.h"

char *mx_str_reverse(char *s) {
    int len = mx_strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
    return s;
}

