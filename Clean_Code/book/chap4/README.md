# Chap 4 - Comments

> 어떻게 해야 코드에 적절한 Comment를 남길 수 있을까요?



#### Introduction

- 주석은 **필요악이다.**

- 주석을 짰다는 건 **좋은 코드를 짜는 걸 실패했다는 뜻**



#### Comment를 달지 말고 좋은 코드를 짜라!

- 코드를 통해 설명할 수 있는 방법을 찾아라.
  - if 문의 조건에 대해 주석을 달지 말고, 메소드로 만든 후 메소드 이름을 통해 설명하라.
- 주석을 달았다고 나쁜 코드가 좋게 변하는건 아니다.



#### Good Comments

- Legal Comments

  - 저작권 등 법적인 이유로 작성한 것은 좋다.
- Informative Comments

  - comment를 통해 추론하기 어려운 information을 전달하는 것은 바람직하다.
    - 물론 추론 하기 쉽게 짜는것이 우선

- Explanation of Intent
  - 코드의 의도를 명시하고 싶을 때 
- Clarification
  - standard library 와 같이 alter 할 수 없는 코드의 경우 argument와 return value 를 명확히 해주고 싶을 때 
- TODO
  - 어떻게 코드를 바꿔야 하는지에 대해서 추가해준다. 어떻게 해야되고, 현재는 왜 안되고..



#### Bad Comments

- Redundant Comment -> 
- Mandated Comments -> vcs 없던 시절에나 하던거
- Position Marker -> 이름을 적절하게 작성하자.

