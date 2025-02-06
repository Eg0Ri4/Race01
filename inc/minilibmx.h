#ifndef MINILIBMX_H
#define MINILIBMX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(int size);
char *mx_strtrim(const char *str);
void mx_strdel(char **str);
int mx_strcmp(const char *s1, const char *s2);

#endif

