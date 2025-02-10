#include "minilibmx.h"

static bool is_in_list(int x, int y, Point *b){
    while(b->x!=-1){
        if(x == b->x && y == b->y) return true;
        ++b;
    }
    return false;
}


void output_to_file(char **maze, Point *fp, Point *path, int row, int cols){
    int fd = open("path.txt", O_WRONLY | O_CREAT | O_TRUNC);

    if (fd < 0) {
        mx_printerr("Error creating file");
        return;
    }
    const char sbwls[4] = "*XD\n";

    for(int i = 0; i < row; ++i){
        for(int j = 0; j <= cols; ++j){
            if(j == cols){ 
                write(fd, &sbwls[3], 1);
                continue;
            }
            if(is_in_list(i,j, fp)){
                if(is_in_list(i,j, path)){
                    write(fd, &sbwls[1], 1);
                }else{
                    write(fd, &sbwls[2], 1);
                }
            }else if(is_in_list(i,j, path)){
                write(fd, &sbwls[0], 1);
            }else{
                write(fd, &maze[i][j], 1);
            }
        }
    } 
    close(fd);
}
