## 자바스크립트 비동기

### call stack

콜 스택은 호출된 함수에 대한 정보가 저장되는 스택 공간을 의미한다. 스택의 특성 답게, 함수가 호출될 때 **콜 스택**의 맨 위에 쌓이고, 리턴할 때 빠져나간다. 

함수간의 호출 관계는 스택 자료구조로 표현되는데, 특정 함수가 다른 함수를 호출하면, 호출된 함수는 **콜 스택** 상에서 호출한 함수의 위에 쌓이게 된다. 호출된 함수가 리턴되면, 리턴값은 호출한 함수에게 전달된다. 위 gif는 콜 스택의 작동 방식을 적절하게 설명하고 있다. 

![콜스택](https://miro.medium.com/max/675/1*E3zTWtEOiDWw7d0n7Vp-mA.gif)

위 gif 에서, main()이 실행되고, 그 후 console.log()가 실행되고, 함수 bar가 console.log()에서 호출되고, 그 후 bar의 리턴을 foo로 함으로써, foo를 호출한다. **Call stack은 해당 호출 순서를 그대로 반영한다**. 먼저 호출된 함수는 스택의 낮은 위치에, 나중에 호출된 함수는 스택의 높은 위치에 있게 된다. 이러한 방식으로 함수 호출을 관리한다.

### Event Queue && Event Loop

Event queue는 setTimeout과 같은 web API의 동작에 대한 결과를 보관하는 큐이다. Event loop은 callback queue에 존재하는 event들이 Call Stack이 완전히 비게 되는 시점에 다시 stack으로 올려주는 작업을 한다. 예시를 통해 설명을 해보자.

```javascript=
console.log('Hi');
setTimeout(()=>{console.log('cb')},0);
console.log("Bye");
```

해당 코드의 작동 시뮬레이션은 밑의 이미지로 묘사된다.

![](https://miro.medium.com/max/1400/1*TozSrkk92l8ho6d8JxqF_w.gif)

처음 main의 시작으로 console.log("Hi")가 작동하면, 콜 스택에 우선 해당 함수가 쌓이고, 콘솔에 "Hi"를 출력함으로써 바로 수행될 것이다.

그 후 setTimeout(()=>{console.log('cb')},0); 을 실행시킨다. setTimeout은 web API의 요소중 하나이기 때문에, **해당 함수를 실행 시 web API에서 동작하여, 0초 후 콜백 함수를 리턴할 것이다.** 리턴된 함수는 **Callback Queue(Event Queue)**에 저장되어, Call Stack이 완전히 비게 될 때 까지 기다릴 것이다.

console.log("Bye")가 작동한 이후,  **Call Stack이 완전히 비게 되므로**, **Event Loop에 의해 Callback Queue에 있는 함수들이 Call Stack으로 이동하게 된다**. 이와 같은 방식으로 작동하게 된다.

### Why?

왜 이런 구조로 되어 있을까? 그 이유는 자바스크립트가 싱글쓰레드 라는 점에 기인한다. 싱글 쓰레드는 어떤 특정 동작이 오랜 시간이 걸리면, 그 동작을 수행할 때 까지 기다려 주어야 한다. 그러나 빠른 반응과 동작을 필요로 하는 웹의 입장에선, 이러한 병목현상은 적절하지 않다. 그래서 이미지를 불러오는 일이나, 통신이 필요한 것들에 대해서는 setTimeout와 같은 web API를 이용하여, 빠르게 수행되어야 하는 것들을 먼저 수행해주고, 나중에 stack이 완전히 비게 되면 Event loop을 통해 실행해주는 것이다. 



### Reference

[call stack에 관한 gif](https://medium.com/@gaurav.pandvia/understanding-javascript-function-executions-tasks-event-loop-call-stack-more-part-1-5683dea1f5ec)

[Event loop]([https://engineering.huiseoul.com/%EC%9E%90%EB%B0%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8%EB%8A%94-%EC%96%B4%EB%96%BB%EA%B2%8C-%EC%9E%91%EB%8F%99%ED%95%98%EB%8A%94%EA%B0%80-%EC%9D%B4%EB%B2%A4%ED%8A%B8-%EB%A3%A8%ED%94%84%EC%99%80-%EB%B9%84%EB%8F%99%EA%B8%B0-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%EC%9D%98-%EB%B6%80%EC%83%81-async-await%EC%9D%84-%EC%9D%B4%EC%9A%A9%ED%95%9C-%EC%BD%94%EB%94%A9-%ED%8C%81-%EB%8B%A4%EC%84%AF-%EA%B0%80%EC%A7%80-df65ffb4e7e](https://engineering.huiseoul.com/자바스크립트는-어떻게-작동하는가-이벤트-루프와-비동기-프로그래밍의-부상-async-await을-이용한-코딩-팁-다섯-가지-df65ffb4e7e))

