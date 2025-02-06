#include "minilibmx.h"

int mx_pow(int n, unsigned int pow) {
    int result = 1;
    for (unsigned int i = 0; i < pow; i++) {
        result *= n;
    }
    return result;
}

