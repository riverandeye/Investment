# Chap 7 - Error Handling



#### Introduction

> Error handling is important, but if it obscures logic, it’s wrong 



#### Before this Chapter

- Error
  - indicates serious problems that a reasonable application **should not try to catch.**
  - StackOverflowError, OutOfMemoryError 이런거
- Exception
  - indicates conditions that a reasonable application **might want to catch**
  - 예를 들어서 FileNotFoundException, ParseException, 이런건 프로그래머가 try catch로 잡아줄만한 것
  - **Catch** 하는걸 권장하지 않는 경우도 있음. ArrayIndexOutOfBound 이런거
- Interrupt
  - asynchronous interruption
    - I/O Interrupt, keyboard event, network packet arrived etc..
  - synchronous interruption -> Exception



#### Use Exceptions Rather Than Return Codes

- 작업을 수행 한 중간에 오류가 발생할 시, '오류가 발생했다' 는 코드를 보내지 말고 Exception을 던지자.
- Error Handling 과 Algorithm 을 분리시켜서 코드를 명확하게 만들어라.



#### Write Your Try-Catch-Finally Statement First

- Exception은 프로그램의 **scope**를 정해준다.
- **try는 transaction 과도 같은 것이라, catch 를 통해 application을 consistent 하게 만들어주어야 한다.** 
- 이를 통해 **try 내에서 어떤 문제가 발생했든 문제가 없도록 해야한다**.



이게 무슨 의미인지 예시를 통해서 한번 알아보자.

```java
@Test(expected = StorageException.class)
public void retrieveSectionShouldThrowOnInvalidFileName() {
    sectionStore.retrieveSection("invalid - file");
}
```

테스트 코드를 이렇게 짰다고 쳐보자. Invalid File Name을 입력했을 때 에러를 던진다는 테스트 내용이다. 테스트 코드를 이렇게 짰으면 메소드는 이렇게 나올 것.



```java
public List<RecordedGrip> retrieveSection(String sectionName) {
    // dummy return until we have a real implementation
    return new ArrayList<RecordedGrip>();
}
```

근데 애는 sectionName을 넣는다고 에러가 반환되지는 않으니, 실제 FileInputStream을 불러오는 함수를 짜고, try-catch 문에 넣고 catch에서 error를 던져야 한다.



```java
public List<RecordedGrip> retrieveSection(String sectionName) {
    try {
        FileInputStream stream = new FileInputStream(sectionName)
    } catch (Exception e) {
        throw new StorageException("retrieval error", e);
    }
    return new ArrayList<RecordedGrip>();
}
```

이제 테스트가 통과하니, 실제 메소드가 뱉는 Exception으로 catch 하는 Exception의 범위를 좁혀주자.



```java
public List<RecordedGrip> retrieveSection(String sectionName) {
    try {
        FileInputStream stream = new FileInputStream(sectionName);
        stream.close();
    } catch (FileNotFoundException e) {
        throw new StorageException("retrieval error”, e);
	}
	return new ArrayList<RecordedGrip>();
}
```

이런 식으로, **먼저 exception을 발생시켜야 하는 테스트 케이스를 생성한 후, handler에 behavior를 추가하여 테스트를 만족시키자**. Transaction scope를 지정하는 것. '특정 하나의 에러' 를 핸들링하는 스코프를 지정하는 것이 핵심인 것으로 보인다. 그래야 유의미한 Transaction 이라고 할 수 있다. 



#### Use Unchecked Exceptions

- Checked Exception을 쓰지 말라고 한다. 근데 그게 뭔지 모르겠다.. 수홍이가 알려줄 것이다.



#### Provide Context with Exceptions

- Source와 Location에 대한 충분한 context를 exception에 담아 전달하자.
- 로그에도 Informative한 error message를 남기자

