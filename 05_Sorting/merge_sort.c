#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int *temp = (int *)malloc((right - left + 1) * sizeof(int));

    while (i <= mid && j <= right)
    {
        if (A[i] < A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = A[i++];
    }
    while (j <= right)
    {
        temp[k++] = A[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++)
    {
        A[i] = temp[k];
    }

    free(temp);
}

void mergeSort(int A[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

int main(void)
{
    int arr[] = {4, 7, 9, 2, 5, 0, 1, 7, 3, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
