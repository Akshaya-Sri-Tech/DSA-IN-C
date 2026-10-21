/*Write a C program to construct a Binary Search Tree (BST) by
inserting 500 randomly generated integers in the range 0–9.
Store the frequency of each distinct value in its node and
display the values with their frequencies in ascending order using inorder traversal.
*/

#include<stdio.h>
#include<stdlib.h>

typedef enum{ FALSE, TRUE}BOOL;
typedef struct node{
    int data; int freq;
    struct node* left;
    struct node* right;
}BT;

BT* makeNode(int data){
    BT *t=(BT *)malloc(sizeof(BT));
    t->data=data; t->freq=1; t->left=NULL; t->right=NULL; return t;
}

void inOrder(BT *t){
    if(t){
        inOrder(t->left);
        printf("[%2d,%5d]  ",t->data,t->freq);
        inOrder(t->right);
    }
}
BT* insert(BT* t,int data){
    if(!t) return makeNode(data);
    if(t->data==data) { t->freq++; return t; }
    if(t->data>data)  t->left=insert(t->left,data);
    if(t->data<data) t->right=insert(t->right,data);
    return t;
}

int main(){
    BT* root=NULL;
    for(int i=0;i<500;i++) root=insert(root,rand()%10);
    inOrder(root);
    return 0;
}
