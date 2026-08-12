#pragma once

#include<stdio.h>
#include<stdlib.h>
typedef enum{ FALSE, TRUE}BOOL;
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}BT;

BT* makeNode(int data);
void inOrder(BT *t);
void preOrder(BT *t);
void postOrder(BT *t);
BT* insert(BT* t,int data);
BOOL search(BT* t,int data);
int count(BT* t);
int height(BT* t);
BOOL isEquals(BT* p,BT* q);