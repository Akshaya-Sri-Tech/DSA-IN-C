#include<stdio.h>
#define MIN_HEAP_CAPACITY 100
typedef struct {
    int arr[MIN_HEAP_CAPACITY];
    int size;
} MinHeap;

int isMinHeap(MinHeap *heap)
{
    for (int i = 0; i < heap->size / 2; i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap->size &&
            heap->arr[i] > heap->arr[left])
            return 0;

        if (right < heap->size &&
            heap->arr[i] > heap->arr[right])
            return 0;
    }

    return 1;
}

int main(){
    MinHeap h1={{1,2,3,4,5},5};
    MinHeap h2={{1,2,3,0,5},5};
    if(isMinHeap(&h1)) printf("\nYes");
    else printf("\nNo");
    if(isMinHeap(&h2)) printf("\nYes");
    else printf("\nNo");
}