#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "bfs.h"



int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(int size);
char *mx_strtrim(const char *str);
void mx_strdel(char **str);
int mx_strcmp(const char *s1, const char *s2);
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
char *mx_strcat(char *s1, const char *s2);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strdup(const char *str);
char **mx_file_to_strarr(const char *filename);



