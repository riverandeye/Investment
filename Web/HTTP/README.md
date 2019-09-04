# HTTP Protocol



**Web** 이란 결국 수도 없이 분산된 Client/Server 간 정보 전달 시스템을 의미한다. 적절한 communication을 위해 어플리케이션 단위의 프로토콜(HTTP, FTP, SMTP, POP) 등을 채택한다.



**HTTP**는 HTML 등 하이퍼미디어 문서를 전송하기위한 **어플리케이션 레이어** 프로토콜이다. 클라이언트와 서버간 asymmetric한 request-response를 하는데, client가 request를, server가 response를 하는 입장이며, 항상 client가 pull 하는 구조를 가지고 있다.

HTTP는 **Stateless protocol**인데, 이는 request간 독립적이며, 각 request간 서로의 존재에 대해 전혀 모른다.

전송되는 데이터와는 관계없이 Generic한 데이터 전달을 통해, develop 되는 시스템이 전달하는 데이터 양식에 구애받지 않게끔 구성되게 한다.



### Browser

브라우저에게 url을 전달하면, 브라우저는 해당 url을 전달받아 리퀘스트 메세지를 작성하여 HTTP 서버로 전달한다. 



### URL

URL은 Uniform Resource Locator의 약자이며, 웹 상의 리소스의 고유한 ID이고, 이를 통해 해당 리소스의 위치를 알 수 있다.

URL은 네 부위로 나뉜다.

1. 프로토콜 : 클라이언트와 서버 간 사용되는 application level 프로토콜
2. 호스트명 : DNS 도메인 이름 (e.g www.naver.com) 이나 IP 주소
3. Port : 해당 서버가 해당 request가 들어오도록 열어놓은 포트
4. path and file name : 서버의 base directory에 대한 해당 리소스의 위치와 이름



### HTTP Protocol

URL을 브라우저에 입력하면, 브라우저는 URL을 받아 request message를 형성하고, 리퀘스트 메세지를 서버로 보낸다.



![1567606824578](Images/1.PNG)

www.naver.com 을 chrome URL에 작성할 시 Network에서 이 내용을 확인 할 수 있다. Chrome 브라우저는 이와 같이 리퀘스트를 형성한다.



이러한 리퀘스트가 올 때, **<수정요망>**



### HTTP Request

![http requests](http://public.codesquad.kr/honux/images/w303.png)

- Request line엔 Request method, 요청 URL, HTTP 버전을 입력한다.
- Header엔 host, connection 등의 정보가 담겨있다.
- Request Message Body에는 POST 방식을 예로 하면 여기에 정보가 key value pair로 구성되어 들어간다. (GET은 url에)



### HTTP Response

![](https://tramyu.github.io/images/etc/image-20180603203355021.png)

- Status line 엔 프로토콜, request status code 가 전달된다.
- Response Header엔 부차적인 정보가 담겨있다.
- Response Message Body엔 요청한 정보가 담겨 들어온다. 
- Header와 Body는 한 줄 떨어져 작성되어 있다.



### Response Message (중요한 것만)

**General**

- Class 1xx - informational : request가 진행중임을 알림. 
- Class 2xx - Success : request가 server에 전달되고, 수용됨을 알림.
- Class 3xx - Redirection : request가 전달됨을 의미, 주로 redirection 시 등장함.

- Class 4xx - Client error : 전달 받았으나 incorrect request에 의해 수행할 수 없음을 의미. 
- Class 5xx - Server error : 서버가 전달받은 리퀘스트를 수행하는데 실패하였음을 의미.



**자주 뵐 분들**

- 100 Continue : 서버가 리퀘스트를 받았고 response를 할 것임을 의미
- 200 OK : request가 완료됨을 의미
- 301 Move Permanently : 리퀘스트에 해당하는 정보가 영구적으로 다른 주소로 옮겨졌음을 의미. 이때 클라이언트는 새 주소로 request를 업데이트 해야 함.
- 302 Found & Redirect : 새 주소로 옮겨졌지만 임시로 옮겨진 것이다. 



Response Message Header**

- **Status Line**





















### Reference

- https://developer.mozilla.org/ko/docs/Web/HTTP/Overview
- https://www.ntu.edu.sg/home/ehchua/programming/webprogramming/HTTP_Basics.html