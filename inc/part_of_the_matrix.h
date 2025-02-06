#ifndef PART_OF_THE_MATRIX_H
#define PART_OF_THE_MATRIX_H

#include "minilibmx.h"

typedef struct {
    int x, y;
} Point;

int mx_atoi(const char *str);
long mx_atoi(const char *str);
long mx_atoi_ruthless(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
char *mx_itoa(int number);
int mx_pow(int n, unsigned int pow);
void mx_printchar(char c);
void mx_printerr(const char *s);
void mx_printint(int n);
void mx_printstr(const char *s);
char *mx_str_reverse(char *s);

#endif

