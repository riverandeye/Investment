# Maven

> Maven에 대해 정리합니다.



### 빌드란?

빌드란 소스 코드를 컴파일 등의 작업을 거쳐 최종적인 실행 파일로 만드는 작업이다. 자바 파일을 컴파일하여 적절한 단위로 JAR 파일로 합친 후, 경우에 따라 스크립트나 설정 파일을 부여하여 다른 시스템에서 실행 가능한 파일의 세트를 만드는 작업이다.

빌드 작업은 JDK의 명령으로 누구나 실행 할 수 있지만, 작업 순서를 빼먹어 제대로 동작하지 않는 파일이 만들어지는 것을 방지하기 위해 빌드용 도구로 불리는 소프트웨어가 존재한다.

자바에서는 Ant, Maven, Gradle이 대표적인 빌드 자동화 도구이다.



### MAVEN의 정의 및 특징

메이븐은 5가지 목표가

- Making the build process easy
  - 세부 과정에 대한 이해는 동반하지만, 불필요한 디테일은 드러내지 않음.
- Providing a uniform build system
  - POM(Project Object Model)과 Maven의 모든 프로젝트에 사용되는 플러그인을 이용하여 동일한 빌드 시스템을 구성한다. 메이븐의 빌드 과정을 하나만 이해해도 모든 프로젝트를 쉽게 이해한다.
- Providing quality project information
- Providing guidelines for best practices development
- Allowing transparent migration to new features

뭐 그렇다.. 당장 모든걸 짚고 넘어갈 필요는 없어보인다.

- 메이븐은 프로젝트의 전체적인 라이프 사이클을 관리하는 도구 이다.
- pom.xml에 필요한 라이브러리르 정의해놓으면 해당 라이브러리와 라이브러리가 의존하는 다른 라이브러리까지 네트워크를 통하여 자동으로 다운받아준다.
- Maven은 중앙 저장소를 통한 자동 의존성 관리를 한다. 중앙 저장소(아파치재단에서 운영 관리)는 라이브러리를 공유하는 파일 서버라고 볼 수 있고, 자기 회사만의 중앙 저장소를 구축할수도 있다.
- 간단한 설정을 통한 배포 관리가 가능 하다.



#### Maven Lifecycle

Maven에서는 default, clean, site의 세 가지 build Lifecycle을 제공하고 있다.

- default : project deployment
- clean : project cleaning
- site : creation of your project's site documentation



**Phase of Build Lifecycle**

각각의 라이프사이클은 phase로 구성되며, phase는 각 lifecycle의 stage를 의미한다.

- validate - pom.xml 에 작성된 프로젝트에 대한 내용이 적합한지 확인
- compile - 소스코드를 컴파일 한다.
- test - 컴파일된 소스코드를 단위 테스트 프레임워크를 이용하여 테스트한다. 패키지 혹은 deploy 되는 코드가 요구되지 않는다.
- package - 컴파일된 코드를 패키징하여 JAR 파일과 같은 포멧으로 만든다.
- verify - Integration 결과물이 적합한지 테스트한다.
- install - 로컬 저장소에 필요한 패키지를 설치한다.
- deploy - 빌드가 긑나고 결과 패키지를 remote repository에 옮겨 배포한다.



default 라이프사이클을 이용하면 이러한 과정을 거치게 될 것이다. 만약 cli를 이용하여 빌드한다면 이런 라이프사이클을 command line에 작성하는 식으로 동작을 하게 될 것이다.



**Plugin Goals**

Build Phase는 Goals 들로 이루어져 있고, Maven goals는 프로젝트의 빌드와 관리에 있어 필요한 특정 작업을 의미한다. 각 phase는 믈론 default goal을 수행하는 것이 된다. 이부분은 아직 잘 모르겠어서 나중에 다시 정리해야겠다.



#### POM 이란

pom.xml 파일은 메이븐의 핵심 설정 파일이다. 메이븐의 빌드 과정에 필요한 정보 및 기본 값들을 담는다. task나 goal을 수행할 때 maven은 현재 디렉토리의 pom을 읽고 설정값들을 가져온다.

기본 설정값

- 빌드 디렉토리 : target
- 소스 디렉토리 : src/main/java
- 테스트 소스 디렉토리 : src/test/java



**SUPER POM**

Super POM 은 메이븐의 기본 POM으로, 모든 POM은 명시하지 않는 한 이 설정을 extend하여 사용한다. 그 값은 [여기](http://maven.apache.org/guides/introduction/introduction-to-the-pom.html)를 참고하도록 하자.



**Minimal Requirement**

POM을 구성하는 최소한의 정보는 다음과 같다.

- project root
- modelVersion - 4.0.0 으로 고정!
- groupId - 프로젝트 그룹 Id
- artifactId - artifact(project)의 Id
- version - 버전정보



**Project Inheritance**

POM을 상속하여 기존의 설정을 그대로 가져온 후 extend할 수 있다.



```xml
<parent>
  <groupId>org.springframework.boot</groupId>
  <artifactId>spring-boot-starter-parent</artifactId>
  <version>2.2.5.RELEASE</version>
  <relativePath/> <!-- lookup parent from repository -->
</parent>
```

스프링 부트에 처음 제공되는 POM에 작성되어있는 것으로, 상속된 Parent의 설정을 그대로 가져온다.



### Reference

- 기초부터 실무 응용까지 자바 마스터북 (Jpub 출판사)
- 메이븐이란 : https://maven.apache.org/what-is-maven.html
- 메이븐이란 : https://goddaehee.tistory.com/199
- POM : http://maven.apache.org/guides/introduction/introduction-to-the-pom.html
