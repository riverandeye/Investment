# Queue



Queue는 자료구조 중의 하나로, **먼저 입력되는 정보가 먼저 나오는** 형태의 구조를 지닌다. 이를 First in First Out 이라 하여 FIFO 라 부른다.



![](https://qph.fs.quoracdn.net/main-qimg-ee73af949fa0381c54280fbc5f385b3d.webp)

### Queue의 연산

- Enqueue : Queue의 front에 값을 넣는 것을 의미함.
- Dequeue : Queue의 Back(rear)에서 값을 빼는 것을 의미함.



### Queue 구현 설명

- ArrayQueue
  - 처음 Queue를 선언할 때 최대 Size를 주게끔 선언
  - Circular Queue 형식으로 구성, index가 maxSize를 초과할 시 나머지 연산으로 index가 초기화됨.
- LLQueue (Linked List Queue)
  - 

