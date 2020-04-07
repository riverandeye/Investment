# Maven Build Profiles

> Production과 Develop 과 같은 서로 다른 환경에서 빌드를 Customize 해보자.



#### Introduction

- 메이븐은 portability가 매우 높지만, dependency set이 상황별로 다른 경우가 있을 수도 있고, plugin이 local filesystem에 의존적인 경우가 있을 수도 있다.
- 위와 같은 경우를 위해, build Profile이 존재한다.
- Profile은 빌드 시간에 POM을 변경하며, 동일한 구성이지만 target environment가 다른 경우를 위해 사용된다.



#### Different types of Profile

- 프로젝트 단위 - pom.xml에 정의됨
- User 단위 - Maven setting 에 정의됨 `(%USER_HOME%/.m2/settings.xml)`
- Global - global Maven setting에 정의됨 `(${maven.home}/conf/settings.xml)`

- Profile Descriptor - project의 basedir의 **profiles.xml**에 정의됨.



#### How to trigger Profile?

- Explicitly -> command console의 input으로 사용
- Through Maven settings
- Based on environment variables
- OS settings
- Present or missing files



#### Reference

- https://www.tutorialspoint.com/maven/maven_build_profiles.htm

