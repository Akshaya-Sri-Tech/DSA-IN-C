#include "../ADT/02_Stack/char_stack.h"

BOOL isWReverseWForm(char str[])
{
    CHAR_STACK s = createCharStack();
    int i = 0;

    while (str[i] != '\0' && str[i] != '.')
    {
        charPush(&s, str[i]);
        i++;
    }

    if (str[i] == '.')
    {
        i++;
    }

    while (str[i] != '\0' && str[i] != '\n')
    {
        char ch = '\0';
        if (!charPop(&s, &ch))
        {
            return FALSE;
        }
        if (ch != str[i])
        {
            return FALSE;
        }
        i++;
    }

    return isCharStackEmpty(s);
}

int main(void)
{
    char str[100];
    printf("Enter the sequence: ");
    fgets(str, sizeof(str), stdin);

    if (isWReverseWForm(str))
    {
        printf("YES, it is in (w.w-reverse) form\n");
    }
    else
    {
        printf("NO, it is not in (w.w-reverse) form\n");
    }

    return 0;
}
