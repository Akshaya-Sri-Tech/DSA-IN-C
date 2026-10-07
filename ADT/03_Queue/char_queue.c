#include "char_queue.h"

void createCharQueue(CHAR_QUEUE *q)
{
    q->rear = q->front = 0;
}

BOOL isCharQueueEmpty(CHAR_QUEUE q)
{
    return q.front == q.rear;
}

BOOL isCharQueueFull(CHAR_QUEUE q)
{
    return (q.rear + 1) % CHAR_QUEUE_MAX_SIZE == q.front;
}

BOOL enqueueChar(CHAR_QUEUE *q, char data)
{
    if (isCharQueueFull(*q))
    {
        return FALSE;
    }
    q->rear = (q->rear + 1) % CHAR_QUEUE_MAX_SIZE;
    q->val[q->rear] = data;
    return TRUE;
}

BOOL dequeueChar(CHAR_QUEUE *q, char *data)
{
    if (isCharQueueEmpty(*q))
    {
        return FALSE;
    }
    q->front = (q->front + 1) % CHAR_QUEUE_MAX_SIZE;
    *data = q->val[q->front];
    return TRUE;
}

int charQueueSize(CHAR_QUEUE q)
{
    return (q.rear - q.front + CHAR_QUEUE_MAX_SIZE) % CHAR_QUEUE_MAX_SIZE;
}

void displayCharQueue(CHAR_QUEUE q)
{
    char value;
    printf("Queue: ");
    while (!isCharQueueEmpty(q))
    {
        dequeueChar(&q, &value);
        printf("%c ", value);
    }
    printf("\n");
}
