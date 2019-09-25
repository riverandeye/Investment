# MySQL in NodeJS

> Node에서 MySQL을 연동하고 적절하게 사용하는 방법을 기록합니다.



**설치**

`npm install mysql --save`



**모듈 가져오기**

```javascript
const mysql = require('mysql2');
```



**Connection 생성**

```js
const db = mysql.createConnection({
    host: process.env.DB_HOST,
    user: process.env.DB_USER,
    port: process.env.DB_PORT,
    database: process.env.DB_DATABASE,
    password: process.env.DB_PASSWORD
});
```



**단일 Connection 을 이용하여 쿼리 날리고 데이터 받기**

```js
// const db = mysql.createConnection...
async function getdata(){
    const [rows, fields] = await db.promise().execute( 
        'SELECT * FROM `Card`' // Query
    );
    return rows;
}
```

db.execute를 그대로 사용하면, 내부 콜백에 rows와 fields가 input으로 들어가는 형태이다. 

promise() 메소드를 지원하기 때문에 이를 이용하면 코드가 깔끔해진다.



**Pool 생성**

```js
const db = mysql.createPool({
    host: process.env.DB_HOST,
    user: process.env.DB_USER,
    port: process.env.DB_PORT,
    database: process.env.DB_DATABASE,
    password: process.env.DB_PASSWORD
});
```

Connection의 Pool을 리턴하는 함수이다. DB가 여러 쿼리를 동시에 작업하기 위해서 Thread Pool 처럼 Connection의 Pool을 만든다. Thread Pool에 요청이 들어오면 Pool의 잉여 Connection에게 요청하고, 쿼리를 처리하면 다시 Pool로 들어온다.



**Pool에서 개별 Connection 리턴받기**

```js
// const db = mysql.createPool ... 
async function getConnection(){
    return new Promise(
        (resolve, reject)=>{
            db.getConnection(
                (err, connection)=>{
                    !err ? resolve(connection) : reject(err);
                }
            )
        }
    )
}
```

Pool에서 getConnection은 Promise를 리턴하지 않고 콜백에 해당 err와 Connection을 리턴하는데, 이와 같이 Promise를 리턴하는 함수로 감싸주고 connection과 error를 resolve 하게 되면 await을 사용하기 편하다.



```javascript
async function getData(){
    const connection = await getConnection();
    const [rows, fields] = await connection.promise().execute(
        'SELECT * FROM `Card`'
    )
    console.log(rows); // datas..
    connection.release();
}
getData();
```

이와 같이 Connection을 가져오는 함수가 매우 깔끔해진다.

그런데 사실 굳이 release와 connection을 직접 해줄 필요 없고, query 메소드를 사용하면 더 쉽다.



```js
async function getData(){
    const data = await db.promise().query('SELECT * FROM `Card`');
    console.log(data);
}
getData();
```

정말 깔끔한 코드가 아닐수 없다.

\