# Basic :beginner:

### **JavaScript is**

- lightweight, cross-platform, object-oriented computer programming language
- lightweight : doesn't eat up memory, relatively simple grammar
- cross-platform : used in multiple platform system
- object-oriented : language is based on object
- **Core technology of web**
  - Dynamic effects and interactivity
  - Modern web applications that we can interact with
- **React, Angular** are based on 100% JavaScript!

<br>

### How to use JavaScript Code

> html에 직접 작성하기

```html
<script>
	console.log("Hello World!")
</script>
```

> 외부 파일에 작성된 코드를 붙여넣기

```html
<script src="script.js"></script>
```

<br>

# Grammar

> Variable

```javascript
var firstname = 'Kang';
```

- text를 쓸 땐 single quote를 사용하는게 Modern
- **Dynamically typed**

<br>

> Primitive types (immutable)

- Number - floating point numbers for decimal and integer
- String - Sequence of characters
- Boolean - true or false
- Undefined - Data type of **variables that does not have a value yet**
- Null - Meaning of Non-existence
- Symbol (in **ES6**)

<br>

> Type Coercion

```javascript
var Name = 'KwanHun';
var age = 28;
console.log(firstName + ' ' + age);
```

결과는 'KwanHun 28'이 콘솔창에 출력된다. Number였던 28이 String으로 자동 변경되었다.

String + Number => String

String + Bool => String

Bool + Number => Number

<br>

> Variable mutation

```javascript
age = 'twenty five';
job = age;
job = "Programmer"
console.log(age)
```

결과는 "twenty five" 가 출력된다. string은 값 복사로 전달된다.<br>

```javascript
var data = [1,2,3,4,5];
var data2 = data;
data2[0] = 100;
console.log(data);
```

결과는 [100,2,3,4,5] 가 출력된다. 이 경우엔 data2는 data가 가르키는 곳을 가르키게 된 것이다.

<br>

> Operator

- Math operators : + , - , / , % , * , **, ++ 
  - Number가 Floating points 라, 결과가 깔끔하게 나오는 경우는 소수점이 안보이고, 그 외엔 다 보임.
- Logical operator : &&, ||, !
- typeof operator : type을 리턴 (string 타입으로 작성된 type)

<br>

> If else

```javascript
var name = "KKH"
if(name == "KKH"){
    console.log("He is Awesome");
}
```

c언어랑 똑같다. 

<br>

> Ternary operator && Switch case

```javascript
var age = 16;
console.log(age>=18?"You can drink" : "You cannot drink");
```

c언어랑 똑같다.

<br>

> Equality Operator

 ```javascript
1 == '1' // return true (type coercion)
1 === '1' // return false 
 ```

<br>

> Function Definition

```javascript
function functionName(parameter){
    // code
}
var variable = function(param1, param2){
    // code
}
variable(par1, par2);
```

var variable 같은 경우엔 변수가 곧 함수가 되는 것이다.<br>

### Arrays

```javascript
var data = [1,2,3,4,5];
data.pop() // data = [1,2,3,4]
data.push(5) // data = [1,2,3,4,5]
data.shift() // data = [2,3,4,5]
data.unshift(1) // data = [1,2,3,4,5]
console.log(john.indexof(3)) // 2
console.log(john.indexof(6)) // -1
```

<br>

### Objects

```javascript
var KKH = {
    name : 'Kwan Hun',
    birthYear : 1995,
    job : 'developer',
    isMarried : false
};

KKH.isAwesome = true;
console.log(KKH.isAwesome); // true
```

이런 식으로 정의할 수 있고

```javascript
var KKH = new Object();
KKH.something = "Is wrong";
```

과 같이 정의할 수 있다. 해당 Object의 attribute를 설정해주는 방식. []으로 attribute의 값에 접근할 수 도 있다.<br>

```javascript
var KKH = {
    BirthYear : 1995,
    calcAge : function(){
        return 2019 - this.BirthYear;
    }
}
console.log(KKH.calcAge())
```

위와 같이 Object 내 메소드를 정의하여 사용할 수도 있다.