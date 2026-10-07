#ifndef CHAR_STACK_H
#define CHAR_STACK_H

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

#define CHAR_STACK_MAX_SIZE 20

typedef struct
{
    char val[CHAR_STACK_MAX_SIZE];
    int top;
} CHAR_STACK;

CHAR_STACK createCharStack(void);
BOOL isCharStackEmpty(CHAR_STACK s);
BOOL isCharStackFull(CHAR_STACK s);
BOOL charPush(CHAR_STACK *s, char v);
BOOL charPop(CHAR_STACK *s, char *v);
void displayCharStack(CHAR_STACK s);

#endif
