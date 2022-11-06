#include <stdio.h>
#include <stdlib.h>
// Circular Queue
struct Queue
{
    int *elem;
    int front, rear;
    unsigned size;
    int count;
};
typedef struct Queue Q;
Q *initQueue(unsigned size)
{
    Q *q = (Q *)malloc(sizeof(Q));
    q->size = size;
    q->front = q->count = 0;
    q->rear = -1;
    q->elem = (int *)malloc(q->size * sizeof(int));
}

int isFull(Q *q)
{
    return q->count == q->size;
}

int isEmpty(Q *q)
{
    return q->front == q->rear + 1;
}

void enQueue(Q *q, int val)
{
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % q->size;
    q->elem[q->rear] = val;
    q->count++;
}

int deQueue(Q *q)
{
    if (isEmpty(q))
        return -1;
    q->front = (q->front + 1) % q->size;
    q->count--;
    return q->elem[q->front - 1];
}

int front(Q *q)
{
    if (isEmpty(q))
        return -1;
    return q->elem[q->front];
}

int rear(Q *q)
{
    if (isEmpty(q))
        return -1;
    return q->elem[q->rear];
}

void deleteQueue(Q *q)
{
    free(q);
}
