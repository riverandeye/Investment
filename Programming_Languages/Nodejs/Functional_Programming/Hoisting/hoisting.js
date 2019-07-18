/* hoisting variable*/

/* var defined value is hoisted */
console.log(C); 
var C = "hello"; // undefined

/* let defined value is not hoisted */
// console.log(D); // Error
// let D = "hello";

/* const defined value is not hoisted */
// console.log(E); // Error
// const E = "hello";

/* Global defined value is not hoisted */
// console.log(F); // Error
// F = "hello";

/* function declaration is hoisted + initialization*/
hello();
function hello(){
    console.log("hello");
}

/* function expression is not hoisted */
// nothello(); // Error
var nothello = function(){
    console.log("nothello");
}