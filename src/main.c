#include "minilibmx.h"
#include <stdbool.h>
#include <limits.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, Point p) {
    if (q->rear == MAX_ROWS * MAX_COLS - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->data[q->rear] = p;
}

Point dequeue(Queue *q) {
    Point p = q->data[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return p;
}

int bfs(char maze[MAX_ROWS][MAX_COLS], int rows, int cols, Point start, Point end) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int dist[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dist[i][j] = -1;
        }
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, start);
    dist[start.x][start.y] = 0;

    while (!isEmpty(&q)) {
        Point current = dequeue(&q);
        if (current.x == end.x && current.y == end.y) {
            return dist[current.x][current.y];
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[current.x][current.y] + 1;
                enqueue(&q, (Point){nx, ny});
            }
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        return 1;
    }

    char *file_name = argv[1];
    int x1 = mx_atoi(argv[2]);
    int y1 = mx_atoi(argv[3]);
    int x2 = mx_atoi(argv[4]);
    int y2 = mx_atoi(argv[5]);

    FILE *file = fopen(file_name, "r");
    if (!file) {
        mx_printerr("error: file not found\n");
        return 1;
    }

    char maze[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;
    char line[MAX_COLS];

    while (fgets(line, sizeof(line), file)) {
        cols = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '#' || line[i] == '.' || line[i] == ',') {
                maze[rows][cols++] = line[i];
            }
        }
        rows++;
    }

    fclose(file);

    if (x1 < 0 || x1 >= rows || y1 < 0 || y1 >= cols || maze[x1][y1] == '#') {
        mx_printerr("error: invalid start point\n");
        return 1;
    }

    if (x2 < 0 || x2 >= rows || y2 < 0 || y2 >= cols || maze[x2][y2] == '#') {
        mx_printerr("error: invalid end point\n");
        return 1;
    }

    Point start = {x1, y1};
    Point end = {x2, y2};
    int distance = bfs(maze, rows, cols, start, end);

    if (distance != -1) {
        mx_printstr("dist=");
        mx_printint(distance);
        mx_printchar('\n');
    } else {
        mx_printerr("error: route not found\n");
    }

    return 0;
}

