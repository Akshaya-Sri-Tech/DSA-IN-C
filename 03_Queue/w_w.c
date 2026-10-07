#include "../ADT/03_Queue/char_queue.h"

BOOL checkWW(char s[])
{
    CHAR_QUEUE q1;
    createCharQueue(&q1);

    int i = 0;
    while (s[i] != '\0' && s[i] != '.')
    {
        enqueueChar(&q1, s[i]);
        i++;
    }

    if (s[i] == '.')
    {
        i++;
    }

    while (s[i] != '\0' && s[i] != '\n')
    {
        char x;
        if (!dequeueChar(&q1, &x))
        {
            return FALSE;
        }
        if (x != s[i])
        {
            return FALSE;
        }
        i++;
    }

    return isCharQueueEmpty(q1);
}

int main()
{
    char str[100];
    printf("Enter String (w.w): ");
    fgets(str, sizeof(str), stdin);

    if (checkWW(str))
    {
        printf("YES it is in w.w form\n");
    }
    else
    {
        printf("NO it is not in w.w form\n");
    }

    return 0;
}
