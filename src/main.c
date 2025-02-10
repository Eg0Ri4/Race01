#include "minilibmx.h"

void free_maze(char **maze, int rows) {
    for (int i = 0; i < rows; i++) {
        free(maze[i]);
    }
    free(maze);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        return 1;
    }

    int x1 = mx_atoi(argv[2]);
    int y1 = mx_atoi(argv[3]);
    int x2 = mx_atoi(argv[4]);
    int y2 = mx_atoi(argv[5]);

    for (int i = 2; i < 6; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!mx_isdigit(argv[i][j]) && argv[i][j] != '-') {
                mx_printerr("error: invalid coordinates\n");
                return 1;
            }
        }
    }

    char **maze = mx_file_to_strarr(argv[1]);
    if(maze == NULL){ 
        mx_printerr("map does not exist\n");
        return 1;
    }else if(maze[0][0] == 'e'){
        mx_printerr("map error\n");
        return 1;
    }
    int rows = 0;
    while (maze[rows] != NULL) {
        rows++;
    }
    int cols = mx_strlen(maze[0]);

    if (rows == 0 || cols == 0) {
        mx_printerr("error\n");
        return 1;
    }

    if (x1 < 0 || y1 < 0 || x2 < 0 ||
        y2 < 0 || x1 >= cols || y1 >= rows ||
        x2 >= cols || y2 >= rows) {
        mx_printerr("points are out of map range\n");
        free_maze(maze, rows);
        return 1;
    }

    if (maze[y1][x1] == '#') {
        mx_printerr("entry point cannot be an obstacle\n");
        free_maze(maze, rows);
        return 1;
    }

    if (maze[y2][x2] == '#') {
        mx_printerr("exit point cannot be an obstacle\n");
        free_maze(maze, rows);
        return 1;
    }

    if (x1 == x2 && y1 == y2) {
        mx_printerr("error: start and end points are the same\n");
        free_maze(maze, rows);
        return 1;
    }

    Point start = {x1, y1};
    Point end = {x2, y2};
    Point farthest_points[MAX_ROWS * MAX_COLS];
    int farthest_count = 0;
    int max_distance = 0;
    Point *path = NULL;
    int path_length = 0;

    int distance = mx_bfs(maze, rows, cols, start, end, &path, &path_length, farthest_points, &farthest_count, &max_distance);
    output_to_file(maze, farthest_points, farthest_count, path, path_length, rows, cols);

    if (distance == -1) {
        mx_printerr("route not found\n");
        free_maze(maze, rows);
        return 1;
    } else {
        printf("%d\n", distance);
    }

    if (path) {
        free(path);
    }

    free_maze(maze, rows);

    return 0;
}
