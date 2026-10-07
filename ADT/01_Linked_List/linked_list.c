#include "linked_list.h"

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

void revDisplay(NODE *head)
{
    if (head)
    {
        revDisplay(head->next);
        printf("%5d", head->data);
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

int count(NODE *head)
{
    int total = 0;
    while (head)
    {
        total++;
        head = head->next;
    }
    return total;
}

int recCount(NODE *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + recCount(head->next);
}

int findPos(int data, NODE *head)
{
    int pos = 1;
    while (head)
    {
        if (head->data == data)
        {
            return pos;
        }
        pos++;
        head = head->next;
    }
    return -1;
}

int findPosRec(int data, NODE *head, int pos)
{
    if (!head)
    {
        return -1;
    }
    if (head->data == data)
    {
        return pos;
    }
    return findPosRec(data, head->next, pos + 1);
}

int sumNode(NODE *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return head->data + sumNode(head->next);
}

NODE *reverseList(NODE *head)
{
    NODE *prev = NULL;
    NODE *curr = head;
    while (curr)
    {
        NODE *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
