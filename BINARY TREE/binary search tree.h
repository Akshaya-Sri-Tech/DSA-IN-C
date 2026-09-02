#pragma once

#include<stdio.h>
#include<stdlib.h>
typedef enum{ FALSE, TRUE}BOOL;
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}BST;

BST* makeNode(int data);
void inOrder(BST *t);
void preOrder(BST *t);
void postOrder(BST *t);
BST* insert(BST* t,int data);
BOOL search(BST* t,int data);
int count(BST* t);
int height(BST* t);
BOOL isEquals(BST* p,BST* q);