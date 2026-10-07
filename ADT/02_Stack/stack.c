#include "stack.h"

STACK createStack(void)
{
    STACK s;
    s.top = 0;
    return s;
}

BOOL isEmpty(STACK s)
{
    return s.top == 0;
}

BOOL isFull(STACK s)
{
    return s.top == MAX_SIZE - 1;
}

BOOL push(STACK *s, int v)
{
    if (isFull(*s))
    {
        return FALSE;
    }
    s->top += 1;
    s->val[s->top] = v;
    return TRUE;
}

BOOL pop(STACK *s, int *v)
{
    if (isEmpty(*s))
    {
        return FALSE;
    }
    *v = s->val[s->top];
    s->top -= 1;
    return TRUE;
}

void display(STACK s)
{
    while (!isEmpty(s))
    {
        int x;
        pop(&s, &x);
        printf("%d ", x);
    }
    printf("\n");
}
