# New Features



### MAP

- Element에 일괄적으로 함수를 적용해주는 메소드이다

```javascript
var arr = ['hello', 'everyone', 'we are', 'young'];
var arr2 = arr.map(function (str){return str.length;});
console.log(arr2) // [5,8,6,5];
```

- Array 자료형인 arr 내에 존재하는 모든 element에 대해 콜백함수의 리턴을 모아 만든 새로운 배열을 나타내는 Array를 arr2에 저장하였다.
- MAP 메소드는 어떤 array에 있는 element에 모두 같은 함수를 적용시키고, 기존 array는 손상시키지 않는다.

