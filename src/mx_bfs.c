#include "bfs.h"

void enqueue(Queue *q, Point p, int distance) {
    q->nodes[q->rear].point = p;
    q->nodes[q->rear].distance = distance;
    q->rear++;
}

QueueNode dequeue(Queue *q) {
    return q->nodes[q->front++];
}

bool is_empty(Queue *q) {
    return q->front == q->rear;
}

// Четыре направления (вверх, вниз, влево, вправо)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// BFS для поиска кратчайшего пути и самой дальней точки
int mx_bfs(char maze[MAX_ROWS][MAX_COLS], int rows, int cols, Point start, Point end, 
           Point *path, int *path_length, Point *farthest_points, int *farthest_count, int *max_distance) {
    int dist[MAX_ROWS][MAX_COLS];
    Point parent[MAX_ROWS][MAX_COLS]; // Для восстановления пути
    Queue queue = { .front = 0, .rear = 0 };
    
    // Инициализируем массив расстояний
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dist[i][j] = -1;
        }
    }

    // Начало BFS
    dist[start.x][start.y] = 0;
    enqueue(&queue, start, 0);
    *max_distance = 0;
    *farthest_count = 0;

    while (!is_empty(&queue)) {
        QueueNode node = dequeue(&queue);
        Point p = node.point;
        int d = node.distance;

        // Проверяем, является ли эта точка самой дальней
        if (d > *max_distance) {
            *max_distance = d;
            *farthest_count = 0;
        }
        if (d == *max_distance) {
            farthest_points[*farthest_count] = p;
            (*farthest_count)++;
        }

        // Проверяем соседей
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && 
                maze[nx][ny] == '.' && dist[nx][ny] == -1) {
                
                dist[nx][ny] = d + 1;
                parent[nx][ny] = p; // Запоминаем, откуда пришли
                enqueue(&queue, (Point){nx, ny}, d + 1);
            }
        }
    }

    // Восстанавливаем путь до выхода
    *path_length = 0;
    Point current = end;
    
    while (!(current.x == start.x && current.y == start.y)) {
        path[*path_length] = current;
        (*path_length)++;
        current = parent[current.x][current.y];
    }
    path[*path_length] = start;
    (*path_length)++;

    // Возвращаем расстояние до выхода
    return dist[end.x][end.y];
}
