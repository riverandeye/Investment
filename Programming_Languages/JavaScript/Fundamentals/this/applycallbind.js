var Person = function (name) {
    this.name = name;
};

var foo = {};

// apply 메소드는 생성자함수 Person을 호출하며 this에 객체 foo를 바인딩한다.
Person.apply(foo, ['name']);

console.log(foo); // { name: 'name' }
console.log(foo instanceof Person); 