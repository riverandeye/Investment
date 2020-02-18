# Chap 6 - Objects and Data Structures



#### Intro

-  Why automatically add getters and setters to their objects, exposing their private variables **as if they were public**?



### Data Abstraction

- **Hiding Implementation** is about **Abstraction**
- 객체는 **추상 인터페이스** 를 제공하여 implementation에 대해 알 필요 없이 원하는 것을 제공.



```java
public class Point {
    public double x;
    public double y;
}
```

이거랑

```java
public interface Point {
    double getX();
    double getY();
    void setCartesian(double x, double y);
    double getR();
    double getTheta();
    void setPolar(double r, double theta);
}
```



Point가 하는 '행위'가 정의되어 있고, 구현부 (cartesian 인지 polar인지) 가 생략되어 있다. 

**Implementation**은 알지 못하게 하고, **essence of data**, 진짜 다른 객체에게 필요한 것을 제공하는 창구만 열어놓는 것이다. 



```java
public interface Vehicle {
 double getFuelTankCapacityInGallons();
 double getGallonsOfGasoline();
}
```

이거랑

```java
public interface Vehicle {
 double getPercentFuelRemaining();
}
```

이걸 보자.

Vehicle의 TankCapacity를 온 세상이 알아야 하나? 그건 아니라는거다. 필요한 정보만 제공할 수 있는 창문만 만들자는 거다. 위의 interface는 내부 implementation 을 알려주는 메소드다. 



#### Data/Object Anti-Symmetry ★

Object와 Data-structure의 차이는, Object는 data를 뒤로 숨기고 그 데이터를 다루는 function을 내세우는 반면, Data-structure는 data를 그대로 노출한다. 예시를 통해 알아보자.



```java
public class Square {
    public Point topLeft;
    public double side;
}
public class Rectangle {
    public Point topLeft;
    public double height;
    public double width;
}
public class Circle {
    public Point center;
    public double radius;
}
public class Geometry {
    public final double PI = 3.141592653589793;
    public double area(Object shape) throws NoSuchShapeException
    {
        if (shape instanceof Square) {
            Square s = (Square)shape;
            return s.side * s.side;
        }
        else if (shape instanceof Rectangle) {
            Rectangle r = (Rectangle)shape;
            return r.height * r.width;
        }
        else if (shape instanceof Circle) {
            Circle c = (Circle)shape;
            return PI * c.radius * c.radius;
        }
        throw new NoSuchShapeException();
    }
}
```

위 코드는 Class 문법을 사용하였지만 implementation (data structure)만 있고 Behavior가 하나도 없다. 

만약 Geometry에 둘레를 구하는 함수가 추가된다면, 굳이 Shape가 바뀌지 않아도 된다.

만약 새로운 Class가 등장하게 되면, Geometry 내의 모든 구현된 함수를 수정해야 한다.



```java
public class Square implements Shape {
    private Point topLeft;
    private double side;
    public double area() {
        return side*side;
    }
}

public class Rectangle implements Shape {
    private Point topLeft;
    private double height;
    private double width;
    public double area() {
        return height * width;
    }
}

public class Circle implements Shape {
    private Point center;
    private double radius;
    public final double PI = 3.141592653589793;
    public double area() {
        return PI * radius * radius;
    }
}
```

위 코드는, area 메소드가 polymorphic 하게 구성되어있다. 그러다보니 각 Shape에 대한 메소드를 구현할 Geometry라는 Class가 따로 필요가 없게 된다. 그러나 함수를 하나 추가하려면 모든 구현체에 도입해야 함.



**절차지향적인 코드는 그래서 새로운 함수를 구조의 변화 없이 만들 수 있지만**

**객체지향적인 코드는 함수의 변화 없이 새로운 객체를 추가할 수 있다.**

```
Procedural code (code using data structures) makes it easy to add new functions without
changing the existing data structures. OO code, on the other hand, makes it easy to add
new classes without changing existing functions.
```



**절차지향적인 코드는 함수를 바꿔야 하기 때문에 새로운 구조를 추가하기 어렵고**

**객체지향적인 코드는 모든 객체가 바뀌어야 하기 때문에 새로운 함수를 추가하기 어렵다**

```
Procedural code makes it hard to add new data structures because all the functions must
change. OO code makes it hard to add new functions because all the classes must change.
```



그래서 자기가 디자인 해야 할 프로그램의 방향성을 고민을 하고, 어떤 방식을 택할지를 고민해야한다.



#### The Law of Demeter

- **module should not know about the innards of the objects it manipulates.**

-  a method **f** of a class **C** should only call the methods of these: 
  - **C**
  - An object created by **f**
  - An object passed as an argument to **f** 
  - An object held in an instance variable of **C**



#### Train wreck

```java
final String outputDir = ctxt.getOptions().getScratchDir().getAbsolutePath();
```

이런식으로 chain of call 형식으로 구성되어 있는 걸 피해야한다. 함수가 알아야 할 것이 많아지기 때문이다.



```java
Options opts = ctxt.getOptions();
File scratchDir = opts.getScratchDir();
final String outputDir = scratchDir.getAbsolutePath();
```

이런식으로 변수를 분리해주는 것이 좋다.

- 이 부분 이해 안되는 점
  - 객체가 내부 변수를 숨겨야 하므로 Demeter 법칙을 어겼다는건, getOptions 이런거 때문이겠찌?



#### Hiding Structure

ctxt, options, scratchDir 가 real behavior가 있는 object 라면 object는 internal structure를 숨겨야 한다.

그럼 outputDir를 어떻게 만들어야 할까? 

```java
ctxt.getAbsolutePathOfScratchDirectoryOption();
ctx.getScratchDirectoryOption().getAbsolutePath()
```

첫번째는 저 한 메소드가 너무 커지게 될 거 같고, 두번째는 Data Structure를 반환하게 될 것 같다.

object에게는 내부 구조가 어떤지를 요청할게 아니라, **무언갈 해달라고 요청해야 한다.** 



#### Data Transfer Object

data-structure의 본질적인 면은 함수 없는 public variable 이다. 소켓, db등 통신하기 매우 좋은 구조이다. bean은 모든 메소드가 private이고 getter setter가 있는건데, 이 구조에 대한 특별한 장점은 없다.



#### Active Record ★

public variable 이 있는 data structure (약간 짬뽕) 인데, 이건 그렇게 적합하지 않다고 한다. Active Record는 Data structure 로 두고, Business Rule을 작성하고 Internal data를 숨기는 object를  따로 만들어랏.

