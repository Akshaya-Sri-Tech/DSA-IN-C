#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int col;
    int data;
    struct node *next;
} NODE;

NODE *createNode(int col, int data)
{
    NODE *t = malloc(sizeof(NODE));

    if (t == NULL)
        exit(1);

    t->col = col;
    t->data = data;
    t->next = NULL;

    return t;
}

void insert(NODE **head, int col, int data)
{
    if (data == 0)
        return;

    NODE *t = createNode(col, data);

    if (*head == NULL) {
        *head = t;
        return;
    }

    NODE *p = *head;

    while (p->next != NULL)
        p = p->next;

    p->next = t;
}

void display(NODE *rows[], int m)
{
    for (int i = 0; i < m; i++) {
        printf("Row %d: ", i);

        NODE *p = rows[i];

        while (p != NULL) {
            printf("(%d, %d) -> ", p->col, p->data);
            p = p->next;
        }

        printf("NULL\n");
    }
}

int main(void)
{
    int a[3][4] = {
        {0, 5, 0, 0},
        {2, 0, 0, 7},
        {0, 0, 3, 0}
    };

    int m = 3, n = 4;
    NODE *rows[3] = {NULL};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0)
                insert(&rows[i], j, a[i][j]);
        }
    }

    display(rows, m);

    return 0;
}