#include "sorted_linked_list.h"

NODE *inSort(NODE *head, int data)
{
    if (!head)
    {
        return makeNode(data, NULL);
    }
    if (head->data > data)
    {
        return insertHead(data, head);
    }
    NODE *temp = head;
    while (temp->next != NULL && temp->next->data < data)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        return insertTail(data, head);
    }
    NODE *newNode = makeNode(data, temp->next);
    temp->next = newNode;
    return head;
}
