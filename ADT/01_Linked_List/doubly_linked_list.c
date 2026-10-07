#include "doubly_linked_list.h"

DNode *createNode(int data)
{
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

DNode *insertFront(DNode *head, int data)
{
    DNode *newNode = createNode(data);
    if (head != NULL)
    {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

DNode *insertEnd(DNode *head, int data)
{
    DNode *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    DNode *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

DNode *deleteFront(DNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    DNode *temp = head;
    head = head->next;
    if (head)
    {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

DNode *deleteEnd(DNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    DNode *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    if (temp->prev)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }
    free(temp);
    return head;
}

void display(DNode *head)
{
    DNode *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseDisplay(DNode *head)
{
    if (head == NULL)
    {
        return;
    }
    DNode *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
