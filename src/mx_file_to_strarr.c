#include "minilibmx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char **mx_file_to_strarr(const char *filename) {
    int f = open(filename, O_RDONLY);
    if (f < 0) return NULL;

    char c;
    char *buffer = mx_strnew(0);
    char **result = malloc(sizeof(char *) * 100); // 100 строк
    int line_count = 0;

    while (read(f, &c, 1) > 0) {
        if (c == ',' || (mx_isspace(c) && c != '\n')) continue;
        if (c == '\n') {
            result[line_count++] = buffer; 
            buffer = mx_strnew(0);         
        }else if(c == '#' || c == '.'){
            char temp[2] = {c, '\0'};
            char *new_buffer = mx_strjoin(buffer, temp);
            free(buffer);
            buffer = new_buffer;
        }else{
            result[0][0] =  'e';
            return result;
        }
    }

    if (mx_strlen(buffer) > 0) { 
        result[line_count++] = buffer;
    } else {
        free(buffer);
    }

    result[line_count] = NULL;
    close(f);
    return result;
}
