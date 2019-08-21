#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue_t{

    int * data;
    int front;
    int rear;
    int size;
    int maxSize;

} Queue;

Queue * CreateQueue(int maxSize){
    Queue * newQueue = (Queue *)malloc(sizeof(Queue));
    if(newQueue==NULL){
        printf("Error raised while allocating memory in CreateQueue - newQueue");
        return NULL;
    }
    
    int * data = (int *)malloc(sizeof(int) * maxSize);
    if(data == NULL){
        printf("Error raised while allocating memory in CreateQueue - data");
        return NULL;
    }

    newQueue->data = data;
    newQueue->front = 0;
    newQueue->rear = 0;
    newQueue->size = 0;
    newQueue->maxSize = maxSize;

    return newQueue;
}

void Enqueue(Queue * queue, int value){
    if(queue->size == queue->maxSize){
        printf("Queue is full! so you cannot push");
        return;
    }
    queue->data[queue->rear++] = value;
    queue->rear %= queue->maxSize;
    queue->size++;
}

int Dequeue(Queue * queue){
    if(queue->size == 0){
        printf("Queue is Empty, so you cannot Pop from it\n");
        return -44444; // instead raise Error
    }

    int ret = queue->data[queue->front++];
    queue->front %= queue->maxSize;
    queue->size--;
    return ret;
}

void TraverseQueue(Queue *queue){
    printf("Size of this Queue : %d\n", queue->size);
    printf("Queue->front : %d, Queue->rear : %d\n", queue->front, queue->rear);
    if(queue->rear >= queue->front){
        for(int i = queue->front; i <queue->rear; i++){
            printf("%d ", queue->data[i]);
        }
    }
    else{
        for(int i = queue->front; i < queue->maxSize; i++){
            printf("%d ", queue->data[i]);
        }
        for(int i = 0; i < queue->rear; i++){
            printf("%d ", queue->data[i]);
        }
    }
    printf("\n");
}