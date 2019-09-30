# debug

> nodejs 디버그 모듈



### Introduction

nodejs 의 디버깅 할 때 console에 대신 찍어주는 아주 편리하고 강력한 모듈이다. 대부분의 패키지에 내장되어 있어 사용법을 미리 숙지해 두는 것이 좋다.



![](Images/1569767663065.PNG)

수많은 프로그램이 위 모듈을 사용하여 디버깅을 지원한다.



**Example**

```javascript
const debug = require('debug')('hello');
const debug2 = require('debug')('dello');

function smth(){
    debug('hello %O 안녕', {
        h:'e',
        he:[1,2,3,4,5],
    });
    debug2("hiiiiahhhh");
}

smth();
```

debug 메소드를 가져온 후 이름을 지정해준다. 나중에 환경변수에 DEBUG = '이름' 에 넣을 namespace 에 해당하는 디버그 함수만 작동되어 콘솔에 남겨진다.



**실행하기**

Powershell : `$env:DEBUG='hello'; node index.js`

Window,  : `set DEBUG=* & node app.js`



앱을 실행할 때 `DEBUG` 환경 변수를 설정해주어야 해당 namespace의 메소드만 실행된다.

위 코드를 실행하면 이와 같이 콘솔에 작성된다.

```
hello hello { h: 'e', he: [ 1, 2, 3, 4, 5 ] } 안녕 +0ms
```

`DEBUG=*'로 지정시 모든 namespace의 대상들을 지정할 수 있다.



**색깔 지정하기**

Debug 모듈의 색깔은 Namespace를 바탕으로 지정된다. Namespace에 따라 자동으로 색깔이 지정된다. 원한다면 [supports-color](https://www.npmjs.com/package/supports-color) 를 이용하여 원하는 색깔을 지정해주자.



### Reference

**npm** : https://www.npmjs.com/package/debug