#include<stdlib.h>
#include<stdio.h>
typedef enum
{
    FALSE,
    TRUE
} BOOL;
typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *makeNode(int data, NODE *t)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = t;
    return temp;
}

void display(NODE *head)
{
    while (head)
    {
        printf("%5d", head->data);
        head = head->next;
    }
}

NODE *insertHead(int data, NODE *head)
{
    NODE *temp = makeNode(data, head);
    return temp;
}

NODE *insertTail(int data, NODE *head)
{
    if (!head)
    {
        return makeNode(data, NULL);
    }
    NODE *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = makeNode(data, NULL);
    return head;
}

BOOL isIncreasing(NODE* head){
    if (head == NULL) return TRUE;
    while(head->next){
        if(head->data>=head->next->data) return FALSE;
        head=head->next;
    }
    return TRUE;
}

BOOL isSame(NODE* l1,NODE* l2){
    if (l1 == NULL || l2 == NULL) return l1 == l2;
    while(l1->next && l2->next){
        if(l1->data != l2->data) return FALSE;
        l1=l1->next;  l2=l2->next;
    }
    return (l1->next==NULL) && (l2->next==NULL) ;
}

NODE* copyListRec(NODE* l){
    if(!l) return NULL;
    NODE* temp=makeNode(l->data,NULL);
    temp->next=copyListRec(l->next);
    return temp;
}


NODE* concatList(NODE* l1, NODE* l2)
{
    NODE* l = l1;
    if (l1 == NULL) return copyListRec(l2);
    while (l1->next) l1 = l1->next;
    while (l2 != NULL)
    {
        l1->next = makeNode(l2->data, NULL);
        l1 = l1->next;
        l2 = l2->next;
    }
    return l;
}

int middleNode(NODE* l){
    if (l == NULL) return -1;
    NODE* slow=l;
    NODE* fast=l;
    while(fast && fast->next){
        slow=slow->next; fast=fast->next->next;
    }
    return slow->data;
}

int main(){
    NODE* l1=NULL;
    NODE* l2=NULL;
    for(int i=0;i<10;i++){
        l1=insertTail(rand()%10,l1);
        l2=insertTail(rand()%10,l2);
    }
    printf("L1 : "); display(l1); printf("\n");
    printf("L2 : "); display(l2);


    if(isIncreasing(l1)) printf("\nIncreasing");
    else printf("\nNot Increasing");

    if(isSame(l1,l2)) printf("\nSame");
    else printf("\nNot Same");

    NODE* l3=concatList(l1,l2);
    printf("\nL3 : "); display(l3); printf("\n");

    l1 = copyListRec(l2);
    printf("L1 : "); display(l1); printf("\n");
    printf("L2 : "); display(l2);

    printf("\nMiddle Node of L3 : %2d\n",middleNode(l3));
    printf("\nMiddle Node of L1 : %2d\n",middleNode(l1));
    printf("\nMiddle Node of L2 : %2d\n",middleNode(l2));

}