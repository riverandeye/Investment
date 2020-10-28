#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct t_Heap {
  int * arr;
  int size;
  int maxSize;
} Heap;

Heap * createHeap();
void swap(int *i, int *j);
void push(Heap *heap, int data);
int pop(Heap *heap);

Heap * createHeap(int size){
  Heap *newHeap = (Heap *)malloc(sizeof(Heap));
  if(newHeap == NULL){
    printf("Failed to allocate memory on heap\n");
    return NULL;
  }

  int *arr = (int *)malloc(sizeof(int) * size + 1);
  if(arr == NULL){
    printf("Failed to allocate memory on array\n");
    return NULL;
  }

  newHeap->arr = arr;
  newHeap->maxSize = size;
  newHeap->size = 0;

  return newHeap;
};


void push(Heap *heap, int data){
  heap->arr[++heap->size] = data;

  int child = heap->size;
  int parent = child / 2;

  while(child > 1 && heap->arr[parent] < heap->arr[child]){ // 
    swap(&heap->arr[parent], &heap->arr[child]);
    child = parent;
    parent = child/2;
  }
};

int pop(Heap *heap){
  int ret = heap->arr[1];

  swap(&heap->arr[1], &heap->arr[heap->size]);
  heap->size--;

  int parent = 1;
  int child = parent * 2;
  if(child + 1 <= heap->size){
    child = (heap->arr[child] > heap->arr[child + 1]) ? child : child + 1;
  }

  while(child < heap->size && heap->arr[parent] < heap->arr[child]){
    swap(&heap->arr[parent], &heap->arr[child]);
    
    parent = child;
    child = child * 2;

    if(child + 1 <= heap->maxSize){
      child = (heap->arr[child] > heap->arr[child + 1]) ? child : child + 1;
    }
  }

  return ret;
}

void swap(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}