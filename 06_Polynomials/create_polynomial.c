#include <stdio.h>

typedef struct
{
    int coeff;
    int exp;
} TERM;

typedef struct
{
    int n;
    TERM p[100];
} POLY;

POLY createPoly(void)
{
    POLY pol;
    pol.n = 0;
    return pol;
}

POLY attachPoly(POLY pol, TERM t)
{
    POLY result = pol;
    result.p[result.n] = t;
    result.n += 1;

    for (int i = 0; i < result.n; i++)
    {
        for (int j = i + 1; j < result.n; j++)
        {
            if (result.p[i].exp == result.p[j].exp)
            {
                result.p[i].coeff += result.p[j].coeff;
                result.p[j].exp = 0;
            }
        }
    }

    return result;
}

void printPoly(POLY pol)
{
    for (int i = 0; i < pol.n; i++)
    {
        if (pol.p[i].exp != 0)
        {
            printf("%dx^%d ", pol.p[i].coeff, pol.p[i].exp);
        }
    }
    printf("\n");
}

int main(void)
{
    TERM t1 = {2, 12}, t2 = {3, 12}, t3 = {4, 17};
    POLY p1 = createPoly();

    p1 = attachPoly(p1, t1);
    p1 = attachPoly(p1, t2);
    p1 = attachPoly(p1, t3);

    printPoly(p1);
    return 0;
}
