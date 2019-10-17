# Oauth 2.0

> Oauth 에 대해서 설명합니다.



#### Introduction

Oauth는 별도의 인증 절차로 외부 서비스에서도 사용자에게 필요한 일부 기능을 사용할 수 있게끔 하는 Open standard protocol 입니다.

Oauth 2.0에선 보호된 자원에 접근하기 위해 Access Token을 사용하는데, 이 형식은 Default로 [**JWT**]( https://github.com/riverandeye/Investment/tree/master/Web/JWT ) 형식을 따르고 있다.



#### Roles

- **Resource Owner**: **end user** , **application**, **security policy** 등 보호된 자원에 access를 허락해줄 수 있는 대상들을 의미한다. 
- **Resource Server**: 보호된 자원을 호스팅하는 서버 (접근하고 싶어하는 **API**), 자원을 주거나 보호하는 역할을 한다.
- **Client**: 보호된 자원에 request를 날리는 대상. resource owner에게 권한을 받고 api에 call을 날리는 대상을 의미한다.
- **Authorization Server**: resource owner에 의해 authenticate가 되면, access token을 제공하는 역할을 한다.



#### Protocol

**generic** 한 flow의 예시를 보자.

![](https://cdn2.auth0.com/docs/media/articles/protocols/oauth2-generic-flow.png)

1. Client가 Resource Owner에게 authorization을 요청한다.
2. Resource Owner가 access를 허가하면, **Authorization Grant**를 받는다. 
3. Client는 이 **Authorization Grant** 를 Authorization Server에 제출하여 그에 해당하는 **Access Token**을 받는다.
4. Client는 이 **Access Token** 을 이용하여 Resource Server에 protected resource를 요청한다.
5. **Access Token**이 valid 할 시 Resource Server는 요청한 자원을 지급받는다.



#### Reference

- [auth0 docs]( https://auth0.com/docs/protocols/oauth2 )