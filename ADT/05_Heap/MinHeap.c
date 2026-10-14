
#include <stdio.h>
#include "minheap.h"

void createMinHeap(MinHeap *heap) {
    heap->size = 0;
}

int isMinHeapEmpty(MinHeap *heap) {
    return heap->size == 0;
}

int isMinHeapFull(MinHeap *heap) {
    return heap->size == MIN_HEAP_CAPACITY;
}

int insertMinHeap(MinHeap *heap, int value) {
    if (isMinHeapFull(heap))
        return 0;

    int i = heap->size++;
    while (i > 0 && value < heap->arr[(i - 1) / 2]) {
        heap->arr[i] = heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->arr[i] = value;
    return 1;
}

int deleteMinHeapRoot(MinHeap *heap, int *deletedValue) {
    if (isMinHeapEmpty(heap))
        return 0;

    *deletedValue = heap->arr[0];
    int last = heap->arr[--heap->size];
    int i = 0;

    while (2 * i + 1 < heap->size) {
        int child = 2 * i + 1;
        if (child + 1 < heap->size &&
            heap->arr[child + 1] < heap->arr[child])
            child++;

        if (last <= heap->arr[child])
            break;

        heap->arr[i] = heap->arr[child];
        i = child;
    }

    if (heap->size > 0)
        heap->arr[i] = last;

    return 1;
}

int peekMinHeap(MinHeap *heap, int *rootValue) {
    if (isMinHeapEmpty(heap))
        return 0;

    *rootValue = heap->arr[0];
    return 1;
}

void displayMinHeap(MinHeap *heap) {
    if (isMinHeapEmpty(heap)) {
        printf("Min-Heap is empty\n");
        return;
    }

    printf("Min-Heap: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);

    printf("\n");
}
