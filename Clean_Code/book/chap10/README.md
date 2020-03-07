# Chap 10 - Classes

> 클래스를 어떻게 구성해야 할까요?



#### Class Organization

- public static constant (or read only)
- private static
- private instance
- public functions
- private utility methods after the public function that calls it

저 순서대로 작성을 하면 클래스의 역할이 더 잘 전달된다. 신문 읽듯이..



#### Encapsulation

-  Loosening encapsulation is always a last resort. 
  - 캡슐화를 내려놓는건 최후의 보루..



#### Class Should Be Small

- Class의 Measure는 **Responsibility**

-  naming is probably the first way of helping determine class size
  - Ambiguous Name -> Too Many Responsibility
- We should also be able to write a brief description of the class in about 25 words
  - without using the words “if,” “and,” “or,” or “but.”



####  Single Responsibility Principle

- 하나의 책임만 가지자
  - 모듈을 변경할 이유를 단 한가지만 가지게 하자.



#### Cohesion

- 클래스가 소유한 instance variable을 클래스가 소유한 method가 하나 이상 사용해야 한다.
  - 사용하는 instance variable이 많을수록 응집성이 높다.



#### Maintaining Cohesion Results in Many Small Classes - 중요

- 하나의 클래스에서 **특정 메소드와 특정 변수간의 응집성**이 유독 높게 되면, 그녀석들을 따로 독자적인 클래스로 뺴도 된다.



#### Isolating from Change

- Interface나 Abstract Class를 dependency로 가지는 것이 변화에 더욱 flexible 하다.
  - 