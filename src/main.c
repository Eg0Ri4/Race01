#include "minilibmx.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        mx_print_usage();
        return 1;
    }

    char *file_name = argv[1];
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

    char maze[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;

    FILE *file = fopen(file_name, "r");
    if (!file) {
        mx_handle_error(INVALID_FILE, file_name);
        return 1;
    }

    char line[MAX_COLS];
    bool is_valid_format = true;

    while (fgets(line, sizeof(line), file)) {
        cols = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '#' || line[i] == '.' || line[i] == ',') {
                maze[rows][cols++] = line[i];
            } else if (line[i] != '\n') {
                is_valid_format = false;
                break;
            }
        }
        if (!is_valid_format) break;
        rows++;
    }

    fclose(file);

    if (!is_valid_format) {
        mx_printerr("error: invalid file format\n");
        return 1;
    }

    if (rows == 0 || cols == 0) {
        mx_printerr("error: file is empty\n");
        return 1;
    }

    if (x1 < 0 || y1 < 0 || x2 < 0 ||
        y2 < 0 || x1 >= rows || y1 >= cols ||
        x2 >= rows || y2 >= cols) {
        mx_printerr("points are out of map range\n");
        return 1;
    }

    if (maze[x1][y1] == '#') {
        mx_printerr("entry point cannot be an obstacle\n");
        return 1;
    }

    if (maze[x2][y2] == '#') {
        mx_printerr("exit point cannot be an obstacle\n");
        return 1;
    }

    if (x1 == x2 && y1 == y2) {
        mx_printerr("error: start and end points are the same\n");
        return 1;
    }

    Point start = {x1, y1};
    Point end = {x2, y2};
    Point farthest_points[MAX_ROWS * MAX_COLS];
    int farthest_count = 0;
    int max_distance = 0;
    Point path[MAX_ROWS * MAX_COLS];
    int path_length = 0;

    int distance = mx_bfs(maze, rows, cols, start, end, path, &path_length, farthest_points, &farthest_count, &max_distance);
    mx_file_to_starr(maze);

    if (distance == -1) {
        mx_printerr("route not found\n");
        return 1;
    } else {
        mx_print_distance(distance);
    }

    return 0;
}

