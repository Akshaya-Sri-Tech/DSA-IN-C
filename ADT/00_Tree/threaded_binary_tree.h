#ifndef THREADED_BINARY_TREE_H
#define THREADED_BINARY_TREE_H

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

typedef struct node
{
    int data;
    BOOL lthread, rthread;
    struct node *left, *right;
} TBT;

TBT *makeNode(int data);
TBT *inSucc(TBT *cur);
void inOrder(TBT *t);
TBT *insert(TBT *head, int data);
TBT *makeHead();

#endif
