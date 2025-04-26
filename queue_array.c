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

int isEmpty(Queue *q)
{
    return q->size == 0;
}
int isfull(Queue *q){
    return q->size==q->capacity;
}

void Enqueue(Queue *q, int data)
{
    (q->arr)[++(q->rear)] = data;
    q->front = 0;
    q->size++;
    printf("the %d is in queue at %d position.\n", data, q->rear);
}

int peek(Queue *q){
    return q->arr[q->front];
}


void free_memo(Queue *q){
    free(q->arr);
    free(q);
}
int main()
{
    Queue *Q1 = create_queue(10);
    Enqueue(Q1, 10);
    Enqueue(Q1, 20);
    Enqueue(Q1, 30);
    Enqueue(Q1, 40);

    printf("%d", isEmpty(Q1));
    free_memo(Q1);
    return 0;
}