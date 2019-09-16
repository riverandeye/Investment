# Arrow Function



Arrow function 은 ES6 부터 지원하는 함수로, this binding이 되지 않아있는 것이 함수의 중요한 특성이다.

```javascript
const arrFunc = (param)=>{code}
```



리턴을 명시하지 않아도, {}를 감싸지 않으면 해당 값을 리턴하는 것으로 표현된다.

```javascript
const helloworld = ()=>"Hello World";
console.log(helloworld()); // Hello World
```



### This in Arrow Function

- Arrow Function은 Lexical Scope 에서의 **상위 스코프의 this를 가르킨다.**



```javascript
const obj = {
    init() {
        const button = document.getElementById('shit');
        button.addEventListener("click", () => {
            this.log();
        });
    },
    fn() {
        this.log();
    },
    log() {
        console.log("test");
    }
};

obj.init();
```

여기서 ()=>{this.log()} 의 this는 상위 스코프인 init의 this인 obj를 가르키게 된다. 

이러면 굳이 function().bind(that) 이러지 않아도 this 바인딩이 된다.



### When should not use Arrow Function ? 

- **Method**
  - 상위 컨텍스트인 전역 객체를 가르킨다.
- **prototype**
  - Method와 같은 이유
- **Constructor function**
  - 화살표 함수는 prototype 프로퍼티가 없어서 Constructor로 사용할 수 없다.
- **Callback on addEventListener**
  - this가 상위 컨텍스트인 전역 객체 window가 된다.
  - function을 사용해야 동적으로 this가 바인딩되어 해당 DOM 객체를 가르키게 된다.



### Reference

- https://poiemaweb.com/es6-arrow-function