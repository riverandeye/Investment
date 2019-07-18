# Pure Function

- Return value가 **같은 argument에 대해서 항상 같은** 함수
  - 함수 호출을 해당 함수의 리턴 값으로 대체할 수 있음. 
- **side effect가 없는 함수** 
  - 해당 Scope 외부의 변수 및 객체의 속성을 참조하거나 수정하지 않는다.
  - Console에 로깅 및 I/O작업을 수행 하지 않는다.
  - 외부 프로세스를 작동시키지 않는다.

<br>

**example of not pure function**

```javascript
// Console log를 발생시키는 함수
function helloworld(){
    console.log("Hello world!"); // 콘솔 로깅은 리턴과는 관계 없는 side effect
}
```



**example of pure function**

```javascript
function helloworld(){
    return "Hello world!"; // Immutable variable을 리턴한다
}
```

