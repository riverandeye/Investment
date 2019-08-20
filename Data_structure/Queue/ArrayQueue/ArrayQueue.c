#include "ArrayQueue.h"

int main(){

    Queue * myQueue = CreateQueue(12);
    for(int i=0;i<10;i++){
        Enqueue(myQueue, i);
        TraverseQueue(myQueue);
    }
    for(int i=0;i<10;i++){
        printf("%d\n", Dequeue(myQueue));
        TraverseQueue(myQueue);
    }
    printf("\n\n");
     for(int i=0;i<10;i++){
        Enqueue(myQueue, i);
        TraverseQueue(myQueue);
    }
    for(int i=0;i<10;i++){
        printf("%d\n", Dequeue(myQueue));
        TraverseQueue(myQueue);
    }
    
    return 0;
}