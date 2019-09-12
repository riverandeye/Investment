# This in JavaScript



> **함수 호출 방식에 따라 this에 바인딩되는 객체가 달라진다 (동적으로 결정된다).**





### This in Function declaration

일반 함수를 호출하는 방식은 4가지가 있다.

1. 함수 호출
2. 메소드 호출
3. 생성자 함수 호출
4. apply, call, bind 호출



#### 함수 호출

**일반 함수 호출 -> window**

```javascript
const sample = function(){
    console.log(this)
}
sample() // window
```

자바스크립트의 모든 전역 변수는 **전역 객체(Global Object)** 의 프로퍼티이다. JS의 경우엔 window, Nodejs의 경우 global 이 전역 객체에 해당한다. 기본적으로 this는 위 전역 객체를 가르키게 된다.



**함수 내 함수 호출 -> window** 

```javascript
const sample2 = function(){
    const sample3 = function(){
        console.log(this);
    }
    sample3();
}
sample2();
```

이와 같이 함수 내에 함수가 정의된 상태에도 this는 전역 객체를 가르킨다.



**메소드의 내부 함수 -> window** 

```javascript
const obj = {
    sam : function(){
        const a = function(){
            console.log(this);
        }
        a();
    }
}
obj.sam();
```

당연히 this가 obj에 바인딩 될 것 같아 보이지만 그렇지 않다.



**콜백함수의 내부 함수 -> window**

```javascript
const obj2 = {
    sam : function(){
        setTimeout(function(){
            console.log(this);
        }, 1000)
    }
}
obj2.sam();
```

애도 마찬가지. 애초부터 내부 함수는 해당 객체를 조작할 수 없게끔 설정하였다.



#### 메소드 호출

```javascript
const obj1 = {
    name : "KKH",
    sayName : function(){
        console.log(this.name);
    }
}

const obj2 = {
    name :"PJS",
}

obj2.sayName = obj1.sayName;

obj1.sayName(); // KKH
obj2.sayName(); // PJS
```

함수가 객체의 property 일 시 메소드로 호출되는데, 이때 this는 해당 메소드를 소유한 객체에 바인딩 된다. 이는 **Lexical하게 binding 되지 않고 동적으로 바인딩** 됨을 보인다. 이는 프로토타입 객체의 메소드에도 적용 되는 사항이다.



#### 생성자 함수 호출

```javascript
function Person(name){
    this.name = name;
}

var Me = new Person('KKH');
console.log(Me) // Person { name: 'KKH' }

var You = new Person("JHJ");
console.log(You); // Person { name: 'JHJ' }
```

모양은 일반 함수와 같아 this가 global object를 가르킬 것 같지만, 실제로는 다른 수순을 밟는다.

1. new 에 의한 생성자 함수가 빈 객체를 생성하고, **this는 이 빈 객체를 가리킨다.**
2. 이후 this를 통해 생성한 프로퍼티와 메소드는 새로 생성된 객체에 추가한다.
3. 다른 걸 return 하는 경우가 아닐 시 해당 객체가 반환된다.



#### apply, call, bind



**apply**

```javascript
var Person = function (name) {
    this.name = name;
};

var foo = {};

// apply 메소드는 생성자함수 Person을 호출하며 this에 객체 foo를 바인딩한다.
Person.apply(foo, ['name']);

console.log(foo); // { name: 'name' }
console.log(foo instanceof Person); // false
```

apply는 해당 생성자 내 this를 입력한 객체로 설정하고 함수를 수행한다. 자연스럽게 기존 Object에 프로퍼티들이 추가된다. 중요한 것은 추가되는 것이지, 해당 생성자의 인스턴스가 되는 것은 아니다.



**call** -> apply랑 똑같고, 인자를 따로따로 전달하는 것 외엔 차이가 없음.



**bind** -> 함수에 this로 바인딩 할 인자를 주면 새로운 함수를 리턴한다.



**번외1 : 객체 리터럴과 생성자 함수의 차이**

```javascript
// 객체 리터럴 방식
var foo = {
    name: 'foo',
}

console.dir(foo); // { name: 'foo' }

// 생성자 함수 방식
function Person(name) {
    this.name = name;
}

var me = new Person('Lee');
console.dir(me); // Person { name: 'Lee' }
```

- 객체 리터럴의 프로토타입 객체는 Object.prototype
- 생성자 함수로 만들어진 객체의 프로토타입 객체는 Person.prototype



**번외2 : Scope-Safe Constructor Pattern**

```javascript
if (!(this instanceof arguments.callee)) {
    return new arguments.callee(arg);
}
```

- 일반함수처럼 사용되는 것을 방지하기 위해 위 패턴을 추가한다.
- arguments.callee는 호출된 함수의 이름이다.
  - 만약 new로 호출되었으면, 빈 객체가 생성되었을 것이고 해당 객체의 프로토타입 객체는 arguments.callee.prototype 이 되므로, instanceof 에 의해 true를 반환하므로 return이 작동되지 않는다.
  - new로 호출되지 않으면, 밑의 코드가 실행되어 다시 new로 함수가 실행된다.



### Reference

- https://poiemaweb.com/js-this

- https://poiemaweb.com/es6-arrow-function