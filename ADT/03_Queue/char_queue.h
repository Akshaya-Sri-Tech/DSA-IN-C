#ifndef CHAR_QUEUE_H
#define CHAR_QUEUE_H

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

#define CHAR_QUEUE_MAX_SIZE 20

typedef struct
{
    char val[CHAR_QUEUE_MAX_SIZE];
    int rear, front;
} CHAR_QUEUE;

void createCharQueue(CHAR_QUEUE *q);
BOOL isCharQueueEmpty(CHAR_QUEUE q);
BOOL isCharQueueFull(CHAR_QUEUE q);
BOOL enqueueChar(CHAR_QUEUE *q, char data);
BOOL dequeueChar(CHAR_QUEUE *q, char *data);
int charQueueSize(CHAR_QUEUE q);
void displayCharQueue(CHAR_QUEUE q);

#endif
