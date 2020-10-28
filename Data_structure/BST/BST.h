#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int Element; // for set type easily

typedef int bool;
#define true 1
#define false 0

typedef struct node_t {

    Element data;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;

} node;

typedef struct BST_t {

    node *root;
    int *size;

} BST;

BST * createBST(){
    BST * bst = (BST *)malloc(sizeof(BST));
    if(bst==NULL){
        printf("Error occured while malloc Memory on BST");
        return NULL;
    }

    bst->root = NULL;
    bst->size = 0;

    return bst;
}

node * createNode(Element data){
    node * newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL){
        printf("Error occured while malloc Memory on newNode");
        return NULL;
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

bool findplace(node *now, Element data){
    if(now->data == data){
        // 중복된 key를 입력할 수 있게 하려면, 구조체에 count를 두는 방법이 더 효율적입니다. 
        printf("You cannot push %d since it already exists in the tree\n",data);
        return false;
    }

    else if(now->data < data){
        if(now->right == NULL) {
            now->right = createNode(data);
            now->right->parent = now;
            return true;
        }
        else return findplace(now->right, data);
    }
    else{ 
        if(now->left == NULL){
            now->left = createNode(data);
            now->left->parent = now;
            return true;
        } 
        else return findplace(now->left, data);
    }
}

void insert(BST *bst, Element data){
    if(bst->size == 0) bst->root = createNode(data);
    else if(!findplace(bst->root, data)) return;

    bst->size++;
}

void _preorder(node *now){
    if(now==NULL) return;

    printf("%d ", now->data);
    _preorder(now->left);
    _preorder(now->right);
}

void _inorder(node *now){
    if(now==NULL) return;

    _inorder(now->left);
    printf("%d ", now->data);
    _inorder(now->right);
}

void _postorder(node *now){
    if(now==NULL) return;

    _postorder(now->left);
    _postorder(now->right);
    printf("%d ", now->data);
}

void preorder(BST *bst){if(bst->root==NULL)return;_preorder(bst->root);printf("\n");}
void inorder(BST *bst){if(bst->root==NULL)return;_inorder(bst->root);printf("\n");}
void postorder(BST *bst){if(bst->root==NULL)return;_postorder(bst->root);printf("\n");}

node * getMax(node *now){
    if(now->right == NULL) return now;
    else return getMax(now->right);
}

node * getMin(node *now){
    if(now->left == NULL) return now;
    else return getMin(now->left);
}

Element findmax(BST *bst){return getMax(bst->root)->data;}
Element findmin(BST *bst){return getMin(bst->root)->data;}

void freeallnode(node *now){
    if(now==NULL) return;

    freeallnode(now->left);
    freeallnode(now->right);
    free(now);
}

void clear(BST *bst){
    freeallnode(bst->root);
    bst->root = NULL;
    bst->size = 0;
}

node *search(node *now, Element data){
    if(now->data == data) return now;
    else if(now->data < data){
        if(now->right == NULL) return NULL;
        else return search(now->right, data);
    }
    else{
        if(now->left == NULL) return NULL;
        else return search(now->left, data);
    }
}

void delete(BST *bst, Element data){
    node *target = search(bst->root, data);
    if(target == NULL){
        printf("There's no %d in your bst", data);
        return;
    }

    node *leftchild = target->left;
    node *rightchild = target->right;
    
    if(rightchild != NULL){ // target has a rightchild
        node *minofrightchild = getMin(rightchild);

        target->data = minofrightchild->data;
        if(minofrightchild == target->right){
            if(minofrightchild->right != NULL){
                target->right = minofrightchild->right;
                target->right->parent = target;
            }
            else target->right = NULL;
        }
        else{
            if(minofrightchild->right != NULL){
                minofrightchild->parent->left = minofrightchild->right;
                minofrightchild->right->parent = minofrightchild->parent;
            }
            else minofrightchild->parent->left = NULL;
        }
        free(minofrightchild);
    }
    else if(leftchild != NULL){ // target has only a leftchild
        leftchild->parent = target->parent;
        if(target->data < target->parent->data) target->parent->left = target->left;
        else target->parent->right = target->left;
        free(target);
    }
    else{ // target has no child
        if(target->parent != NULL){
            if(target->data < target->parent->data) target->parent->left = NULL;
            else target->parent->right = NULL;
        }
        free(target);
    }

    bst->size--;
    if(bst->size == 0) bst->root = NULL;
}