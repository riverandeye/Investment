# Chap 2

> 클린코드 챕터 2



### Use Intention-Revealing Names

- The problem isn’t the simplicity of the code but the **implicity** of the code
- The code implicitly requires that we know the answers to questions such as: 
  1. What kinds of things are in theList? | 추론 가능한 변수명
  2. What is the significance of the zeroth subscript of an item in theList?  | 변수명 지정
  3. What is the significance of the value 4? | 매직 넘버 상수화
  4. How would I use the list being returned? | 함수명 지정



### Avoid Disinformation

- Programmers must avoid leaving false clues that **obscure the meaning of code**.

![image-20200213000036805](images/image-20200213000036805.png)

- developer is likely to pick an object by name **without seeing your copious comments or even the list of methods** supplied by that class



### Make Meaningful Distinction

- It is not sufficient to add number series or noise words
  
  -  they provide no clue to the **author’s intention**
-  **Info and Data are indistinct noise words like a, an, and the.**
  -  there is nothing wrong with using prefix conventions like a and the so long as they make a meaningful distinction
  - The problem comes in when you decide to call a variable theZork because you already have another variable named zork | 단순히 zork가 이미 있다고 해서 theZork 이런건 하지말라.

- Use Pronounceable Name
  
- This matters because **programming is a social activity**
  
- Use Searchable Names
  
  - single letter는 for문 돌리는 j 정도만 허용되게 (index 용)
- Avoid Encoding
  - 변수명에 type을 굳이 encode 할 필요 없다. 요즘 언어들이 타입 인코딩이 좋아서..
  - 멤버 변수임을 명시할 필요도 없다. 
  
  - 근데 인터페이스는 I를 붙여주는게 좋다. Class에 derived하고 명시하는것보다 나음.

- Avoid Mental Mapping
  - generic한 의미를 전달하는 것이 중요하다. 

- Class 이름은 모호하지 않은 명사로!

- Method 가 오버로딩 되는 경우엔 팩토리 메소드로! (팩토리 패턴 아님)

  ```java
  Complex fulcrumPoint = Complex.FromRealNumber(23.0);
  ```

  메서드 안에 생성자를 은닉하자. 정적 팩토리 메소드는 일단 이름이 있으니까 구분이 쉽고, 이렇게 하면 싱글턴 패턴도 사용할 수 있어서 좋다. static 변수로 자기 자신을 가지고 있으면 되기 때문. 이 내용은 effective java에 더 자세히 설명되어 있다. 나중에 그것도 정리해 봐야지.

- **Pick One Word per Concept**

  - **A consistent lexicon is a great boon to the programmers who must use your code.** 
  - 이게 진짜 잘 지켜지지 않는 것 중 하나인 것 같다. fetch, retrieve, get 이거 진짜다 ㅋㅋ
  - add 라는 단어도 조심해서 써야한다. add의 의미를 하나로 통일하여 사용하는게 맞음. 그 외엔 insert, append 이런걸 써야 함.

- Use Solution Domain Names

  - technical term을 써도 된다. JobQueue, Visitor 등 CS, Algorithm, Pattern, math 이런 term을 갖다 쓰자.

