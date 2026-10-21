/*Write a C program to implement Insertion Sort, Merge Sort, Heap Sort, Quick Sort, 
and Counting Sort on an array of 1,000 randomly generated integers.
Count and compare the exact number of key comparisons performed by each sorting algorithm 
while displaying the first 11 sorted elements.*/
#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define MAX_VALUE N

long long c1 = 0, c2 = 0, c3 = 0, c4 = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* Insertion Sort */
void insertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i], j = i - 1;

        while (j >= 0)
        {
            c1++;
            if (A[j] <= key)
                break;

            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

/* Merge Sort */
void merge(int A[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int *T = malloc((r - l + 1) * sizeof(int));

    if (T == NULL)
        exit(1);

    while (i <= m && j <= r)
    {
        c2++;
        if (A[i] <= A[j])
            T[k++] = A[i++];
        else
            T[k++] = A[j++];
    }

    while (i <= m)
        T[k++] = A[i++];

    while (j <= r)
        T[k++] = A[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        A[i] = T[k];

    free(T);
}

void mergeSort(int A[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

/* Heap Sort */
void heapify(int A[], int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n)
    {
        c3++;
        if (A[l] > A[largest])
            largest = l;
    }

    if (r < n)
    {
        c3++;
        if (A[r] > A[largest])
            largest = r;
    }

    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&A[0], &A[i]);
        heapify(A, i, 0);
    }
}

/* Quick Sort */
int partition(int A[], int low, int high)
{
    int pivot = A[low], i = low;

    for (int j = low + 1; j <= high; j++)
    {
        c4++;
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
        int p = partition(A, low, high);
        quickSort(A, low, p - 1);
        quickSort(A, p + 1, high);
    }
}

/* Counting Sort: count key-frequency operations */
void countingSort(int A[], int n, int B[])
{
    int count[MAX_VALUE + 1] = {0};
    

    for (int i = 0; i < n; i++)
        count[A[i]]++;

    for (int i = 1; i <= MAX_VALUE; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
        B[--count[A[i]]] = A[i];
}

/* Display first 11 elements */
void display(char *name, int A[])
{
    printf("\n%s: ", name);

    for (int i = 0; i < 11 && i < N; i++)
        printf("%d ", A[i]);

    printf("\n");
}

int main(void)
{
    int A[N], A1[N], A2[N], A3[N], A4[N], A5[N];
    int B[N];

    for (int i = 0; i < N; i++)
        A[i] = rand() % (MAX_VALUE + 1);

    for (int i = 0; i < N; i++)
    {
        A1[i] = A[i];
        A2[i] = A[i];
        A3[i] = A[i];
        A4[i] = A[i];
        A5[i] = A[i];
    }

    insertionSort(A1, N);
    mergeSort(A2, 0, N - 1);
    heapSort(A3, N);
    quickSort(A4, 0, N - 1);

    countingSort(A5, N, B);

    display("INSERTION SORT", A1);
    display("MERGE SORT", A2);
    display("HEAP SORT", A3);
    display("QUICK SORT", A4);
    display("COUNTING SORT", B);

    printf("\n===== COMPARISON COUNTS =====\n");
    printf("Insertion Sort : %lld\n", c1);
    printf("Merge Sort     : %lld\n", c2);
    printf("Heap Sort      : %lld\n", c3);
    printf("Quick Sort     : %lld\n", c4);


    return 0;
}
