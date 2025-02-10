#include "minilibmx.h"

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

int dx[] = {0, 0, -1, 1};  
int dy[] = {-1, 1, 0, 0}; 
 
int mx_bfs(char **maze, int rows, int cols, Point start, Point end, 
           Point **path, int *path_length, Point *farthest_points, int *farthest_count, int *max_distance) {

    int **dist = (int **)malloc(rows * sizeof(int *));
    Point **parent = (Point **)malloc(rows * sizeof(Point *));
    if (!dist || !parent) return -1; 

    for (int i = 0; i < rows; i++) {
        dist[i] = (int *)malloc(cols * sizeof(int));
        parent[i] = (Point *)malloc(cols * sizeof(Point));
        if (!dist[i] || !parent[i]) return -1;
        for (int j = 0; j < cols; j++) {
            dist[i][j] = -1;
            parent[i][j] = (Point){-1, -1}; 
        }
    }

    Queue queue = { .front = 0, .rear = 0 };
    dist[start.y][start.x] = 0;
    enqueue(&queue, start, 0);

    *max_distance = 0;
    *farthest_count = 0;

    while (!is_empty(&queue)) {
        QueueNode node = dequeue(&queue);
        Point p = node.point;
        int d = node.distance;

        if (d > *max_distance) {
            *max_distance = d;
            *farthest_count = 0;
        }
        if (d == *max_distance) {
            farthest_points[*farthest_count] = p;
            (*farthest_count)++;
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];  
            int ny = p.y + dy[i];  

            if (nx >= 0 && nx < cols && ny >= 0 && ny < rows && 
                maze[ny][nx] != '#' && dist[ny][nx] == -1) {
                
                dist[ny][nx] = d + 1;
                parent[ny][nx] = p;
                enqueue(&queue, (Point){nx, ny}, d + 1);
            }
        }
    }

    if (dist[end.y][end.x] == -1) {
        *path_length = 0;
        return -1; 
    }

    *path_length = dist[end.y][end.x] + 1;
    *path = (Point *)malloc((*path_length) * sizeof(Point));

    Point current = end;
    for (int i = *path_length - 1; i >= 0; i--) {
        (*path)[i] = current;
        current = parent[current.y][current.x]; 
    }

    int final_distance = dist[end.y][end.x];

    for (int i = 0; i < rows; i++) {
        free(dist[i]);
        free(parent[i]);
    }
    free(dist);
    free(parent);

    return final_distance;
}
