#include "circular_linked_list.h"

CNode *makeNode(int data)
{
    CNode *temp = (CNode *)malloc(sizeof(CNode));
    temp->data = data;
    temp->next = temp;
    return temp;
}

void display(CNode *list)
{
    if (!list)
    {
        printf("Empty\n");
        return;
    }
    CNode *temp = list;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list);
    printf("(HEAD)\n");
}

int length(CNode *list)
{
    if (!list)
    {
        return 0;
    }
    int count = 0;
    CNode *temp = list;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != list);
    return count;
}

CNode *insertFront(CNode *list, int data)
{
    if (!list)
    {
        return makeNode(data);
    }
    CNode *last = list;
    while (last->next != list)
    {
        last = last->next;
    }
    CNode *temp = makeNode(data);
    temp->next = list;
    last->next = temp;
    return temp;
}

CNode *insertBack(CNode *list, int data)
{
    if (!list)
    {
        return makeNode(data);
    }
    CNode *last = list;
    while (last->next != list)
    {
        last = last->next;
    }
    CNode *temp = makeNode(data);
    temp->next = list;
    last->next = temp;
    return list;
}

CNode *insertPos(CNode *list, int pos, int data)
{
    if (pos <= 1 || !list)
    {
        return insertFront(list, data);
    }
    CNode *temp = list;
    for (int i = 1; i < pos - 1 && temp->next != list; i++)
    {
        temp = temp->next;
    }
    CNode *newNode = makeNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return list;
}

CNode *deleteFront(CNode *list)
{
    if (!list)
    {
        return NULL;
    }
    if (list->next == list)
    {
        free(list);
        return NULL;
    }
    CNode *last = list;
    while (last->next != list)
    {
        last = last->next;
    }
    last->next = list->next;
    CNode *temp = list;
    list = list->next;
    free(temp);
    return list;
}

CNode *deleteBack(CNode *list)
{
    if (!list)
    {
        return NULL;
    }
    if (list->next == list)
    {
        free(list);
        return NULL;
    }
    CNode *temp = list;
    while (temp->next->next != list)
    {
        temp = temp->next;
    }
    CNode *last = temp->next;
    temp->next = list;
    free(last);
    return list;
}

CNode *deletePos(CNode *list, int pos)
{
    if (!list || pos <= 0)
    {
        return list;
    }
    if (pos == 1)
    {
        return deleteFront(list);
    }
    CNode *temp = list;
    for (int i = 1; i < pos - 1 && temp->next != list; i++)
    {
        temp = temp->next;
    }
    if (temp->next != list)
    {
        CNode *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }
    return list;
}

CNode *search(CNode *list, int key)
{
    if (!list)
    {
        return NULL;
    }
    CNode *temp = list;
    do
    {
        if (temp->data == key)
        {
            return temp;
        }
        temp = temp->next;
    } while (temp != list);
    return NULL;
}
