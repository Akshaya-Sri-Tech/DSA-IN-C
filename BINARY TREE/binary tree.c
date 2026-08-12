#include<stdio.h>
#include "binary tree.h"

BT* makeNode(int data){
    BT *t=(BT *)malloc(sizeof(BT));
    t->data=data; t->left=NULL; t->right=NULL; return t;
}

void inOrder(BT *t){
    if(t){
        inOrder(t->left);
        printf("%5d",t->data);
        inOrder(t->right);
    }
}

void preOrder(BT *t){
    if(t){
        printf("%5d",t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void postOrder(BT *t){
    if(t){
        postOrder(t->left);
        postOrder(t->right);
        printf("%5d",t->data);
    }
}

BT* insert(BT* t,int data){
    if(!t) return makeNode(data);
    if(t->data>data) t->left=insert(t->left,data);
    if(t->data<data) t->right=insert(t->right,data);
    return t;
}

BOOL search(BT* t,int data){
    if(!t) return FALSE;
    if(t->data==data) return 1;
    if(t->data>data) return search(t->left,data);
    return search(t->right,data);
}

int count(BT* t){
    if(!t) return 0;
    return 1+count(t->left)+count(t->right);
}

int height(BT* t){
    if(!t) return 0;
    int l=height(t->left);
    int r=height(t->right);
    return (l>r)? l+1 : r+1;
}

BOOL isEquals(BT* p,BT* q){
    if(!p && !q) return TRUE;
    if(!p || !q) return FALSE;
    if(p->data != q->data) return FALSE;
    return isEquals(p->left,q->left) && isEquals(p->right,q->right);
}