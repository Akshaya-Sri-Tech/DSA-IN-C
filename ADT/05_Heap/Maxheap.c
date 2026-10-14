#include <stdio.h>
#include "maxheap.h"

void createMaxHeap(MaxHeap *heap) {
    heap->size = 0;
}

int isMaxHeapEmpty(MaxHeap *heap) {
    return heap->size == 0;
}

int isMaxHeapFull(MaxHeap *heap) {
    return heap->size == MAX_HEAP_CAPACITY;
}

int insertMaxHeap(MaxHeap *heap, int value) {
    if (isMaxHeapFull(heap))
        return 0;

    int i = heap->size++;
    while (i > 0 && value > heap->arr[(i - 1) / 2]) {
        heap->arr[i] = heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->arr[i] = value;
    return 1;
}

int deleteMaxHeapRoot(MaxHeap *heap, int *deletedValue) {
    if (isMaxHeapEmpty(heap))
        return 0;

    *deletedValue = heap->arr[0];
    int last = heap->arr[--heap->size];
    int i = 0;

    while (2 * i + 1 < heap->size) {
        int child = 2 * i + 1;
        if (child + 1 < heap->size &&
            heap->arr[child + 1] > heap->arr[child])
            child++;

        if (last >= heap->arr[child])
            break;

        heap->arr[i] = heap->arr[child];
        i = child;
    }

    if (heap->size > 0)
        heap->arr[i] = last;

    return 1;
}

int peekMaxHeap(MaxHeap *heap, int *rootValue) {
    if (isMaxHeapEmpty(heap))
        return 0;

    *rootValue = heap->arr[0];
    return 1;
}

void displayMaxHeap(MaxHeap *heap) {
    if (isMaxHeapEmpty(heap)) {
        printf("Max-Heap is empty\n");
        return;
    }

    printf("Max-Heap: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);

    printf("\n");
}
