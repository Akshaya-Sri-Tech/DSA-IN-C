
#ifndef MINHEAP_H
#define MINHEAP_H

#define MIN_HEAP_CAPACITY 100

typedef struct {
    int arr[MIN_HEAP_CAPACITY];
    int size;
} MinHeap;

void createMinHeap(MinHeap *heap);
int isMinHeapEmpty(MinHeap *heap);
int isMinHeapFull(MinHeap *heap);
int insertMinHeap(MinHeap *heap, int value);
int deleteMinHeapRoot(MinHeap *heap, int *deletedValue);
int peekMinHeap(MinHeap *heap, int *rootValue);
void displayMinHeap(MinHeap *heap);

#endif
