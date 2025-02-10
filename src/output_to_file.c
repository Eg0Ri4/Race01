#include "minilibmx.h"

static bool is_in_list(int x, int y, Point *b, int ll){
    for (int i = 0; i < ll; ++i) {
        if (x == b[i].y && y == b[i].x) {
            return true;
        }
    }
    return false;
}


void output_to_file(char **maze, Point *fp, int fl, Point *path, int pl, int row, int cols){
    int fd = open("path.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        mx_printerr("Error creating file");
        return;
    }
    const char sbwls[5] = "*XD\n";

    for(int i = 0; i < row; ++i){
        for(int j = 0; j <= cols; ++j){
            if(j == cols){ 
                write(fd, &sbwls[3], 1);
                continue;
            }
            if(is_in_list(i,j, fp, fl)){
                if(is_in_list(i,j, path, pl)){
                    write(fd, &sbwls[1], 1);
                }else{
                    write(fd, &sbwls[2], 1);
                }
            }else if(is_in_list(i,j, path, pl) && maze[i][j] != '#'){
                write(fd, &sbwls[0], 1);
            }else{
                write(fd, &maze[i][j], 1);
            }
        }
    } 
    close(fd);
}
