#include "../ADT/02_Stack/char_stack.h"

BOOL isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
}

void postfixConversion(char expression[])
{
    CHAR_STACK s = createCharStack();
    printf("Postfix expression: ");

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            printf("%c", ch);
        }
        else if (ch == '(')
        {
            charPush(&s, ch);
        }
        else if (ch == ')')
        {
            char top;
            while (!isCharStackEmpty(s))
            {
                charPop(&s, &top);
                if (top == '(')
                {
                    break;
                }
                printf("%c", top);
            }
        }
        else if (isOperator(ch))
        {
            while (!isCharStackEmpty(s))
            {
                char top;
                charPop(&s, &top);
                if (top == '(')
                {
                    charPush(&s, top);
                    break;
                }
                printf("%c", top);
            }
            charPush(&s, ch);
        }
    }

    while (!isCharStackEmpty(s))
    {
        char top;
        charPop(&s, &top);
        if (top != '(')
        {
            printf("%c", top);
        }
    }
    printf("\n");
}

int main()
{
    char expression[100];
    printf("Enter expression: ");
    fgets(expression, sizeof(expression), stdin);
    postfixConversion(expression);
    return 0;
}
