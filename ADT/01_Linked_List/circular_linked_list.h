#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} CNode;

CNode *makeNode(int data);
void display(CNode *list);
int length(CNode *list);
CNode *insertFront(CNode *list, int data);
CNode *insertBack(CNode *list, int data);
CNode *insertPos(CNode *list, int pos, int data);
CNode *deleteFront(CNode *list);
CNode *deleteBack(CNode *list);
CNode *deletePos(CNode *list, int pos);
CNode *search(CNode *list, int key);

#endif
