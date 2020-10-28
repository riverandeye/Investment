#include "heap.h"

int main()
{
  Heap *myHeap = createHeap(100);

  int data[7] = {100, 47, 13, 5, 10, 66, 35};

  for (int i = 0; i < 7; i++)
    push(myHeap, data[i]);

  for (int i = 0; i < 7; i++)
    printf("%d ", pop(myHeap));

  return 0;
}