# Merge-descriptors

> 수많은 패키지에 사용되는 기본 패키지 중 하나



여러 패키지에서 mixin이라는 변수명으로 import 되는 함수이다. 코드는 매우 간결하고, merge라는 함수가 export 되는데, 다음과 같다.



```javascript
function merge (dest, src, redefine) {
  ...(에러처리)

  Object.getOwnPropertyNames(src).forEach(function forEachOwnPropertyName (name) {
	if (redefine === undefined) {
		// Default to true
		redefine = true
   	}
    if (!redefine && hasOwnProperty.call(dest, name)) {
      // Skip descriptor
      return
    }
    // Copy descriptor
    var descriptor = Object.getOwnPropertyDescriptor(src, name)
    Object.defineProperty(dest, name, descriptor)
  })

  return dest
}
```



**dest** : src로부터 property를 상속받으려는 Object

**src** : property를 상속하려는 Object

**redefine** : 어떤 src의 Property가 dest에 존재하는 경우 해당 property를 src의 것으로 redefine 할지 안할지 설정해준다. (default : true)



단순히 메소드를 이전시켜주는 함수이다. Prototype 은 이전되지 않는다.



###  Reference

**구현체** : https://github.com/component/merge-descriptors/blob/master/index.js