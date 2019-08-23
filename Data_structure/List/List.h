#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{ // singly linked list
    
    int data;
    struct node_t * next;
    struct node_t * before;
} node;

typedef struct List_t{

    int size;
    node * front;
    node * rear;

} List;

List * createList(){
    List * newList = (List *)malloc(sizeof(List));
    if(newList == NULL){
        printf("Error occured when allocating memory at newList");
        return NULL;
    }

    newList->size = 0;
    newList->front = NULL;
    newList->rear = NULL;
}

node * createNode(int item){
    node * newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL){
        printf("Error occured when allocating memory at newNode");
        return NULL;
    }

    newNode->data = item;
    newNode->next = NULL;
    newNode->before = NULL;

    return newNode;
}

void append(List *list, int item){
    node * newItem = createNode(item);
    if(newItem == NULL) return;
    
    if(list->size == 0){
        list->front = list->rear = newItem;
        list->size++;
        return;
    }
     
    newItem->before = list->rear;
    list->rear->next = newItem;
    list->rear = newItem;
    list->size++;
};

int count(List *list){
    return list->size;
};

int index(List *list, int item){
    // return first index of item
    int ret = 0;
    node *Iterate = list->front;
    while(Iterate != NULL){
        if(Iterate->data == item) return ret;
        ret++;
        Iterate = Iterate->next;
    }
    return -1;
};

void insert(List *list, int idx, int item){
    if(list->size < idx){
        printf("Cannot insert item in %d since size of list is %d \n", idx, list->size);
        return;
    }

    node * insertNode = createNode(item);
    if(insertNode == NULL) return;

    if(idx == 0){ // 맨 앞
        list->front->before = insertNode;
        insertNode->next = list->front;
        list->front = insertNode;
    }
    else if (idx == list->size){ // 맨 뒤
        list->rear->next = insertNode;
        insertNode->before = list->rear;
        list->rear = insertNode;
    }
    else{
        node * insertPoint = list->front;
        for(int i=0;i<idx;i++){
            insertPoint = insertPoint->next;
        }
        insertPoint->before->next = insertNode;
        insertNode->before = insertPoint->before;
        insertPoint->before = insertNode;
        insertNode->next = insertPoint;
    }
    
    list->size++;
};

int pop(List *list){
    int ret = list->rear->data;
    node * temp = list->rear;
    list->rear->before->next = NULL;
    list->rear = list->rear->before;
    free(temp);
    return ret;
};

void removeItem(List *list,int item){
    node * it = list->front;
    while(it != NULL){ // time complexity is O(n) // you can use log(n) algorithm for this
        if(it->data == item) break;
        it = it->next;
    }
    if(it == NULL){
        printf("You cannot move item %d since there's no %d in list \n", item, item);
    }
    else{
        if(it->before != NULL && it->next != NULL){
            it->before->next = it->next;
            it->next->before = it->before;
            free(it);
        }
        else if(it->before == NULL){ // it is front
            list->front = it->next;
            it->next->before = NULL;
            free(it);
        }
        else if(it->next == NULL){ // it is rear
            list->rear = it->before;
            it->before->next = NULL;
            free(it);
        }
    }
};

void reverse(List *list){
    
    node *it = list->front;
    node *tmp;
    while(it != NULL){
        tmp = it->before;
        it->before = it->next;
        it->next = tmp;
        it = it->before;
    }

    tmp = list->front;
    list->front = list->rear;
    list->rear = tmp;
};

void clear(List *list){
    if(list->size = 0) return;
    node *bef, *after;
    bef = list->front;
    while(bef != NULL){
        after = bef->next;
        free(bef);
        bef = after;
    }
};

int get(List *list, int idx){
    if(list->size <= idx){
        printf("Cannot get item in %d since size of list is %d \n", idx, list->size);
        return -99999;
    }
    node * it = list->front;
    for(int i=0;i<idx;i++){
        it = it->next;
    }
    return it->data;
}

node *getIterator(List *list, int idx){
    if(list->size <= idx){
        printf("Cannot get item in %d since size of list is %d \n", idx, list->size);
        return NULL;
    }
    node * it = list->front;
    for(int i=0;i<idx;i++){
        it = it->next;
    }
    return it;
}

void Traverse(List *list){
    node * it = list->front;
    while(it != NULL){
        printf("%d ", it->data);
        it = it->next;
    }
    printf("\n");
}

void debug(List *list){
    node *it = list->front;
    while(it != NULL){
        if(it->next == NULL && it->before == NULL)
            printf("before : NULL, now : %d, next : NULL\n", it->before->data, it->data);
        else if(it->before == NULL)
            printf("before : NULL, now : %d, next : %d\n", it->data, it->next->data);
        else if(it->next == NULL)
            printf("before : %d, now : %d, next : NULL\n", it->before->data, it->data);
        else
            printf("before : %d, now : %d, next : %d\n", it->before->data, it->data, it->next->data);
        it = it->next;
    }
    printf("\n");
}