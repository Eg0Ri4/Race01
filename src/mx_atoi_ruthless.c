#include "minilibmx.h"

long mx_atoi_ruthless(const char *str) {
    long result = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    while (mx_isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }

    if (*str != '\0') {
        mx_printerr("error: invalid number format\n");
        exit(1);
    }

    return result * sign;
}

