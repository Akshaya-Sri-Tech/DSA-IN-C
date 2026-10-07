#include <stdio.h>

void printPowerSet(int arr[], int n)
{
    for (int mask = 0; mask < (1 << n); mask++)
    {
        printf("{ ");
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                printf("%d ", arr[i]);
            }
        }
        printf("}\n");
    }
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the set elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("POWER SET:\n");
    printPowerSet(arr, n);
    return 0;
}
