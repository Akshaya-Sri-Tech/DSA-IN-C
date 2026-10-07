#include "../ADT/02_Stack/char_stack.h"

BOOL isBalanced(char str[])
{
    CHAR_STACK s = createCharStack();
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            charPush(&s, str[i]);
        }
        else if (str[i] == ')')
        {
            char ch = '\0';
            if (!charPop(&s, &ch))
            {
                return FALSE;
            }
        }
    }
    return isCharStackEmpty(s);
}

int main()
{
    char str[100];
    printf("Enter the bracket sequence: ");
    fgets(str, sizeof(str), stdin);

    if (isBalanced(str))
    {
        printf("YES, it is balanced\n");
    }
    else
    {
        printf("NO, it is not balanced\n");
    }

    return 0;
}
