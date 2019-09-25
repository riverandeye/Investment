# Dotenv

> 환경변수를 저장할 때 사용하는 패키지이다.

​	

> 설치

```
npm install dotenv --save
```



> 사용법

기본 디렉토리에 .env 파일을 만들고, 내용을 작성한다.

```
DB_HOST=101.33.63.238
DB_USER=test
DB_PORT=3306
```



dotenv를 import하고, config 메소드 안에 .env 파일의 path를 지정해준다.

```
require('dotenv').config({path : `../../.env`});
```



process.env에서 해당 변수를 사용하면 된다. 밑은 DB의 예시이다.

```js
const mysql = require('mysql2');
require('dotenv').config({path : `../../.env`});

console.log(process.env.DB_HOST);

const db = mysql.createConnection({
    host: process.env.DB_HOST,
    user: process.env.DB_USER,
    port: process.env.DB_PORT,
    database: process.env.DB_DATABASE,
    password: process.env.DB_PASSWORD
});

module.exports = db;
```

이와 같이 하면, 코드상에 값을 그대로 노출하지 않고 개인정보를 보호할 수 있다