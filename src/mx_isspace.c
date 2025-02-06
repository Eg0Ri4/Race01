#include "minilibmx.h"

bool mx_isspace(char c) {
    return c == ' ' || (c >= '\t' && c <= '\r');
}

