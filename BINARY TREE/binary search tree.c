#include<stdio.h>
#include "binary search tree.h"

BST* makeNode(int data){
    BST *t=(BST *)malloc(sizeof(BST));
    t->data=data; t->left=NULL; t->right=NULL; return t;
}

void inOrder(BST *t){
    if(t){
        inOrder(t->left);
        printf("%5d",t->data);
        inOrder(t->right);
    }
}

void preOrder(BST *t){
    if(t){
        printf("%5d",t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void postOrder(BST *t){
    if(t){
        postOrder(t->left);
        postOrder(t->right);
        printf("%5d",t->data);
    }
}

BST* insert(BST* t,int data){
    if(!t) return makeNode(data);
    if(t->data>data) t->left=insert(t->left,data);
    if(t->data<data) t->right=insert(t->right,data);
    return t;
}

BOOL search(BST* t,int data){
    if(!t) return FALSE;
    if(t->data==data) return 1;
    if(t->data>data) return search(t->left,data);
    return search(t->right,data);
}

int count(BST* t){
    if(!t) return 0;
    return 1+count(t->left)+count(t->right);
}

int height(BST* t){
    if(!t) return 0;
    int l=height(t->left);
    int r=height(t->right);
    return (l>r)? l+1 : r+1;
}

BOOL isEquals(BST* p,BST* q){
    if(!p && !q) return TRUE;
    if(!p || !q) return FALSE;
    if(p->data != q->data) return FALSE;
    return isEquals(p->left,q->left) && isEquals(p->right,q->right);
}