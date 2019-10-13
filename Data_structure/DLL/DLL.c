#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define true 1
#define false 0

typedef int ElementType;

struct Node {
  ElementType Element;
  struct Node *Next;
  struct Node *Previous;
};
typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreateList();
int IsEmpty(List L);
int IsLast(List L);
Position Find(ElementType X,List L);
int Delete(ElementType X, List L);
Position Insert(ElementType X, List L, Position P);
Position GetNode(List L,int idx);
void SwapElement(List L,Position P1,Position P2);
void SwapNode(List L,Position P1,Position P2);
void Reverse(List L);
void DeleteList(List L);
Position Last(List L);
int ListLen(List L);
void PrintList(List L);
void FetalError(const char * msg);

void performance_test() {
  int i, j;
  clock_t t1, t2;
  double elapse, reference;

  int N_REPEAT = 100;
  List L;

  // reference time
  t1 = clock();
  for (i = 0; i < 100000; i++) {
    int * p = (int * ) malloc(sizeof(int) * 1024);
    for (j = 0; j < 1024; j++) p[j] = rand();
    free(p);
  }
  t2 = clock();
  reference = (double)(t2 - t1) / CLOCKS_PER_SEC;
  printf("The reference time is %.4f sec\n", reference);

  // running time 
  srand(0);
  t1 = clock();
  for (i = 0; i < N_REPEAT; i++) {
    int LIST_SIZE, idx1, idx2;
    List L, P, P1, P2;
    ElementType X;
    LIST_SIZE = (rand() % 10000 + 1);
    L = CreateList();

    for (j = 0; j < LIST_SIZE; j++){
        Insert(rand(), L, L);
    };

    for (j = 0; j < 1000; j++) {
      idx1 = rand() % LIST_SIZE + 1;
      idx2 = rand() % LIST_SIZE + 1;
      P1 = GetNode(L, idx1);
      P2 = GetNode(L, idx2);
      if (P1->Element == P2 -> Element) continue;

      X = P1->Element;
      Delete(X, L);
      Insert(X, L, P2);
    }

    for (j = 0; j < 1000; j++) {
      idx1 = rand() % LIST_SIZE + 1;
      idx2 = rand() % LIST_SIZE + 1;
      P1 = GetNode(L, idx1);
      P2 = GetNode(L, idx2);
      SwapNode(L, P1, P2);
    }

    DeleteList(L);
  }
  t2 = clock();
  elapse = (double)(t2 - t1) / CLOCKS_PER_SEC;
  printf("The elapse time is %.4f sec (%.4f x ref)\n",
    elapse, elapse / reference);
}

int main(int argc, char * argv[]) {
    int i;
    ElementType X;
    List L;
    Position P, P1, P2;

    srand(60); // set a random seed

    // creat an empty list
    printf("**(TASK 1) Create an empty list\n");
    L = CreateList();
    PrintList(L);

    // Insert at the beginning
    printf("**(TASK 2) insert 5 random numbers at the beginning\n");
    for (i = 0; i < 5; i++) {
      Insert(rand(), L, L);
      PrintList(L);
    }
    P = GetNode(L, 5);
    printf("The Element of 5th Node is %d\n", P-> Element);

    // Insert at the end
    printf("**(TASK 3) insert a random number at the end\n");
    P = Last(L);
    Insert(rand(), L, P);
    PrintList(L);

    // Find
    printf("**(TASK 4) find the second element\n");
    X = L->Next->Next->Element;
    P = Find(X, L);
    printf("%d is %s\n", X, (P) ? "found" : "not found");

    // insertion in the middle (현재 P=2번째 가르킴, P다음에 넣어) 
    printf("**(TASK 5) insert a random number in the middle\n");
    Insert(rand(), L, P);
    PrintList(L);

    // delete
    printf("**(TASK 6) delete %d from the list\n", X);
    Delete(X, L); //X 현재 2번째 element를 지워 
    PrintList(L);
    printf("**(TASK 7) find %d in the list\n", X);
    P = Find(X, L); 
    printf("%d is %s\n", X, (P) ? "found" : "not found");

    // swap
    printf("**(TASK 8) swap the 2nd and 4th value\n", X);
    P1 = GetNode(L, 2);
    P2 = GetNode(L, 4);
    SwapElement(L, P1, P2);
    PrintList(L);
    printf("**(TASK 9) swap the 3rd and 4th value\n", X);
    P1 = GetNode(L, 4);
    P2 = GetNode(L, 3);
    SwapNode(L, P1, P2);
    PrintList(L);

    // reverse
    printf("**(TASK 10) reverse the list\n");
    Reverse(L);
    PrintList(L);
    printf("**(TASK 11) add an element and reverse\n");
    Insert(rand(), L, Last(L));
    PrintList(L);
    Reverse(L);
    PrintList(L);

    // // delete the whole list
    printf("**(TASK 12) delete the whole list\n", X);
    DeleteList(L);
    PrintList(L);

    // // running time test
    printf("**(TASK 13) running time test\n", X);
    performance_test();

    return 0;
}


List CreateList(){
    List L = (List) malloc (sizeof(struct Node));
    if( L == NULL ) FetalError("Out Of Memory\n");
    L->Element = 0;
    L->Next = NULL;
    return L;
};

int IsEmpty(List L){
    if(L->Next == NULL) return true;
    else return false;
};

int IsLast(Position L){
    if(L->Previous != NULL && L->Next == NULL) return true;
    else return false;
};

Position Find(ElementType X, List L){
    Position P = L->Next;
    while(P != NULL && P->Element != X) P = P->Next;
    return P;
};

int Delete(ElementType X, List L){
    if(IsEmpty(L)) FetalError("List is Empty! You cannot delete item from Empty list!\n");

    Position P = Find(X,L);
    if(P == NULL) FetalError("Given position is not in the List\n");
    if(IsLast(P)){
        P->Previous->Next = NULL;
    }
    else {
        P->Previous->Next = P->Next;
        P->Next->Previous = P->Previous;
    }

    free(P);
    return true;
};

PtrToNode CreateNode(ElementType X){
    PtrToNode ret = (PtrToNode)malloc(sizeof(struct Node));
    if(ret == NULL) FetalError("Out of Memory");
    ret->Element = X;
    ret->Next = NULL;
    ret->Previous = NULL;

    return ret;
}

Position Insert(ElementType X, List L, Position P){
    Position tmp = CreateNode(X);

    if(!IsLast(P)){
        P->Next->Previous = tmp;
        tmp->Next = P->Next;
    }

    P->Next = tmp;
    tmp->Previous = P;

    return tmp;
};

Position GetNode(List L, int idx){
    if(IsEmpty(L)) FetalError("List is Empty!\n");

    Position P = L;
    int pos = 0;
    while(P != NULL){
        if(pos == idx) return P;
        P = P->Next;
        pos++;
    }

    FetalError("List is shorter than given index!\n");
};

void SwapElement(List L, Position P1, Position P2){
    
    ElementType tmp;
    tmp = P1->Element;
    P1->Element = P2->Element;
    P2->Element = tmp;
};

void SwapNode(List L, Position P1, Position P2){
    if(P1->Element == P2->Element) return;
    if(Find(P1->Element, L) == NULL) FetalError("First Position is not on the List\n");
    if(Find(P2->Element, L) == NULL) FetalError("Second Position is not on the List\n");
    Position dummy;
    
    P1->Previous->Next = P2;
    P2->Previous->Next = P1;

    dummy = P1->Previous;
    P1->Previous = P2->Previous;
    P2->Previous = dummy;

    if(IsLast(P1)){
        P2->Next->Previous = P1;
        P1->Next = P2->Next;
        P2->Next = NULL;
    }
    else if(IsLast(P2)){
        P1->Next->Previous = P2;
        P2->Next = P1->Next;
        P1->Next = NULL;
    }
    else{
        P1->Next->Previous = P2;
        P2->Next->Previous = P1;

        dummy = P1->Next;
        P1->Next = P2->Next;
        P2->Next = dummy;
    }
};

void Reverse(List L){
    if(IsEmpty(L)) return;

    Position P = L->Next;
    int size = ListLen(L), idx;

    ElementType *data = (ElementType *)malloc(sizeof(ElementType) * size);
    if(data == NULL) FetalError("Memory Out of Bound\n");

    for(idx = 0; idx < size; idx++){
        data[idx] = P->Element;
        P = P->Next;
    }

    P = Last(L);
    for(idx = 0; idx < size; idx++){
        P->Element = data[idx];
        P = P->Previous;
    }

    free(data);
};

void DeleteList(List L){
    Position tmp1 = L->Next, tmp2 = tmp1->Next;  
    while(true){
        free(tmp1);
        if(tmp2->Next == NULL){
            free(tmp2);
            break;
        }
        else{
            tmp1 = tmp2;
            tmp2 = tmp2->Next;
        }
    };
    L->Next = NULL;
};

Position Last(List L){
    Position P = L->Next;
    while(P->Next != NULL) P = P->Next;
    return P;
};

int ListLen(List L){
    Position P = L->Next;
    int count = 0;
    while(P != NULL){
        count++;
        P = P->Next;
    }
    return count;
};

void PrintList(List L){
    Position tmp = L->Next;
    printf("%d: ", ListLen(L));
    while(tmp != NULL){
        printf("%d <-> ", tmp->Element);
        tmp = tmp->Next;
    }
    printf("NULL\n");
};


void FetalError(const char * msg) {
  printf(msg);
  exit(-1);
}
