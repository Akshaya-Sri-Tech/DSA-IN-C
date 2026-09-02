#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef enum{FALSE,TRUE}BOOL;
typedef struct node{
    int data;
    BOOL lthread,rthread;
    struct node *left,*right;
}TBT;


TBT* makeNode(int data);
TBT* inSucc(TBT *cur);
void inOrder(TBT* t);
TBT* insert(TBT* head,int data);
TBT* makeHead();