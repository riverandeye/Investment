#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t { // node 구조체 정의

    int val;
    struct node_t * next;

} node;

typedef struct stack_t { // Stack 구조체 정의

    struct node_t * front;
    int size;

} Stack;

Stack * CreateStack(){ 
    // Stack을 생성하고, 그 포인터를 리턴

    Stack * newStack = (Stack *)malloc(sizeof(Stack));

    if(newStack==NULL){
        printf("Fail when creating Stack pointer");
        return NULL;
    }

    newStack->front = NULL;
    newStack->size = 0;

    return newStack;
}

node * CreateNode(int val){
    // node를 생성하고, 그 포인터를 리턴

    node * newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL){
        printf("Fail when creating new node pointer");
        return NULL;
    }
    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

void stackPush(Stack * stack, int val){
    // stack과 값을 넣으면 해당 stack에 값을 넣어줌

    node * newNode = CreateNode(val);
    if(newNode == NULL) return;

    if(stack->front == NULL) stack->front = newNode;
    else{
        newNode->next = stack->front;
        stack->front = newNode;
    }

    stack->size++;
}

int stackPop(Stack *stack){
    int ret = stack->front->val;
    node * del = stack->front;

    stack->front = stack->front->next;
    free(del);
    stack->size--;
    return ret;
}

void PrintStackState(Stack *stack){
    node * nodePtr = stack->front;
    int i = stack->size;
    printf("Stack's total size : %d\n", i);
    while(nodePtr != NULL){
        printf("Stack's %dth floor value : %d\n", i, nodePtr->val);
        nodePtr = nodePtr->next;
        i--;
    }
}