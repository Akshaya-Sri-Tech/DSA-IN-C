#include "char_stack.h"

CHAR_STACK createCharStack(void)
{
    CHAR_STACK s;
    s.top = 0;
    return s;
}

BOOL isCharStackEmpty(CHAR_STACK s)
{
    return s.top == 0;
}

BOOL isCharStackFull(CHAR_STACK s)
{
    return s.top == CHAR_STACK_MAX_SIZE - 1;
}

BOOL charPush(CHAR_STACK *s, char v)
{
    if (isCharStackFull(*s))
    {
        return FALSE;
    }
    s->top += 1;
    s->val[s->top] = v;
    return TRUE;
}

BOOL charPop(CHAR_STACK *s, char *v)
{
    if (isCharStackEmpty(*s))
    {
        return FALSE;
    }
    *v = s->val[s->top];
    s->top -= 1;
    return TRUE;
}

void displayCharStack(CHAR_STACK s)
{
    while (!isCharStackEmpty(s))
    {
        char x;
        charPop(&s, &x);
        printf("%c ", x);
    }
    printf("\n");
}
