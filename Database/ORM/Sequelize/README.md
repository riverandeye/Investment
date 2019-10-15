# Sequelize

> Sequelize 에 대해서 설명합니다.



#### Introduction

Sequelize는 nodejs의 ORM 패키지입니다. 다양한 dialect를 지원하며 사용성이 좋아 사랑받는 패키지입니다.



#### 설치

```javascript
npm install --save mysql2 // 다른 db를 사용해도 됨
npm install --save sequelize
npm install --save dotenv
```



#### 연결

```javascript
require('dotenv').config();

const { Sequelize, Model, DataTypes } = require('sequelize');
const mysql2 = require('mysql2');

const sequelize = new Sequelize(
  process.env.DB_DATABASE,
  process.env.DB_USER,
  process.env.DB_PASSWORD,
  {
    dialect: 'mysql', // 다른 dialect를 선택할 수 있다.
    dialectModule: mysql2, // 입력한 dialect에 대한 모듈을 import 해주어야 한다.
    host: process.env.DB_HOST,
    port: process.env.DB_PORT
  }
);
```

dotenv에 아래와 같은 환경 변수들을 설정해주고, Sequelize 객체를 생성해준다.  



#### 모델 정의

```javascript
class User extends Model {}
const UserTable = {
    username: DataTypes.STRING,
    birthday: DataTypes.DATE
  },
User.init(
  UserTable,
  { sequelize, modelName: 'user' }
);
```

User.init의 인자로 첫번째는 Table Object를 , 두번째로는 sequelize 객체를 전달한다.



#### Foreign key 관계 지정

```javascript
User.hasMany(Property);
User.hasMany(Reservation);
Property.hasMany(Reservation);
```





**DB 동기화**

연결 후에 해당 모델을 DB와 동기화 하여야 DB를 최신 상태로 업데이트 할 수 있다.



#### Reference

[공식 문서](https://sequelize.org/master/)

