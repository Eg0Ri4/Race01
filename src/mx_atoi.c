#include "minilibmx.h"

long mx_atoi(const char *str) {
    long result = 0;
    int sign = 1;

    while (mx_isspace(*str)) str++;

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

    return result * sign;
}

