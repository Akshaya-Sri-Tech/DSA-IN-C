#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} BST;

BST *makeNode(int data)
{
    BST *t = (BST *)malloc(sizeof(BST));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void inOrder(BST *t)
{
    if (t)
    {
        inOrder(t->left);
        printf("%5d", t->data);
        inOrder(t->right);
    }
}

BST *insert(BST *t, int data)
{
    if (!t)
    {
        return makeNode(data);
    }
    if (t->data > data)
    {
        t->left = insert(t->left, data);
    }
    if (t->data < data)
    {
        t->right = insert(t->right, data);
    }
    return t;
}

int k_smallest(BST *t,int *k)
{
    if (t)
    {
        int left = k_smallest(t->left,k);
        if(left != -1) return left;
        (*k)--;
        if((*k)==0) return t->data;
        return k_smallest(t->right,k);
    }
    return -1;
}

int main(){
    BST* root=NULL;
    for(int i=0;i<10;i++){
        root=insert(root,rand()%100);
    }
    inOrder(root);
    int n=2;
    printf("\n K-th Smallest : %d\n",k_smallest(root,&n));
}