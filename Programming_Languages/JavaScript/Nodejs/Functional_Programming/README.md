# Functional Programming 

### What is Functional Programming

- 함수형 프로그래밍이란 
  - Pure function**으로 소프트웨어를 작성함으로써 **shared state**, **mutable data** 등의 side effect를 최소화하는 것.
  - Functional Programming은 **declarative** 하고, application state는 pure function을 통해 변경된다.
  - OOP는 Imperative하다 (어플리케이션의 상태가 공유되며 메서드와 함께 배치됨)

- 함수형 프로그래밍의 장점
  - 간결하고, 예측 가능하다.

#### Definitions

- Pure function
  - 같은 입력에 대해 항상 같은 출력을 반환하는 함수
  - 그런 것 말고는 아무것도 안하는 함수 (부수적인 작용이 없는 함수)
  - referential transparency (결과 값으로 함수 호출을 대신할 수 있음)
- Function composition - 함수 합성 (합성 함수를 만드는 것)
  - 명령형(Imperative) 흐름 제어보다는 합성 함수(Function composition) 사용하라
- Avoid shared state
  - Shared state - 공유 범위에 있는 변수, 객체, 또는 범위 내에 전달되는 객체의 속성
  - 함수형 프로그래밍은 immutable과 pure function으로 새로운 데이터를 만듬.
  - 공유 상태의 함수는, 함수 호출 순서 변경시 작동하는 함수의 양상이 달라지며 호출에 실패할 수 있음. (race condition)
  - 공유 상태의 함수는, 공유 변수에 의해 의도치 않게 값이 변경될 수 있다.
  - 이와 같은 잠재적 버그를 함수형 프로그래밍을 통해 제거할 수 있다.
- Avoid mutating state
  - Immutable을 이용하여 데이터 흐름을 보존한다.
- Avoid side effect
  - Side effect엔 이러한 것들이 있다.
    - 외부 변수 및 객체 속성 수정
    - 콘솔 로깅
    - 화면에 쓰기 작업
    - 파일 쓰기 작업
    - 네트워크 쓰기 작업
    - 외부 프로세스를 트리거
    - Side effect가 있는 함수 호출
  - 이걸 잘 피해야 프로그램을 더 쉽게 이해하고 테스트 할 수 있음.

## JavaScript 함수 사용 기본

### 함수 선언식 VS 함수 표현식

- 함수 선언식 (Function Declaration)

  ```javascript
  function helloworld(){
      return "helloworld";
  }
  ```

- 함수 표현식 (Function Expression)

  ```javascript
  var helloworld = function(){
      return "helloworld";
  }
  ```

- 둘의 차이는 [**Hoisting**](https://github.com/riverandeye/Investment/Programming_Languages/JavaScript/Functional_Programming/Hoisting)에서 비롯된다
  - 호이스팅은, 선언된 변수를 해당 scope의 최상위로 끌어올리는 것을 의미한다.
  - let, const로 선언된 변수에 대해서는 호이스팅하지 않는다.
  - 함수는 Declaration만 호이스팅됨과 동시에 Initialize 되고, Expression은 호이스팅되지 않는다.
  - 그래서 Declaration한 함수는 Declaration 전에 사용할 수 있다.

#### 함수 표현식 장점

- [클로져](https://github.com/riverandeye/Investment/Programming_Languages/JavaScript/Functional_Programming/Closure)로 사용할 수 있다.
- 콜백으로 사용할 수 있다(다른 함수의 인자로 넘길 수 있음)