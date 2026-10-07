#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} DNode;

DNode *createNode(int data);
DNode *insertFront(DNode *head, int data);
DNode *insertEnd(DNode *head, int data);
DNode *deleteFront(DNode *head);
DNode *deleteEnd(DNode *head);
void display(DNode *head);
void reverseDisplay(DNode *head);

#endif
