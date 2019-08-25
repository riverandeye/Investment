# BST (Binary Search Tree)

BST는 자료구조 중 하나로, Tree 자료 구조이면서, node의 left child가 더 작고, right child가 항상 더 큰 구조를 갖는 tree이다.

이 자료구조는 여러가지 이점이 있다.

1. **입력, 삭제, 이진 탐색의 시간복잡도는 O(logn)이다.**
   - Search에 대해 시간복잡도가 다른 자료구조보다 빠르다.
2. 해당 구조 자체가 정렬이 되어있는 상태이다. 



### Methods

- insert - 해당 BST에 특정 값을 입력
- delete - 해당 BST에서 특정 노드를 삭제
- traversal - 해당 BST의 node를 특정 규칙으로 순회함
  - preorder - **node**, left, right 순으로 node를 **먼저(pre)** 순회 
  - inorder - left,**node**, right 순으로 node를 **중간에(in)**순회
  - postorder - left, right, **node** 순으로 node를 **나중에(post)**순회
- getMax - 해당 BST 중 최대값을 구함
- getMin - 해당 BST 중 최소값을 구함
- clear - BST를 삭제함.



### Demonstration

- BST.c 의 Test data는 밑의 이미지를 참고

![](https://www.geeksforgeeks.org/wp-content/uploads/Preorder-from-Inorder-and-Postorder-traversals.jpg)