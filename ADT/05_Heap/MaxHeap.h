#ifndef MAXHEAP_H
#define MAXHEAP_H

#define MAX_HEAP_CAPACITY 100

typedef struct {
    int arr[MAX_HEAP_CAPACITY];
    int size;
} MaxHeap;

void createMaxHeap(MaxHeap *heap);
int isMaxHeapEmpty(MaxHeap *heap);
int isMaxHeapFull(MaxHeap *heap);
int insertMaxHeap(MaxHeap *heap, int value);
int deleteMaxHeapRoot(MaxHeap *heap, int *deletedValue);
int peekMaxHeap(MaxHeap *heap, int *rootValue);
void displayMaxHeap(MaxHeap *heap);

#endif
