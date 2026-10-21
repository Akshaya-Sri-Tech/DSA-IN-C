/*Write a C program to construct a Binary Search Tree (BST) using strings as node data.
Perform an inorder traversal to display the strings in lexicographical order.
Count and display the number of leaf nodes, nodes with exactly one child, and nodes with two children.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{ FALSE, TRUE}BOOL;
typedef struct node{
    char data[100];
    struct node* left;
    struct node* right;
}BT;

BT* makeNode(char data[]){
    BT *t=(BT *)malloc(sizeof(BT));
    strcpy(t->data,data); t->left=NULL; t->right=NULL; return t;
}

void inOrder(BT *t){
    if(t){
        inOrder(t->left);
        printf("%s  ",t->data);
        inOrder(t->right);
    }
}
BT* insert(BT* t,char *data){
    if(!t) return makeNode(data);
    int cp=strcmp(t->data,data);
    if(cp>0) t->left=insert(t->left,data);
    if(cp<0) t->right=insert(t->right,data);
    return t;
}

int countLeaf(BT* t){
        if(!t) return 0;
        if(!t->left && !t->right) return 1;
        return countLeaf(t->left)+countLeaf(t->right);
}

int countOne(BT* t){
        if(!t) return 0;
        if(!t->left && t->right || t->left && !t->right) return 1;
        return countOne(t->left)+countOne(t->right);
}

int countTwo(BT* t){
        if(!t) return 0;
        if(t->left && t->right) return 1+countTwo(t->left)+countTwo(t->right);
        return countTwo(t->left)+countTwo(t->right);
}

int count(BT *t)
{
    if (!t) return 0;
    return 1 + count(t->left) + count(t->right);
}

int main(){
    BT* root=makeNode("Dog");
    root=insert(root,"Banana");
    root=insert(root,"Cat");
    root=insert(root,"Apple");
    root=insert(root,"Fanta");
    root=insert(root,"Egg");
    root=insert(root,"Goat");
    printf("\nTOTAL :%5d",count(root));
    printf("\nLEAF :%5d",countLeaf(root));
    printf("\nONE CHILD :%5d",countOne(root));
    printf("\nTWO CHILD :%5d\n",countTwo(root));
    inOrder(root);
}
