# JSON WEB TOKEN

> JWT에 대해 설명합니다.



#### Introduction

**토큰 기반 인증**



![](https://velopert.com/wp-content/uploads/2016/12/bb.png)



위와 같이 서버 기반 인증 시스템은 대부분 사용자의 접속 상태를 세션으로 관리하는 식이였다. 

여러 단점이 있다.

- 서버가 여러대일 경우 세션을 서버간 동기화해주어야 한다.  

- 쿠키를 사용자가 변경할 수 있어 보안상 취약하며, 단일 및 서브 도메인에만 작동하여 확장성이 부족하다.



#### 토큰의 장점

- **Stateless** - 서버가 상태를 가지고 있지 않고, 토큰을 클라이언트에서 저장한다. 세션을 유지한다면 유지한 서버로만 요청을 해야하는데, 토큰을 갖고 있으면 그렇지 않아도 된다.

- 쿠키를 사용하지 않음으로써 취약점이 줄어든다.

- 로그인 정보(토큰)를 이용하는 분야를 확장할 수 있다.

  - 토큰에 선택적인 권한만 부여하여 발급할 수 있다.

- 어떤 디바이스나 도메인에서도 토큰만 유효한다면 요청이 정상적으로 처리된다.

  - 서버의 응답에 다음과 같은 부분을 추가해주면 된다.

    ```shell
    Access-Control-Allow-Origin: *
    ```

    [참고]( https://developer.mozilla.org/ko/docs/Web/HTTP/Access_control_CORS )



#### JSON WEB TOKEN

JWT는 **Header, Payload, Signiture** 이 3개의 부분으로 이루어져있고, `.`으로 나누어져 있다. 그래서 일반적으로 ` xxxxx.yyyyy.zzzzz `와 같은 양식으로 되어있다.



**Header**

- 토큰 타입, 알고리즘을 담는다.

  ```javascript
  {
    "alg": "HS256",
    "typ": "JWT"
  }
  ```

- **Base64Url** 로 인코딩되어 JWT의 첫번쨰 부분을 차지하게 된다.



**Payload**

- claims 들을 보관한다. claim 이란 entity나 추가적인 data에 관한 statement 이다. 
- claim의 type 3가지
  - registered -  사용하길 권장하는 claim
    - iss(issuer) - JWT를 발행한 주체
    - exp(expiration time) - 
    - sub(subject) - JWT의 대상자가 되는 주체 
      - 일반적으로 JWT의 claims는 subject에 대한 것들이다.
      - issuer의 context에서 unique 하거나 global하게 unigue 한 대상이여야 한다.
    - aud(audience) - 토큰을 받아들이는 대상자들 (주로 Resource server)
  - public
    - 공개적으로 관계가 명시된 claim들 , 충돌을 막기 위해 [여기]( https://www.iana.org/assignments/jwt/jwt.xhtml )에 있는 claim 이름을 사용해야 한다.
  - private
    - 공개되지 않은 claim들. 클라이언트와 서버간 합의가 된 것들만 주로 지정한다. 
- **Base64Url** 로 인코딩되어 JWT의 두번쨰 부분을 차지하게 된다.

- **누구나 읽을수 있는 정보이기 때문에 중요한 정보를 그대로 넣어서는 안된다.**



**Signature**

헤더, payload, secret, 알고리즘을 이용하여 sign한다.

```hash
HMACSHA256(
  base64UrlEncode(header) + "." +
  base64UrlEncode(payload),
  secret)
```

이와 같은 방식으로 signature가 생성될 것이다. secret 변수에 해당하는 값은 서버에 저장되어 있다.



#### JWT 동작 방식

사용자가 로그인에 성공하면 JWT가 리턴이 되고, 



#### Reference

[VELOPERT](https://velopert.com/2350) : JWT 토큰 기반 인증 소개

[VELOPERT]( https://velopert.com/2389 ) : JWT 구조

[공식문서]( https://jwt.io/introduction/ )

[JWT 공식 문서]( https://tools.ietf.org/html/rfc7519#section-4.1 )

