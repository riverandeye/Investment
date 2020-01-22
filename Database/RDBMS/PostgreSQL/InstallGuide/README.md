# PostgreSQL InstallGuide

> PostgreSQL 을 설치 및 초기화하는 방법을 작성합니다.



### 설치 

```shell
sudo apt update
sudo apt install postgresql postgresql-contrib
```



### Role

PostgreSQL엔 해당 DB 서버에 접근할 수 있는 '권한'을 가진 사용자 혹은 그룹만이 접근할 수 있다. Document엔 role과 user는 alias라고 하지만, user는 login을 전제로 하고 있다는 차이만 존재하다. role을 생성한 후, 사용자에게 해당 role을 지정해보자.



**[cli를 통해 생성](https://www.postgresql.org/docs/9.1/app-createuser.html)**

```
createuser --interactive
Shall the new role be a superuser? (y/n) n
Shall the new role be allowed to create databases? (y/n) y
Shall the new role be allowed to create more new roles? (y/n) n
```

해당 명령어를 이용하여 role을 생성하였으면, `psql` 명령어로 postgresql 를 실행한 후 role의 목록을 확인할 수 있다.



![image-20200122133942691](C:\Users\tony0\Desktop\github\Investment\Database\RDBMS\PostgreSQL\InstallGuide\images\image-20200122133942691.png)



**[DB 명령어를 통해 생성](https://www.postgresql.org/docs/8.0/sql-createuser.html)**

```
CREATE ROLE demo_role;
```

DB 명령어로도 생성할 수 있다. 



![image-20200122134223036](C:\Users\tony0\Desktop\github\Investment\Database\RDBMS\PostgreSQL\InstallGuide\images\image-20200122134223036.png)



### [Role 삭제](https://www.postgresql.org/docs/9.4/sql-dropuser.html)

```
DROP ROLE <rolename>
```



### [Role에 권한 부여](https://www.postgresql.org/docs/9.0/sql-grant.html)

```
GRANT <privilege> TO <table,view,database> TO <user>
```

가장 필요한 권한 부여는, 사용자가 해당 DB에 대한 모든 권한을 가지고 있는 경우일 것이다.



### [Role에 권한 수정](https://www.postgresql.org/docs/9.1/sql-alterrole.html)

```
ALTER ROLE name [ [ WITH ] option [ ... ] ]
```



ex) jiseongg user이 Create DB 로 설정된 권한을 제거하고 싶을 떄

ALTER ROLE jiseongg NOCREATEDB;



### Group 생성

모든 사용자들에 대해서 위 절차를 밟기에는 너무 시간 낭비같다. 그룹을 하나 만들어서, 모든 DB에 접근 할 수 있는 권한을 주는 것이 적절해 보인다. 그룹을 생성해보자.

```
CREATE GROUP <Group Name>;
```



### Group에 User 추가

```
ALTER GROUP <Group Name> ADD USER <user1>, <user2>, ....;
```



### Group에 권한 부여

위에서 Role에 권한 부여하듯 Grant ~ 하면 된다.

[좋은 문서](https://tableplus.com/blog/2018/04/postgresql-how-to-grant-access-to-users.html)가 있어 이를 참고하였다.



### 비밀번호 지정

```
ALTER User <Username> PASSWORD <PASSWORD>
```



### 서버 실행

```
service postgresql start
service postgresql status # (status 확인용)
```

 

### 서버 종료

```
service postgresql stop
```



### 서버에 접근 가능한 IP 설정

![image-20200122143511303](C:\Users\tony0\Desktop\github\Investment\Database\RDBMS\PostgreSQL\InstallGuide\images\image-20200122143511303.png)

이 위치가 postgresql 설정 파일의 위치이다. 여기서, listen_address를 지정해주면 해당 지정해준 address 에서 접근 할 수 있다. 우선 모든 곳에서 접근이 가능하게 끔 '*' 설정을 해주자.



```
listen_addresses = '*'    
```

서버를 재시작 한 후 접근하면 다른 오류가 발생할 것이다.

![image-20200122145356346](C:\Users\tony0\Desktop\github\Investment\Database\RDBMS\PostgreSQL\InstallGuide\images\image-20200122145356346.png)

pg_hba.conf 파일에 entry 설정이 되어있지 않다는 것이다. 해당 파일을 찾아서, 밑의 내용을 추가해주자.

```
host    all             all             0.0.0.0/0            md5
```

모든 host에 대해서, username과 password를 통한 접속이 가능하게끔 하겠다는 뜻이다.

pg_hba.conf 에 대한 내용은 [여기](https://www.postgresql.org/docs/9.3/auth-pg-hba-conf.html)에서 확인할 수 있다.



### 원격에서 서버로 접근하기

```
psql -U <username> -h 106.10.53.228 -p 5432 <database>
```

하하 잘된다. 해피해피.



