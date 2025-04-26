#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int rear;
    int size;
    int capacity;
    int *arr;
} Queue;

Queue *create_queue(int capacity)
{
    Queue *new_queue = (Queue *)malloc(sizeof(Queue));
    new_queue->arr = (int *)malloc(capacity * sizeof(int));
    new_queue->capacity = capacity;
    new_queue->size = 0;
    new_queue->front = -1;
    new_queue->rear = -1;
    return new_queue;
}
