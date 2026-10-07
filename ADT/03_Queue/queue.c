#include "queue.h"

void createQueue(QUEUE *q)
{
    q->rear = q->front = 0;
}

BOOL isQueueEmpty(QUEUE q)
{
    return q.front == q.rear;
}

BOOL isQueueFull(QUEUE q)
{
    return (q.rear + 1) % QUEUE_MAX_SIZE == q.front;
}

BOOL enqueue(QUEUE *q, int data)
{
    if (isQueueFull(*q))
    {
        return FALSE;
    }
    q->rear = (q->rear + 1) % QUEUE_MAX_SIZE;
    q->val[q->rear] = data;
    return TRUE;
}

BOOL dequeue(QUEUE *q, int *data)
{
    if (isQueueEmpty(*q))
    {
        return FALSE;
    }
    q->front = (q->front + 1) % QUEUE_MAX_SIZE;
    *data = q->val[q->front];
    return TRUE;
}

int queueSize(QUEUE q)
{
    return (q.rear - q.front + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
}

void displayQueue(QUEUE q)
{
    int value;
    printf("Queue: ");
    while (!isQueueEmpty(q))
    {
        dequeue(&q, &value);
        printf("%d ", value);
    }
    printf("\n");
}
