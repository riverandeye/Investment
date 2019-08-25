#include "BST.h"

int array[20] = {25,15,10,4,12,22,18,24,50,35,70,31,44,66,90};
// link or data : https://www.google.com/url?sa=i&source=images&cd=&ved=2ahUKEwjEuo2H0J3kAhUDH3AKHSwwBkcQjRx6BAgBEAQ&url=%2Furl%3Fsa%3Di%26source%3Dimages%26cd%3D%26ved%3D%26url%3Dhttps%253A%252F%252Fwww.geeksforgeeks.org%252Ftree-traversals-inorder-preorder-and-postorder%252F%26psig%3DAOvVaw254b9YeFG9sASXqByKvkJZ%26ust%3D1566808855734191&psig=AOvVaw254b9YeFG9sASXqByKvkJZ&ust=1566808855734191
int main(){
    BST * myBST = createBST();

    // insert
    for(int i=0;i<15;i++) insert(myBST, array[i]);
    
    // preorder, inorder, postorder traverse
    inorder(myBST);
    preorder(myBST);
    postorder(myBST);

    // findmin, findmax
    printf("Minimum value of this Tree : %d\n", findmin(myBST));
    printf("Maximum value of this Tree : %d\n", findmax(myBST));

    // delete
    for(int i=14;i>=0;i--){
        delete(myBST, array[i]);
        inorder(myBST);
    }

    // clear
    clear(myBST);
    postorder(myBST);
    return 0;
}
