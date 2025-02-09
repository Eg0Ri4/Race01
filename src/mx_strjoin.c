#include "minilibmx.h"

char *mx_strjoin(char const *s1, char const *s2){
    if(s1 == NULL && s2 == NULL) return NULL;
    if(s1 == NULL || s2 == NULL) return (s1 == NULL)? mx_strdup(s2) : mx_strdup(s1);
    int size = mx_strlen(s1) + mx_strlen(s2);
    char *c = mx_strnew(size);
    
    if(c == NULL) return NULL; 
    mx_strcpy(c, s1);
    mx_strcat(c, s2);
    return c;    
}


