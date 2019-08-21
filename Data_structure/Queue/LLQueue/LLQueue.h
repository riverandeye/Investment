#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{

    int data;
    struct node_t * next;
} node;

typedef struct Queue_t{

    node *front;
    node *rear;
    int size;
} Queue;

Queue * CreateQueue(){
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    if(newQueue == NULL){
        printf("Problem Occured when allocating memory in CreateQueue - newQueue");
        return NULL;
    }
    
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
}

node * CreateNode(int data){
    node * newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL){
        printf("Problem Occured when allocating memory in CreateNode - newNode");
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void Enqueue(Queue * queue, int data){
    node * newnode = CreateNode(data);
    if(newnode == NULL) return;
    
    if(queue->rear == NULL){
        queue->front = newnode;
        queue->rear = newnode;
    }
    else{
        queue->rear->next = newnode;
        queue->rear = newnode;
    }

    queue->size++;
}

int Dequeue(Queue * queue){
    if(queue->size == 0){
        printf("There is No Item to dequeue in queue\n");
        return -44444;
    }

    int ret = queue->front->data;
    node* shouldfree = queue->front;

    if(queue->size == 1){
        queue->front = NULL;
        queue->rear = NULL;
    }
    else queue->front = queue->front->next;
    
    free(shouldfree);
    queue->size--;
    return ret;
}

void TraverseQueue(Queue *queue){
    node * point = queue->front;
    printf("size of queue : %d\n", queue->size);
    while(point != NULL){
        printf("%d ", point->data);
        point = point->next;
    }
    printf("\n");
}