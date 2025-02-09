#ifndef BFS_H
#define BFS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Структура для хранения координат точки
typedef struct {
    int x, y;
} Point;

// Структура для очереди (состоящая из узлов)
typedef struct {
    Point point;
    int distance;
} QueueNode;

// Структура для самой очереди
typedef struct {
    QueueNode nodes[MAX_ROWS * MAX_COLS];
    int front, rear;
} Queue;

// Объявления функций, использующих эти структуры
void enqueue(Queue *q, Point p, int distance);
QueueNode dequeue(Queue *q);
bool is_empty(Queue *q);
int mx_bfs(char maze[MAX_ROWS][MAX_COLS], int rows, int cols, Point start, Point end,
           Point *path, int *path_length, Point *farthest_points, int *farthest_count, int *max_distance);

#endif