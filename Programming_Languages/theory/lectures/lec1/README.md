# Lecture 1 - Inductive Definition



### Inductive Definition



**Induction is a technique for formally defining a set**

- The set is defined in terms of itself (자기 자신을 정의하는 집합)
- The only way of defining an infinite set by a finite means. (무한 집합을 유한한 요소로 정의하는 유일한 방법이다.)

**Three styles to inductive definition**

- Top-down
- Bottom-up
- Rules of inference



### Example

1. Top-down

   자연수의 부분집합 S 를 정의하는 경우를 살펴보자.

   ![image-20200121111229849](C:\Users\tony0\Desktop\github\Investment\Programming_Languages\theory\lectures\lec1\images\image-20200121111229849.png)

   해당 집합 내 원소가 가져야 할 조건을 명시함으로써 집합을 정의하는 방식이다.

   

   S에 대한 정의를 자기 자신(S)으로 하고 있다. 이때 S가 될 수 있는 n은 0, 3, 6, 9.... 3k (k =1,2,3...) 이 될 것이다.

   귀납법으로 증명한다면 다음과 같다.

   ![image-20200121111414867](C:\Users\tony0\Desktop\github\Investment\Programming_Languages\theory\lectures\lec1\images\image-20200121111414867.png)

   

2. Bottom-up

   동일한 정의를 Bottom-up 방식으로 해보면 이렇다.

   ![image-20200121111830001](C:\Users\tony0\Desktop\github\Investment\Programming_Languages\theory\lectures\lec1\images\image-20200121111830001.png)

   가장 작은 집합을 먼저 정의하고, 다음 조건을 통해 그 집합을 커지게 하는 방식이다.

   

3. Rules of inference

   세번째 방식은 추론 규칙을 통해 정의하는 방법이다.

   ![image-20200121112702089](C:\Users\tony0\Desktop\github\Investment\Programming_Languages\theory\lectures\lec1\images\image-20200121112702089.png)

   마치 분모, 분자 꼴로 되어있고, 분자가 맞으면 분모도 맞다 로 '추론'하는 규칙을 통해 집합을 정의한다.

   

   ![image-20200121112902955](C:\Users\tony0\Desktop\github\Investment\Programming_Languages\theory\lectures\lec1\images\image-20200121112902955.png)

   동일한 집합을 Inference rule로 정의하면 다음과 같다.

   0은 항상 S에 포함되고, 

   어찌보면 Bottom-up 방식을 그대로 기호로 표현한 것과 같아보이지만, 다른 점은 Bottom-up은 조건으로, Inference는 추론 규칙들로 구성되어 있다는 점에 있다.

   PL 에서는 주로 Rules of Inference 방식으로 Inductive Definition을 구성할 것.



### Exercise

![image-20200121114309660](C:\Users\tony0\Desktop\github\Investment\Programming_Languages\theory\lectures\lec1\images\image-20200121114309660.png)

1) 3의 배수

2) 문법적으로 올바른 괄호쌍 

3) /a, /b, x /xx , x y/xy

4) /y, a / xay

