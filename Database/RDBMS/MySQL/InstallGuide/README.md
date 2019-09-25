

# MySQL 설치

> MySQL을 설치해보자



## Linux

> 일반적으로 클라우드에서 Linux 운영체제를 많이 선택합니다.



### 최초 접속 후 우분투 패키지 업그레이드 및 한글 설정

```
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install language-pack-ko
$ sudo locale-gen ko_KR.UTF-8
```



### 이어서 한글 로케일 설정

```
$ locale
$ sudo -i
$ cat << 'EOF' > /etc/default/locale
LANG="ko_KR.UTF-8"
LANGUAGE="ko_KR:ko:en_US:en"
EOF
```

- bash 재시작 후 확인

```
$ locale
```



### mysql 설치

- 중간에 root password를 꼭 넣어주어야 합니다.
- 패스워드 분실시 새로 설치가 빠름 (클라우드라서)
- OS 버전과 MySQL 버전에 따라 설치방법이 달라질 수 있으므로 검색을 활용한다.



------



### 버전별 참고 링크

- https://www.digitalocean.com/community/tutorials/how-to-install-mysql-on-ubuntu-18-04
- https://www.digitalocean.com/community/tutorials/how-to-install-mysql-on-ubuntu-16-04



 설치시 꼭 암호를 작성해줍니다.

------



### 설치 스크립트

```
$ sudo apt install mysql-server
$ sudo systemctl start mysql
$ sudo mysql_secure_installation
```



### 18.04 root 접속

18.04 기준으로 auth socket을 이용해서 root 접속을 하게 되었다.

```
# root 접속
$ sudo mysql
mysql> quit
```

------



### utf-8 설정

- 리눅스의 경우 초기 설정은 latin1으로 되어 있는 경우가 많다.
- 한글 처리를 위해 utf8로 설정을 바꾸는 편이 좋다.

```
mysql> status
```



---------------------------



```bash
$ sudo -i #root
$ cat /etc/mysql/my.cnf
$ cat << 'EOF' > /etc/mysql/mysql.conf.d/utf8.cnf
# for utf8 characterset
[client]
default-character-set = utf8

[mysqld]
init_connect = SET collation_connection = utf8_general_ci
init_connect = SET NAMES utf8
character-set-server = utf8
collation-server = utf8_general_ci

[mysqldump]
default-character-set = utf8

[mysql]
default-character-set = utf8
EOF
```



------



```
$ cat /etc/mysql/mysql.conf.d/utf8.cnf
# ctrl + d 로 root 로그아웃, 일반 사용자로 돌아옴
$ sudo systemctl restart mysql
$ sudo mysql
mysql> status
```



------



### 일반사용자 외부 접속 허용

```bash
$ sudo -i
$ cd /etc/mysql
$ grep -r 'bind'
# bind-adress=127.0.0.1 내용 주석처리 (앞에 #을 붙임)
$ cd /etc/mysql/mysql.conf.d
$ sed -i 's/bind/# bind/' mysqld.cnf
$ cat mysqld.cnf | grep bind
$ sudo systemctl restart mysql
$ exit
```

- 주의: root 사용자의 외부 접속은 허용하면 안 됩니다.

  

------



### 재부팅시 mysqld 자동 실행

```bash
$ sudo reboot
$ mysql -u root -p 
$ sudo update-rc.d mysql defaults
# 자동 실행 취소 명령 (참고용, 타이핑하지 마세요)
# sudo update-rc.d mysql remove  
$ sudo reboot
$ mysql -u root -p
```

------



### 데이터베이스 및 일반 사용자 생성

```sql
CREATE DATABASE mydb;
--- 아이디 및 패스워드 설정
CREATE USER 'myuserid'@'%' IDENTIFIED BY 'mypassword';
GRANT ALL ON mydb.* TO 'myuserid'@'%';
FLUSH PRIVILEGES;
```

`mydb`: 데이터베이스 이름

`myuserid`: 사용자 id

`mypassword`: 사용자 패스워드



------



### 사용자 패스워드가 생각나지 않을 때

루트 사용자로 로그인 후 일반 사용자 패스워드는 쉽게 변경 가능

```
SET PASSWORD FOR 'honux'@'%'='new_password';
FLUSH PRIVILEGES;
```



--------



### security group 설정

- mysql (inbound, 3306, any address) 로 허용해 줘야 합니다.



------

### GUI 이용 접속

### workbench

https://www.mysql.com/products/workbench/

https://www.sequelpro.com/

http://www.heidisql.com/



### 참고자료

- https://dev.mysql.com/doc/refman/5.7/en/
- https://www.digitalocean.com/community/tutorials/how-to-install-mysql-on-ubuntu-18-04
  