# Express

> Express 프레임워크에 대해 정리합니다.



### Introduction

Express는 Node.js 의 웹 프레임워크 입니다. Express를 통해 편하게 웹 서버를 구축할 수 있습니다.

설치 및 기본적인 사항들은 [여기](https://expressjs.com/ko/starter/hello-world.html)에서 확인해주세요.

이해에 도움이 되는 메소드에 대한 구체적인 설명은 아래에 달아놨습니다.



### Initialize 



초기화는 다음과 같이 진행됩니다.

```javascript
const express = require('express')
const app = express()

app.get('/', (req, res) => res.send('Hello World!'))

app.listen(3000, () => console.log('Example app listening on port 3000!'))
```

express 모듈을 이용하여 라우터를 설정하고 HTTP 서버를 띄우는 가장 기초가 되는 코드입니다. 



express() 가 실행되면,  아래 함수가 실행됩니다.

```javascript
var proto = require('./application');
// ...
function createApplication() {
  var app = function(req, res, next) {
    app.handle(req, res, next);
  };

  mixin(app, EventEmitter.prototype, false);
  mixin(app, proto, false);

  // expose the prototype that will get set on requests
  app.request = Object.create(req, {
    app: { configurable: true, enumerable: true, writable: true, value: app }
  })

  // expose the prototype that will get set on responses
  app.response = Object.create(res, {
    app: { configurable: true, enumerable: true, writable: true, value: app }
  })

  app.init();
  return app;
}
```



app은 mixin 함수를 통해 EventEmitter와 proto를 상속받으며, request와 response 프로퍼티를 객체로 선언합니다.   **init 함수는 mixin을 통해 proto에서 전달받은 프로퍼티입니다.**

[mixin 참고](https://github.com/riverandeye/Investment/tree/master/Programming_Languages/JavaScript/Nodejs/Fundamentals/merge-descriptors)



```javascript
app.init = function init() {
  this.cache = {};
  this.engines = {};
  this.settings = {};

  this.defaultConfiguration();
};
```

캐시, 엔진, 세팅 Property 를 빈 객체로 선언하고 defaultConfiguration을 수행합니다. **defaultConfiguration 함수는 mixin을 통해 proto에서 전달받은 프로퍼티입니다.**



```javascript
app.defaultConfiguration = function defaultConfiguration() {
  var env = process.env.NODE_ENV || 'development';

  // default settings
  this.enable('x-powered-by');
  this.set('etag', 'weak');
  this.set('env', env);
  this.set('query parser', 'extended');
  this.set('subdomain offset', 2);
  this.set('trust proxy', false);

  // trust proxy inherit back-compat
  Object.defineProperty(this.settings, trustProxyDefaultSymbol, {
    configurable: true,
    value: true
  });

  debug('booting in %s mode', env);

  this.on('mount', function onmount(parent) {
    // inherit trust proxy
    if (this.settings[trustProxyDefaultSymbol] === true
      && typeof parent.settings['trust proxy fn'] === 'function') {
      delete this.settings['trust proxy'];
      delete this.settings['trust proxy fn'];
    }

    // inherit protos
    setPrototypeOf(this.request, parent.request)
    setPrototypeOf(this.response, parent.response)
    setPrototypeOf(this.engines, parent.engines)
    setPrototypeOf(this.settings, parent.settings)
  });

  // setup locals
  this.locals = Object.create(null);

  // top-most app is mounted at /
  this.mountpath = '/';

  // default locals
  this.locals.settings = this.settings;

  // default configuration
  this.set('view', View);
  this.set('views', resolve('views'));
  this.set('jsonp callback name', 'callback');

  if (env === 'production') {
    this.enable('view cache');
  }

  Object.defineProperty(this, 'router', {
    get: function() {
      throw new Error('\'app.router\' is deprecated!\nPlease see the 3.x to 4.x migration guide for details on how to update your app.');
    }
  });
};
```

위 함수가 초기화 과정 중 마지막이 되는 함수입니다. 



### 기타 함수 설명



**app.set**

```javascript

app.set = function set(setting, val) {
  if (arguments.length === 1) {
    // app.get(setting)
    return this.settings[setting];
  }

  debug('set "%s" to %o', setting, val);

  // set value
  this.settings[setting] = val;

  // trigger matched settings
  switch (setting) {
    case 'etag':
      this.set('etag fn', compileETag(val));
      break;
    case 'query parser':
      this.set('query parser fn', compileQueryParser(val));
      break;
    case 'trust proxy':
      this.set('trust proxy fn', compileTrust(val));

      // trust proxy inherit back-compat
      Object.defineProperty(this.settings, trustProxyDefaultSymbol, {
        configurable: true,
        value: false
      });

      break;
  }

  return this;
};
```



**app.enable**

```javascript
app.enable = function enable(setting) {
  return this.set(setting, true);
};
```



**[Object.setPrototypeOf](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Object/setPrototypeOf)**





### Reference

**source code** : https://github.com/expressjs/express

