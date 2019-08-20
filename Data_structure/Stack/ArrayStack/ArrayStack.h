#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct stack_t {

    int *data;
    int size;
    int maxSize;

} Stack;

Stack * CreateStack(int maxSize){
    Stack * newStack = (Stack *)malloc(sizeof(Stack));
    if(newStack == NULL){
        printf("Error raised while allocating memory in CreateStack - newStack");
        return NULL;
    }

    int *data = (int *)malloc(sizeof(int) * maxSize);
    if(data == NULL){
        printf("Error raised while allocating memory in CreateStack - data");
        return NULL;
    }
    
    newStack->data = data;
    newStack->size = 0;
    newStack->maxSize = maxSize;

    return newStack;
}

int stackPop(Stack * stack){
    if(stack->size == 0){
        printf("Stack is Empty! you cannot Pop!!");
        return -44444;
    }

    return stack->data[--stack->size];
}

void stackPush(Stack * stack, int data){
    if(stack->size == stack->maxSize){
        printf("Stack is full! you cannot push!!");
        return;
    }

    stack->data[stack->size++] = data;
}

void PrintStackState(Stack *stack){
    
    printf("Stack's total size : %d\n", stack->size);
    for(int i=stack->size - 1; i >= 0 ; i--){
        printf("Stack's %dth floor value : %d\n", i + 1, stack->data[i]);
    }
}