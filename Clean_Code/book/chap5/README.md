# Chap 5 - Formatting



### Introduction

- You should choose a **set of simple rules** that govern the format of your code 
-  team should agree to a single set of formatting rules and all members should comply

- 챕터 5의 대부분의 내용은 '가독성'을 중점에 두었다.



#### Purpose of Formatting

-  Code formatting is about **communication**, and **communication is the professional developer’s first order of business** | 코드 포매팅은 커뮤니케이션!



#### Vertical Formatting

-  It appears to be possible to build significant systems out of files that are typically 200 lines long, with an upper limit of 500 | 200 - 500줄 사이로 제한해도 충분히 좋은 시스템 만든다. (very desirable)



####  Source file to be like a newspaper article

- name should be **simple** but **explanatory**
- **최상단은 추상화된 개념들, 디테일은 안으로 들어갈수록 수렴**



#### Vertical Openness Between Concepts

- should be separated from each other with blank lines | **메소드 엔터 쳐서 분리해라**
- 책에도 들여쓰기와 단락 분리가 있는 것 처럼, 코드도 읽기 쉽게끔 분리해서.



#### Vertical Density

- 의미상 관계 있는 variable 들 끼리는 vertically 가까운 위치에 두자.
- comments등으로 관계가 있는 대상들을 최대한 **분리하지 말자**.



**Vertical Distance**

- 의미상 관계 있는 개념을 vertically 가깝게 두자.
- **variable은 usage와 가까운 위치에 선언**하자. 
- Instance variable은 물론 class 맨 위에 선언한다 (자바). 수많은 메소드에서 갖다 쓸거기 때문에.. C++은 제일 밑이라고 한다.
- 서로 의존적인 함수는 가까이 두고, 호출하는 애를 위에 두고 그 안에 호출되는 애를 가까운 밑에 두자. (가독성이 좋아짐.)



**Conceptual Affinity**

- 좀 비슷한 기능을 하는 메소드 끼리는 붙여놓자. 비슷한 종류의 책을 책꽂이에 연달아 꽂아놓는것 처럼.



**Vertical Ordering**

- 메소드에서 Caller를 먼저 두고, Callee를 나중에 두자. **source code를 위에서 아래로 읽게 하는 가장 좋은 방법**.



#### Horizontal Formatting

- Programmers clearly prefer short lines. (작가는 120자 이하로 제한한다 함)



**Horizontal Alignment**

- 그렇게 유용하지 않음. instance variable 이 많아서 그렇게 하는것 같은데, instance variable이 많으면 객체로 빼던지 해야함.



**Indentation**

- oneline if while 최대한 쓰지 말자. 제대로 범위를 표현할 때 가독성이 높아진다.



#### Team Rules

- **good software system is composed of a set of documents that read nicely**

- **They need to have a consistent and smooth style.**

