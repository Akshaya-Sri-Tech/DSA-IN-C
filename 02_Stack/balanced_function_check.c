#include "../ADT/02_Stack/char_stack.h"

BOOL isBalancedFunctionOrder(char str[])
{
    CHAR_STACK s = createCharStack();
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            charPush(&s, str[i]);
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (isCharStackEmpty(s))
            {
                return FALSE;
            }
            char top;
            charPop(&s, &top);
            if (top != (char)(str[i] - 32))
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
    printf("Enter the function call-return sequence: ");
    fgets(str, sizeof(str), stdin);

    if (isBalancedFunctionOrder(str))
    {
        printf("YES, it is a balanced function call-return sequence\n");
    }
    else
    {
        printf("NO, it is not a balanced function call-return sequence\n");
    }

    return 0;
}
