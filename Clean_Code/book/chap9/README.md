# Chap 9 - Unit Test

> 어떻게 해야 제대로 된 테스트 코드를 작성할 수 있을까?



#### Three Laws of TDD

- You may not write production code until you have written a failing unit test.
  - 실패하는 단위 테스트를 작성할 때까지 실제 코드를 작성하지 않는다.
- You may not write more of a unit test than is sufficient to fail, and not compiling is failing.
  - 컴파일은 실패하지 않으면서 실행이 실패하는 정도로만 단위 테스트를 작성한다.
- You may not write more production code than is sufficient to pass the currently failing test
  - 현재 실패하는 테스트를 통과할 정도로만 실제 코드를 작성한다.



#### Keeping Tests Clean

- 코드의 깨끗함 >> 테스트의 성능
- 테스트 하나당 개념 하나를 테스트 할것!
  - **하나의 개념이 최소한의 assert를 담아야 하고, 테스트 함수 하나는 개념 하나만을 테스트하자.**



#### FIRST

- Fast - 빨리 돌아가는 테스트를 만들기.
- Independent - 테스트 간 독립적으로 구성. 
- Repeatable - 어떤 환경이든 돌아가는 테스트를 만들기.
- Self-Validating - 성공 혹은 실패만 명확히 드러나게끔 구성하기.
- Timely - 코드를 구현 한 후에 테스트를 작성하는 것은 늦는다. 테스트를 적절한 시점에 작성하자. 

