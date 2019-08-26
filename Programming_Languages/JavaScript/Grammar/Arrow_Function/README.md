# Arrow Function



Arrow function 은 ES6 부터 지원하는 함수로, this binding이 되지 않아있는 것이 함수의 중요한 특성이다.

```javascript
const arrFunc = (param)=>{code}
```



### 예시를 통한 이해



```javascript
class Animal {
    constructor(name, age){
        this.name = name;
        this.age = age;
    }
}
```

Animal 이란 Class를 만들고

```javascript
class Person extends Animal{
    constructor(name, age){
        super(name, age);
    }

    talk(){
        return ()=>{
            console.log(`제 이름은 ${this.name} 입니다.\n`);
        }
    }

    listen(callback){
        callback();
    }
}
```

이를 상속하는 Person 은 talk과 listen 함수가 있다. 

```javascript
class Dog extends Animal {
    constructor(name, age){
        super(name, age);
    }

    talk(){
        return function(){
            console.log(`Bark! Bark! Bark! ${this.name}! Bark!`);
        }
    }

    listen(callback){
        callback();
    }
}
```



```javascript
const KwanHun = new Person("KwanHun", 25);
const Lilly = new Dog("Lilly", 3);

KwanHun.listen(Lilly.talk()); // this doesn't work
Lilly.listen(KwanHun.talk()); // this works
```

