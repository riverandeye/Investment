# Chap 3 - function

> 함수를 어떻게 작성해야 할까요?



### Small!

- 함수는 무조건 작게 구성해라.
- the indent level of a function **should not be greater than one or two**.

- **FUNCTIONS SHOULD DO ONE THING. THEY SHOULD DO IT WELL. THEY SHOULD DO IT ONLY.**

- So, another way to know that a function is doing more than “one thing” is if you can extract another function from it with a name that is not merely a restatement of its implementation [G34].



### One Level of Abstraction per Function

- 추상화는 함수 내에서 딱 한번만!



#### Reading Code from Top to Bottom: The Stepdown Rule



### Switch Statement -- 좀 이해가 안됨.

- 안좋은 것은 예시를 보면 안다.

```java
public Money calculatePay(Employee e)
throws InvalidEmployeeType {
 switch (e.type) {
     case COMMISSIONED:
     	return calculateCommissionedPay(e);
     case HOURLY:
     	return calculateHourlyPay(e);
     case SALARIED:
     	return calculateSalariedPay(e);
     default:
     	throw new InvalidEmployeeType(e.type);
     }
 }
```

애는 employee의 타입 마다 pay를 계산해주는 거다. 함수 내에서 switch 문으로 employee의 타입이 다른 경우에 switch 문으로 다른 메소드를 제공한다.

이렇게 하면 단점이 있는데,

- employee의 타입이 추가될 때 마다 코드가 변경되야함 (OCP X)
- 모든 'employee' 타입마다 결과가 달라져야하는 메소드가 이렇게 구성된다. (코드 중복)



**switch 문을 Abstract Factory 내에 넣어놓고, Abstract Factory가 객체를 만들어주고, 해당 객체에 적절한 메소드가 배치되어있는 식으로 구성해야 한다.**

```java
public abstract class Employee {
    public abstract boolean isPayday();
    public abstract Money calculatePay();
    public abstract void deliverPay(Money pay);
}
-----------------
public interface EmployeeFactory {
	public Employee makeEmployee(EmployeeRecord r) throws InvalidEmployeeType;
}
-----------------
public class EmployeeFactoryImpl implements EmployeeFactory {
    public Employee makeEmployee(EmployeeRecord r) throws InvalidEmployeeType {
        switch (r.type) {
            case COMMISSIONED:
                return new CommissionedEmployee(r) ;
            case HOURLY:
                return new HourlyEmployee(r);
            case SALARIED:
                return new SalariedEmploye(r);
            default:
                throw new InvalidEmployeeType(r.type);
        }
    }
}
```

이렇게 구성하면, switch 문을 한번만 써도 되고, Factory에 넣는 type에 대해 메소드가 해당 class에 implement 되니까 (abstract class 니까) 완전 좋다. 타입이 추가되면, Factory에만 반영하고 생성자에 전달만 하면 되니까!길



### Use Descriptive Name

- 길어도 명시적인게 좋다.
- 일관적으로 지어라.



#### Function Arguments

- 없는게 최고, 한두개 정도는 봐줄만 하다. 3개 이상은 좀 에바.

- Argument 많을수록 이해도 힘들고, 테스트하기도 힘들다.

- Monadic Form을 가져가는게 

- Flag 쓰지 마라.

- Dyadic 으로 갈거면, 두 argument가 관계가 명확하거나 혹은 순서가 존재하는 하나의 대상인 것을 추천

  3개 이상이면 Object로 빼라



#### Have No Side Effect

- 함수가 하나 하는줄 알았더니 2개를 하는거임 (엥?)
  - 예상치 못한 결과를 낳음.
  - 함수 명에 써져있지 않는 일들이 함수 안에서 벌어지지 않게끔 하자.



#### Output Arguments

- Anything that **forces you to check the function signature is equivalent to a double-take.** It’s a cognitive break and should be avoided. | 그냥 명확히 좀 써라.



#### Command Query Seperation

- Functions should either do something or answer something, but not both. 
- Either your function should change the state of an object, or it should return some information about that object. 
- **Doing both often leads to confusion.**

어떤 조건에 무언갈 수행해야 되는 상황에서, '조건 판단'과 '수행'을 하나의 함수에 두지 말라는 내용임. 뭐 그 뿐만 아니라 다른 것들도 마찬가지. 



#### Prefer Exceptions to Returning Error Code

- 에러 케이스를 직접 분류하여 메세지를 구분하지 말고, 정형화된 에러 객체를 반환 할 수 있게끔 Exception을 던지고 catch 해서 편하게 메세지를 전달하자.

- if the keyword try exists in a function, it should be the very first word in the function and that there should be nothing after the catch/finally blocks.
  - Try Catch도 함수니까, 다른 문장이 있다면 이는 여러 일을 같이 하게 되는거겟져.
- When you use exceptions rather than error codes, then new exceptions are derivatives of the exception class. **They can be added without forcing any recompilation or redeployment**.



#### DRY (Don't Repeat Yourself)

- **Duplication may be the root of all evil in software. Many principles and practices have been created for the purpose of controlling or eliminating it**
  - all of Codd’s database normal forms serve to eliminate duplication in data
  - OOP, AOP, COP.. 모두 중복 제거용..



#### 그래서 어떻게 잘짜냐고?

- 걍 짜고, **그 다음에 리팩토링 하자.**

- **Master programmers think of systems as stories to be told** (좀 멋있는듯)