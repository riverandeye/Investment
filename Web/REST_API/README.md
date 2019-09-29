# REST API

> REST API가 무엇이고, 진정한 REST가 무엇인지 정리합니다.



## 개요



**최근 웹 및 앱 개발은 프론트가 백엔드에서 제공하는 RESTful API 를 호출하는 경우가 많다.** -> 프론트, 백 모두 Restful API가 무엇인지 정확히 알아야 한다.



https://restapitutorial.com

### REST란

- Resource-based

  - API에선 Resource를 제공하지, action을 제공하지 않는다.
  - Resource는 독립적인 URI 로 Identify 된다.
    - 여러 URI가 같은 resource를 가리킬 수 있다.
  - Resource 와 Representation은 서로 분리되어 있다.

- Representation

  - Restful API에서 resource가 다루어지는 방법을 의미
  - resource state의 일부를 표현하며, client와 server 간 전달된다.
  - 일반적으로 JSON, XML 형태로 전달된다.

  예를 들어, Todd라는 person 리소스를 얻기 위해 우린 GET 방식의 contact information을 사용하고, Json이나 XML 형태로 이름, address, phone number 등이 전달 될 것이다.

- 6 Constraints

  - Uniform interface
    - 사용자와 클라이언트 간 interface가 정의되어야 한다.
      - HTTP verbs로 해당 resource에 접근하는 방법을 규정
      - URIs 와 verb를 규정하여 client가 server에게 request를 함. 
      - HTTP response로 status와 body에서 resource를 전달받음.
  -  Statelessness
    - Rest api의 server는 client의 state가 없어야 한다.
    - 각 request는 server에서 작동할 만큼의 충분한 정보를 포함해야 한다.
      - self descriptive message
    - client 가 보내는 정보에 모든 state가 담겨있어야 한다
      - HTTP verb , URI etc..
    - 물론 회원 인증이 필요한 경우엔 서버에서 세션 state가 필요 할 수도 있겠지만, 통상적으로는 그러한 경우에도 Restful 하다고 한다.

  - Client-server structure
    - client과 server간 단절된 시스템을 전제한다.
    - Uniform interface (HTTP)가 그 둘을 연결하는 Link 가 된다.
  - Cacheable
    - 모든 종류의 서버의 응답을 캐싱할 수 있어야 한다.
      - Implicitly - 그냥 저장.
      - Explicitly - 서버가 어떤 데이터를 클라이언트 측에 얼마나 보관할지 명시한다.
      - Negotiated - 서버랑 클라이언트랑 교류하여 정하는 것.
  -  Layered System
    - 클라이언트는 그냥 단순히 API를 알고, 어떤 형태의 representation이 돌아오는지 아는거지, 그게 어디서 누구한테 어떻게 오는지는 신경쓰지 않는다.
    - 클라이언트와 서버 간 middleware가 있을 수 있다.
    - 확장성이 증가한다.
  - Code On Demand
    - 서버가 클라이언트에게 logic을 전달할 수도 있다.
    - Optional Constraint이다.



**장점**

- Scalability, Simplicity, Modifiability, Visibility, Portability, Reliability



---------------



https://tv.naver.com/v/2292653

왜 **REST** 하지 못할까?

1) **Uniform interface** 를 잘 지키지 못한다.

- **Self-descriptive message** - 거의 지키지 못함

  - 메세지가 스스로 설명해야 한다.

  **ex )** GET / HTTP/1.1 - root를 가져오는 메시

  목적지가 빠져 있어서, self-descriptive 하지 못하다 >>

  GET / HTTP/1.1 - root

  Host : www.example.org

  **ex)** HTTP/1.1 200 OK [ {"op" : "remove", "path" : "a/b/c"} ]

  클라이언트가 이걸 받고 해석해야하는데, 어떤 문법으로 작성되었는지 content type이 명시되지 않아 이해하기 힘든 것.

  Content-Type: application/json-patch+json 을 추가해야 한다.

  json-patch+json 이라는 미디어 타입에 해당하는 명세에 찾아가서 그 명세를 이해해야 온전히 이해할 수 있다.

  **메시지를 봤을때 온전히 해석이 가능해야 하는데, 일반적으로 json으로 되어있지 이걸 보고 어떻게 해석해야 하는지는 모른다.**



2) **HATEOAS** 를 잘 지키지 않는다.

- HTTP 는 a tag와 같은 hyperlink로 상태를 전이시킬 수 있지만, JSON은 그렇지 않다.
- 그래서 JSON 내에 link를 달고, 해당 링크가 의미하는 것을 API Docs에 명세하여야 한다.



Uniform interface가 왜 필요하나

- **서버와 클라이언트가 독립적으로 진화하게끔 하기 위함.**
- 서버를 업데이트 해도 클라이언트를 업데이트 할 필요 없다.



웹 브라우저는 Rest를 잘 지키고 있는가?
* 웹 페이지를 변경했다고 해서 웹 브라우저를 업데이트할 필요 없다.
* 웹 브라우저를 업데이트했다고 해서 웹 페이지를 변경할 필요 없다.
* HTTP 명세가 변경되어도 웹은 잘 동작한다.
* HTML 명세가 변경되어도 웹은 잘 동작한다.
* 페이지가 깨지겠지만 최소한으로 동작한다.



Rest가 웹의 독립적 진화에 도움을 주었나
* HTTP에 지속적으로 영향을 줌
* Host 헤더 추가
* 길이 제한을 다루는 방법 명시
* URI에서 리소스의 정의가 추상적으로 변경됨



Rest API를 꼭 사용하여야 하나?

* **시스템 전체를 통제할 수 있거나, 진화에 관심이 없다면 REST를 굳이 쓰지 않아도 된다.**



## 예시





### Reference

https://restapitutorial.com

https://tv.naver.com/v/2292653

