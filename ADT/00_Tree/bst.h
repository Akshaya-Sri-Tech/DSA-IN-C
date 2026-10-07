#ifndef BST_H
#define BST_H

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
    struct node *left;
    struct node *right;
} BST;

BST *makeNode(int data);
void inOrder(BST *t);
void preOrder(BST *t);
void postOrder(BST *t);
int findMin(BST *t);
BST *insert(BST *t, int data);
BOOL search(BST *t, int data);
BST *deleteNode(BST *t, int data);
int count(BST *t);
int height(BST *t);
BOOL isEquals(BST *p, BST *q);

#endif
