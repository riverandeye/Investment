#include "LLQueue.h"

int main(){

    Queue *myQueue = CreateQueue();
    for(int i=0;i<10;i++){
        Enqueue(myQueue, i); 
        TraverseQueue(myQueue);
    }

    for(int i=0;i<10;i++){
        printf("Dequeued : %d \n", Dequeue(myQueue)); 
        TraverseQueue(myQueue);
    }

    for(int i=10;i<20;i++){
        Enqueue(myQueue, i); 
        TraverseQueue(myQueue);
    }

    for(int i=0;i<10;i++){
        Dequeue(myQueue); 
        TraverseQueue(myQueue);
    }

    return 0;
}