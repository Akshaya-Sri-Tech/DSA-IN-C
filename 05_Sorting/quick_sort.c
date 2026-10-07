#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low;

    for (int j = low + 1; j <= high; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }

    swap(&A[low], &A[i]);
    return i;
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = partition(A, low, high);
        quickSort(A, low, mid - 1);
        quickSort(A, mid + 1, high);
    }
}

int main()
{
    int arr[] = {4, 7, 9, 2, 5, 0, 1, 7, 3, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
