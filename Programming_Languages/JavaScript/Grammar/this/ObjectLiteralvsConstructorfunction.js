// 객체 리터럴 방식
var foo = {
    name: 'foo',
}

console.dir(foo);

// 생성자 함수 방식
function Person(name) {
    this.name = name;
}

var me = new Person('Lee');
console.dir(me);