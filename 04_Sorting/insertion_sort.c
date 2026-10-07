#include <stdio.h>

void insertionSortDec(int n, int A[])
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] < key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void insertionSortInc(int n, int A[])
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main(void)
{
    int arr[] = {4, 7, 9, 2, 5, 0, 1, 7, 3, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSortDec(n, arr);
    printf("Decreasing order: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSortInc(n, arr);
    printf("Increasing order: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
