#include <stdio.h>

int main(void)
{
    int a = 10;
    int *p = &a;

    printf("a            : %d\n", a);
    printf("&a           : %p\n", (void *)&a);
    printf("p            : %p\n", (void *)p);
    printf("*p           : %d\n", *p);
    printf("&p           : %p\n", (void *)&p);
    printf("*&a          : %d\n", *&a);
    printf("(void*)p     : %p\n", (void *)p);
    printf("(void*)&p    : %p\n", (void *)&p);
    return 0;
}
