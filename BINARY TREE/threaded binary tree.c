#include<stdio.h>
#include<stdlib.h>

typedef enum{FALSE,TRUE}BOOL;
typedef struct node{
    int data;
    BOOL lthread,rthread;
    struct node *left,*right;
}TBT;


TBT* makeNode(int data){
    TBT* temp=(TBT *)malloc(sizeof(TBT));
    temp->data=data;
    temp->left=NULL; temp->right=NULL;
    temp->lthread=TRUE; temp->rthread=TRUE;
    return temp;
}

TBT* inSucc(TBT *cur){
    TBT* s=cur->right;
    if(cur->rthread){
        while(s!=NULL && s->lthread)
            s=s->left;
    }
    return s;
}

void inOrder(TBT* t){
    TBT* head=t;
    while((t=inSucc(t))!=head){
        printf("%5d",t->data);
    }
    printf("\n");
}

TBT* insert(TBT* head,int data){
    TBT* newNode=makeNode(data);
        if(head->left==head){
        head->left=newNode;
        head->lthread=FALSE;

        newNode->left=head;
        newNode->right=head;

        return head;
    }

    TBT* cur=head->left;

    while(TRUE){
        if(cur->data<data){
            if(cur->rthread){
                TBT *tempNext=cur->right;
                cur->right=newNode;
                cur->rthread=FALSE;
                cur->right->left=cur;
                cur->right->right=tempNext;
                break;
            }
            cur=cur->right;
        }
        if(cur->data>data){
            if(cur->lthread){
                TBT *tempNext=cur->left;
                cur->left=newNode;
                cur->lthread=FALSE;
                cur->left->right=cur;
                cur->left->left=tempNext;
                break;
            }
            cur=cur->left;
        }
        if(cur->data==data) break;
    }
    return head;
}

TBT* makeHead(){
    TBT* head=makeNode(0);

    head->left=head;
    head->right=head;

    head->lthread=FALSE;
    head->rthread=TRUE;

    return head;
}

