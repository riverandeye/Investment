# Terminology

> JS에 관한 키워드들을 알파벳순으로 정리합니다.





### Closure

> 함수와 함수가 선언된 영역에 대한 lexical environment 



리턴된 내부 함수 인스턴스를 클로저라고 한다.**클로저는 선언된 영역에 대한 Scope를 보존한다.**

```javascript
function makeAdder(x) {
  return function(y) {
    return x + y;
  };
}

var add5 = makeAdder(5);
var add10 = makeAdder(10);

console.log(add5(2));  // 7
console.log(add10(2)); // 12
```

add5 = makeAdder(5)가 선언되고 함수가 리턴되고 해당 함수는 스택에서 소멸되지만, 함수의 lexical environment는 보존되어 add5에 남아있다. 클로저를 이용하여 비슷한 기능을 하는 함수를 재정의 하지 않아도 만들어서 사용할 수 있다.



**Closure Done right**

```javascript
function showHelp(help) {
  document.getElementById('help').innerHTML = help;
}

function setupHelp() {
  var helpText = [
      {'id': 'email', 'help': 'Your e-mail address'},
      {'id': 'name', 'help': 'Your full name'},
      {'id': 'age', 'help': 'Your age (you must be over 16)'}
    ];

  for (var i = 0; i < helpText.length; i++) {
    var item = helpText[i];
    document.getElementById(item.id).onfocus = function() {
      showHelp(item.help);
    }
  }
}

setupHelp();
```

위 코드는 각 id를 갖는 DOM Element에 대하여 onfocus 이벤트에 대한 리스너를 달아주는 코드이다. 



<!DOCTYPE html>
<html>
  <head>
    <title>This is a title</title>
  </head>
  <body>
    <p id="help">Helpful notes will appear here</p>
    <p>E-mail: <input type="text" id="email" name="email"></p>
    <p>Name: <input type="text" id="name" name="name"></p>
    <p>Age: <input type="text" id="age" name="age"></p>
   	<script src="http://yourjavascript.com/99081112322/a.js"></script>
  </body
</html>



### IIFE

> Immediately Invoked Function Expression

```javascript
(function(){
    ...
})();
```

함수가 즉시 호출되는 1회성 익명 함수이다. 글로벌 스코프의 전역변수를 최소화하여 충돌을 방지하는 장점이 있다.



### Module Pattern







### Scoping

> 상위 스코프를 함수를 어디서 선언했느냐에 따라 결정하는 Scope 방식.



**Lexical Scoping**

Lexical Scoping은 함수를 어디에 **선언**했느냐에 따라 Scope 결정되는 것이다. 

```javascript
const a = function(){
	let data = 1;
    const b = function(){
        console.log(data);
    }
    return b;
}
(a())(); // 1
```

함수 b는 함수 a 안에서 정의하였으므로, 함수 b의 scope는 전역변수, 자기 자신과 **상위 함수인 a**가 될 것이다. 이와 같이 정의 된 영역에 대한 scope를 가지는 방식을 Lexical Scoping 이라고 한다.



**Dynamic Scoping**

함수가 어디에서 호출되었느냐에 따라 Scope 가 결정되는 방식을 말한다.

```javascript
const a = function(){
    let aa = 1;
    b();
}

const b = function(){
    console.log(aa);
}

a(); //
```



실제로 자바스크립트는 Lexical Scoping을 지원하기 때문에 위 코드는 아래와 같은 에러가 발생 할 것이다.

```bash
ReferenceError: aa is not defined
at b (repl:2:17)
```

만약 Dynamic scoping 으로 정의되었다면, b는 a안에서 호출되었기 때문에 a에서 정의된 aa라는 변수가 b의 scope안에 있을 것이다.







### Reference

IIFE : https://developer.mozilla.org/ko/docs/Glossary/IIFE

Scope, Closure : https://developer.mozilla.org/ko/docs/Web/JavaScript/Guide/Closures

