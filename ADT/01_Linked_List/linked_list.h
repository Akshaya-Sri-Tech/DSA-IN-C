#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
    struct node *next;
} NODE;

NODE *makeNode(int data, NODE *t);
void display(NODE *head);
void revDisplay(NODE *head);
NODE *insertHead(int data, NODE *head);
NODE *insertTail(int data, NODE *head);
int count(NODE *head);
int recCount(NODE *head);
int findPos(int data, NODE *head);
int findPosRec(int data, NODE *head, int pos);
int sumNode(NODE *head);
NODE *reverseList(NODE *head);

#endif
