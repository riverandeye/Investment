#include "list.h"

int main(){

    List *myList = createList();

    // append , count
    for(int i=0;i<10;i++){
        append(myList, i);
        printf("size of List : %d \n", count(myList));
        Traverse(myList);
    }

    // reverse
    printf("\nreverse\n");

    reverse(myList);
    Traverse(myList);


    // index
    printf("index of number 8 : %d\n", index(myList, 8));

    // // insert
    insert(myList, 0, -100);
    Traverse(myList);

    for(int i=1;i<10;i += 2){
        insert(myList, i, i*100);
        Traverse(myList);
    }
    
    // removeItem
    printf("\n");
    removeItem(myList, -100);
    Traverse(myList);
    removeItem(myList, 1);
    Traverse(myList);
    removeItem(myList, 700);
    Traverse(myList);
    
    // pop
    for(int i=0;i<10;i++){
        printf("popped item : %d\n", pop(myList));
        Traverse(myList);
    }

    // reverse
    printf("\nreverse\n");

    reverse(myList);
    Traverse(myList);

    return 0;
}