# Introduction - SOLID

<br>

디자인 패턴이란 - 소프트웨어 설계시 특정 맥락에서 자주 발생하는 문제들을 해결하는 해결책<br>

과거의 소프트웨어 개발 과정에서 발견된 노하우를 축적하여 이름을 붙여, 이후에 다시 쓰기 좋은 형태로 특정의 규약을 묶어서 정리한 것이다. 알고리즘과 같이 프로그램 코드로 바로 변환될 수 있는 형태는 아니지만, 특정한 상황에서 구조적인 문제를 해결하는 방식을 설명해 준다.<br>

모든 문제가 Design Pattern 내의 문제로 환원되지는 않겠지만, 관점을 가지면 도움이 될 것이다. <br>

### Essential of Design Pattern

- Pattern name : 패턴의 이름 
- Problem : 패턴을 적용해야 할 문제상황
- Solution :  문제에 대한 추상화된 해결첵을 제시
- Consequence : 패턴을 적용함으로써 발생하는 Trade-off

<br>

자료구조와 알고리즘도, 각각을 사용하는 문제 상황과 비용이 존재하듯이 디자인 패턴도 그러하다. 고로 사용하는 상황과 방법, 그에 따른 Tradeoff를 이해하는 것이 적합하다.<br>

무엇보다 Design Pattern은, class내에 encoded 되는 무언가가 아니라, 특정 context의 문제를 해결해 주는  **Object와 Class간의 소통 방식** 이라고 보는 것이 적합하다.<br>



# Solid Design Principle

- introduced by Robert C. Martin
- S : **Single responsibility principle** - 클래스당 소프트웨어 내의 오직 1개의 responsibility 만 부여
- O : **Open / Closed Principle**
- L : **Liskov substitution principle**
- I : **Interface segregation principle**
- D : **Dependency inversion principle**

<br>

### Single Responsibility Principle

- 각 Responsibility를 오직 하나의 클래스에만 지정하는 것.
- 물론 responsibility를 분리하는것은 어렵다. 그래서 잘 해야 한다.
- 클래스는 해당 Responsibility를 완전히 Encapsulate 해야한다.

<br>

### Open Closed Principle

- 소프트웨어의 개체는 확장에 대해 열려있고, 수정에 대해서는 닫혀 있어야 한다.
- 여러 모듈 중 하나를 수정하게 되면 다른 모듈을 줄줄이 수정해야 되게 된다.
- Open Closed Principle을 지키면, 기능을 추가하거나 변경해야 할 때 원래 코드를 변경하지 않아도 새로운 코드를 추가함으로써 기능의 추가나 변경이 가능하다.
- C++ 에서는 Template을 이용한 Generic Programming이 이를 지원한다.

<br>

### Liskov Substituion Principle

- 어떠한 경우에도 Derived Class는, Parent Class가 들어가는 곳에 무조건 대체될 수 있어야 한다.
- Derived Class에서 Parent Class의 method를 올바르게 Override 해야 한다. 
- 애초부터 자녀 클래스는 부모 클래스의 메서드를 손상시키면 안되고, 잘 보존해야 함.

<br>

### Interface Segregation Principle

- 클라이언트가 자신이 이용하지 않는 메서드에 의존하지 않아야 한다.
- 클라이언트는 오직 클라이언트가 필요한 메서드만 제공받아야 한다.
- 이 원칙을 지키기 위해서는 적절한 Abstraction이 필요하고, Single Interface에 많은 기능을 넣는 것을 피해야 한다.

<br>

### Dependency Inversion Principle

- 하이레벨 모듈이 로우레벨 모듈에 의존해서는 안된다.
- Abstraction이 detail에 의존해서는 안된다. detail이 Abstraction에 의존해야 한다.
- 프레임워크 개발의 기본이 됩니다

<br>

