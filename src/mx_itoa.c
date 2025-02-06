#include "minilibmx.h"

char *mx_itoa(int number) {
    if (number == 0) {
        return mx_strcpy(mx_strnew(1), "0");
    }

    int length = 0;
    int temp = number;
    while (temp != 0) {
        temp /= 10;
        length++;
    }

    char *result = mx_strnew(length);
    if (!result) return NULL;

    int index = length - 1;
    if (number < 0) {
        result[0] = '-';
        number = -number;
    }

    while (number != 0) {
        result[index--] = (number % 10) + '0';
        number /= 10;
    }

    return result;
}

