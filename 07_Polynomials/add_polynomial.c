#include <stdio.h>

void getPoly(int p[], int count)
{
    printf("Enter %d coefficients and exponents in pairs:\n", count);
    for (int i = 1; i <= 2 * count; i += 2)
    {
        scanf("%d %d", &p[i], &p[i + 1]);
    }
}

void display(int p[])
{
    int size = 2 * p[0] + 1;
    for (int i = 1; i < size; i += 2)
    {
        printf("%dx^%d ", p[i], p[i + 1]);
    }
    printf("\n");
}

int main(void)
{
    int n1, n2;
    printf("Enter number of terms in first and second polynomial: ");
    scanf("%d %d", &n1, &n2);

    int p1[2 * n1 + 2], p2[2 * n2 + 2];
    p1[0] = n1;
    p2[0] = n2;

    getPoly(p1, n1);
    getPoly(p2, n2);

    printf("Polynomial 1: ");
    display(p1);
    printf("Polynomial 2: ");
    display(p2);

    int sum[100];
    int i = 1, j = 1, k = 1, count = 0;

    while (i <= 2 * p1[0] && j <= 2 * p2[0])
    {
        if (p1[i + 1] > p2[j + 1])
        {
            sum[k] = p1[i];
            sum[k + 1] = p1[i + 1];
            i += 2;
            k += 2;
            count++;
        }
        else if (p1[i + 1] < p2[j + 1])
        {
            sum[k] = p2[j];
            sum[k + 1] = p2[j + 1];
            j += 2;
            k += 2;
            count++;
        }
        else
        {
            if (p1[i] + p2[j] != 0)
            {
                sum[k] = p1[i] + p2[j];
                sum[k + 1] = p1[i + 1];
                k += 2;
                count++;
            }
            i += 2;
            j += 2;
        }
    }

    while (i <= 2 * p1[0])
    {
        sum[k] = p1[i];
        sum[k + 1] = p1[i + 1];
        i += 2;
        k += 2;
        count++;
    }

    while (j <= 2 * p2[0])
    {
        sum[k] = p2[j];
        sum[k + 1] = p2[j + 1];
        j += 2;
        k += 2;
        count++;
    }

    sum[0] = count;
    printf("The sum is: ");
    display(sum);

    return 0;
}
