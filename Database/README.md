# DBMS



**Data , Database , DBMS**

- Data : 기록 할 수 있는 정보
- Database : 정보를 저장하는 공간
- Database Management System : 정보를 관리하는 시스템



**Data, Information, Knowledge, Wisdom**



![](https://firebasestorage.googleapis.com/v0/b/nextstep-real.appspot.com/o/lesson-attachments%2F-L37_Tjm0PE9J7DmPxKx%2F1280px-DIKW_Pyramid.svg.png?alt=media&token=cb1b93f1-f648-4796-9c17-7289ed27af64)



**Information - Data 를 가공하여 얻은 유의한 정보**

**Knowledge -  Information을 모아 얻어진 조금 더 보편화된 지식**

**Wisdom - 내어다보는 것**



**Key Point of Database**

- 필요한 정보만을 최소한으로 저장한다.



**RDBMS**

- Relational Database Management System

- 객체간의 관계로 데이터를 정의하는 방식
- 오라클, MySQL, MS-Server, PostgreSQL



**SQL**

- Structured Query Language
- 선언적 언어 (무엇을 해주세요! 라고 선언하는 언어)
  - 어떻게 하는지는 모른다.
- RDBMS 제어에 사용됨



**NOSQL**

- 관계형 DB가 아닌 나머지



**관련 용어**

**CAP**

- Consistency, Availability, Partition Tolerence

- Consistency : 같은 요청에 같은 응답을 하는 것.
  - 분산 시스템 간 데이터 동기화가 잘 되어야 함.
- Availability : 언제나 응답을 주는 서비스 (가용성)
  - 100%의 Availability - 서버가 항상 다운되지 않고 접근 가능.
- Partition Tolerence : 어떤 서버가 날라가도 다른 시스템엔 영향을 주지 않는 것

- 이상적인 정의, 최근엔 Consistency를 희생하는 방식으로.
  - Eventual Consistency -> 일정 시간 후에 Consistency 보장.



 **ACID**

- Atomicity : Transaction이 All or Not 방식으로 작동. 
  - 전부다 수행되거나, 아무것도 하지 않거나.
- Consistency : 
- Isolation
- Durability :  



**확장성**

- 수직 확장 : SQL
- 수평 확장 : NOSQL



**SQL VS NOSQL**

SQL -> ACID 중시

NOSQL -> CAP 중시



### Read Replica

- 백업과 성능향상을 위해서 데이터베이스를 여러대의 서버에 복제하는 행위
- 서버에 Read 요청이 많은 경우, Read용 DB를 복제하여 동기화.



### SQL 설치

- root 접속은 sudo를 통해 접속해야 한다.
- password 분실시 새로 설치가 빠르다.



### 기타

- 각각의 Application 마다 DB를 따로 만드는 것이 일반적이다.