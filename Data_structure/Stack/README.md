# Stack

![](https://res.cloudinary.com/practicaldev/image/fetch/s--GS1k4iwx--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://thepracticaldev.s3.amazonaws.com/i/l8r4ic2gedi0j9obd7ix.jpg)

스택은 자료구조의 한 종류로, **나중에 입력한 정보를 가장 먼저 꺼낼 수 있는 구조**를 갖는 자료구조이다. 이러한 구조를 **LIFO (Last In First Out)** 라고 한다. 



### Stack의 연산

- **pop** - 스택에 쌓여있는 값들 중 가장 맨 위에 있는 정보를 뺀다.

- **push** - 스택의 맨 위에 정보를 넣는다.

- **peek** - 스택에 쌓여있는 값들 중 가장 맨 위에 있는 정보를 읽는다 (빼지 않음)

  - top 이라고도 한다.

- **isEmpty** - 스택이 비어있는지 아닌지 확인한다.

  > peek와 isEmpty는 예제 코드에 구현하지 않았지만, 직접 구현해보자. 



### Implementation

- LLStack (Linked List Stack)구현 설명
  - 입력된 value는 node 구조체에 저장한다.
  - Stack 구조체는 맨 위의 node의 주소를 가지고 있다.
  - 각 node는 바로 밑의 node의 주소를 가지고 있다.
  - 스택의 가장 밑 node의 next는 NULL 을 가르킨다.

- ArrayStack 구현 설명
  - Stack 구조체가 Array의 Pointer를 갖고 있다.
  - Stack의 Top은 Stack->size - 1 이다.
  - Array의 Stack->size에 해당하는 index에 push된 값을 넣는다.



### Others

- Linked List로 value를 구성하면 구현은 복잡하지만, Stack의 크기에 제한이 없다.
- Array로 value를 구성하면 구현은 간단하지만 Stack의 크기를 제한해야 한다.
  - 물론 Stack의 크기를 유동적으로 변경하게끔 하면 되지만, 그러한 경우 Stack의 이점을 살리기 힘들다.

