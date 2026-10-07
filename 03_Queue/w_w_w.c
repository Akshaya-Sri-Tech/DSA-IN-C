#include "../ADT/03_Queue/char_queue.h"

BOOL checkWWW(char s[])
{
    CHAR_QUEUE q1, q2;
    createCharQueue(&q1);
    createCharQueue(&q2);

    int i = 0;

    while (s[i] != '\0' && s[i] != '.')
    {
        enqueueChar(&q1, s[i]);
        i++;
    }

    if (s[i] != '.')
        return FALSE;

    i++;

    while (s[i] != '\0' && s[i] != '.')
    {
        char x;

        if (!dequeueChar(&q1, &x))
            return FALSE;

        if (x != s[i])
            return FALSE;

        enqueueChar(&q2, s[i]);
        i++;
    }

    if (!isCharQueueEmpty(q1))
        return FALSE;

    if (s[i] != '.')
        return FALSE;

    i++;

    while (s[i] != '\0' && s[i] != '\n')
    {
        char x;

        if (!dequeueChar(&q2, &x))
            return FALSE;

        if (x != s[i])
            return FALSE;

        i++;
    }

    if (!isCharQueueEmpty(q2))
        return FALSE;
    return TRUE;
}

int main()
{
    char str[100];
    printf("Enter String (w.w.w): ");
    fgets(str, sizeof(str), stdin);

    if (checkWWW(str))
    {
        printf("YES it is in w.w.w form\n");
    }
    else
    {
        printf("NO it is not in w.w.w form\n");
    }

    return 0;
}
