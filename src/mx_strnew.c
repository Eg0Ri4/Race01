#include <stddef.h>
#include <stdlib.h>

char *mx_strnew(const int size) {
    if (size < 0) {
        return NULL;
    }
    char *vector = (char *)malloc((size + 1) * sizeof(char));
    if (!vector) {
        return NULL;
    }
    vector[size] = '\0';
    return vector;
}
