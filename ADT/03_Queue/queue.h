#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#ifndef BOOL_TYPE_DEFINED
#define BOOL_TYPE_DEFINED
typedef enum
{
    FALSE,
    TRUE
} BOOL;
#endif

#define QUEUE_MAX_SIZE 20

typedef struct
{
    int val[QUEUE_MAX_SIZE];
    int rear, front;
} QUEUE;

void createQueue(QUEUE *q);
BOOL isQueueEmpty(QUEUE q);
BOOL isQueueFull(QUEUE q);
BOOL enqueue(QUEUE *q, int data);
BOOL dequeue(QUEUE *q, int *data);
int queueSize(QUEUE q);
void displayQueue(QUEUE q);

#endif
