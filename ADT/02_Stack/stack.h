#ifndef STACK_H
#define STACK_H

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

#define MAX_SIZE 10

typedef struct
{
    int val[MAX_SIZE];
    int top;
} STACK;

STACK createStack(void);
BOOL isEmpty(STACK s);
BOOL isFull(STACK s);
BOOL push(STACK *s, int v);
BOOL pop(STACK *s, int *v);
void display(STACK s);

#endif
