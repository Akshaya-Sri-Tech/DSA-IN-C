/* LAB QUESTION 
Implement the following operations:
1.Create a list with 10 random integers (0–99).
2.Insert an integer in sorted order; increment frequency for duplicates.
3.Delete one occurrence of an integer.
4.Reset the list to empty.
5.Delete all occurrences of an integer.
6.Display the frequency of an integer.
7.Count distinct nodes.
8.Count total values, including duplicates.
9.Display the list in [data, freq] format.
10.Quit the program.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data; int freq;
    struct node *next;
} NODE;

NODE *makeNode(int data, NODE *t)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = t;
    temp->freq=1;
    return temp;
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

void display(NODE *head)
{
    while (head)
    {
        printf("[%3d,%3d]", head->data,head->freq);
        head = head->next;
    }
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

NODE *inSort(NODE *head, int data)
{
    int pos=findPos(data,head);
    if(pos!=-1){
        NODE *temp = head;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;
        temp->freq++;
        return head;
    }
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

NODE* delSort(NODE* l,int data){
    if(!l) return l;
    if(l->data==data){
            l->freq--;
        if(l->freq==0){
            return l->next;
        }
    }
    if(l->data>data) return l;
    l->next=delSort(l->next,data);
    return l;
}

NODE* delSortAll(NODE* l,int data){
    if(!l) return l;
    if(l->data==data) return l->next;
    if(l->data>data) return l;
    l->next=delSortAll(l->next,data);
    return l;
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

int countVal(NODE *head)
{
    int total = 0;
    while (head)
    {
        total+=head->freq;
        head = head->next;
    }
    return total;
}

int freq(NODE *head,int data)
{
    int pos = 1;
    while (head)
    {
        if (head->data == data)
        {
            return head->freq;
        }
        pos++;
        head = head->next;
    }
    return 0;
}
int sumNode(NODE *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return head->data + sumNode(head->next);
}

NODE* l1;
int main(){
    while(1){
        printf("1.Create\n");
        printf("2.Insert\n");
        printf("3.Delete\n");
        printf("4.Reset\n");
        printf("5.Clear\n");
        printf("6.display frequency\n");
        printf("7.Total nodes\n");
        printf("8.Total values\n");
        printf("9.Display\n");
        printf("10.Quit\n");

        int choice;
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            {
                for(int i=0;i<10;i++){
                    l1=inSort(l1,rand()%100);
                }
                break;
            }
        case 2:
            {
                int data;
                printf("Enter the data : ");
                scanf("%d",&data);
                l1=inSort(l1,data);
                break;
            }
        case 3:
            {
                int data;
                printf("Enter the data : ");
                scanf("%d",&data);
                l1=delSort(l1,data);
                break;
            }
        case 4:
            {
                l1=NULL;
                break;
            }
        case 5:
            {
                int data;
                printf("Enter the data : ");
                scanf("%d",&data);
                l1=delSortAll(l1,data);
                break;
            }
        case 6:
            {
                int data;
                printf("Enter the data : ");
                scanf("%d",&data);
                printf("Freq : %2d\n",freq(l1,data));
                break;
            }
        case 7:
            {
                printf("\nTotal Nodes :");
                printf("%2d\n\n",count(l1));
                break;
            }
        case 8:
            {
                printf("\nTotal Values :");
                printf("%2d\n\n",countVal(l1));
                break;
            }
        case 9:
            {
                printf("\nList :");
                display(l1);
                printf("\n\n");
                break;
            }
        default : return;
        }

    }

}
