#include <stddef.h>

char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);


char *mx_strdup(const char *str) {
    if (!str) {
        return NULL;
    }
    char *sec_str = mx_strnew(mx_strlen(str));  
    if (!sec_str) {
        return NULL;
    }
    return mx_strcpy(sec_str, str);
}
