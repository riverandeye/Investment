

# MySQL

> 일반적으로 검색해서 바로 찾을 수 있는 정보보단, 새롭게 알게 된 정보를 저장합니다.



### Tutorial

[**Linux에서 설치하기**]('./InstallGuide')



**접속하기**

`mysql -u [username] -p`



### User 관련 유용한 명령어



**user 생성**

`CREATE USER 'myuserid'@'%' IDENTIFIED WITH mysql_native_password BY '1q2w3e!Q'`

WITH mysql_native_password 설정은 꼭 붙이지 않아도 되는데, 없이 하다가 nodejs 연결에서 에러가 발생했음.



**user에게 모든 db 및 테이블에 접근권한 주기 (로컬만)**

`mysql> grant all privileges on *.* to userid@host identified by 'password';`



**user에게 모든 db및 테이블 접근권한 주기 (로컬 및 리모트)**

`grant all privileges on *.* to userid@'%' identified by 'password';`



**user 권한 조회**

`show grants for userid@host`



**user 권한 삭제**

`revoke all on dbname.table from userid@host`



**user 제거**

`DROP USER ‘username’@‘localhost’;`



위에 2개 를 보면, `*.*`와 `'%'` 부분을 regex로 설정해주면 선택적으로 권한을 지급하는 것이 가능하다.



### Reference

https://www.fun25.co.kr/blog/mysql-grant-user-privileges/?category=001