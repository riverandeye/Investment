# HLS

> HTTP Live Streaming 프로토콜에 대해 다룹니다.



### Overview

HLS 프로토콜은 audio와 video를 HTTP 프로토콜을 통해 전송한다. 네트워크 환경에 최적화 된 영상 환경을 제공하기 위해 디자인되었다.

- VOD

- 비트레이트에 따른 스트림 조정
- 네트워크 대역폭에 따른 스트림 조정
- 미디어 암호화 및 사용자 인증을 제공



![Flow diagram showing the four parts of an HTTP Live Stream. The media recording is sent to a server, distributed over the web, and sent to the client app.](images/de18e941-81de-482f-843d-834a4dd3aa71.png)



### Understanding the HTTP Live Streaming Architecture

개념적으로 HLS는 3가지 파트로 이루어져 있다.

- 서버 컴포넌트
- 배포 컴포넌트
- 클라이언트

일반 설정에서는 audio-video를 input으로 받으면 이를 HCVE 및 AC-3 코덱으로 각각 video와 audio를 인코딩하여, 여러 조각의 MPEG-4와 MPEG-2 전송 스트림으로 변환한다.

stream segmenter는 스트림을 짧은 미디어 파일로 쪼개어 웹 서버에 배치한다. 또, 해당 미디어 파일의 목록을 포함하는 index file을 생성하고, web server엔 해당 index file이 serving 되는 것이다. 클라이언트는 해당 index를 읽고, 나열된 미디어 파일을 순서대로 segment 간 중지 없이 요청하고 보여주는 것이다.



**Server Component**

서버 컴포넌트는 입력 스트림을 인코딩하며, 배포하기 쉬운 형태로 압축하여 준비한다. 라이브 송출의 경우엔 서버는 미디어 인코더가 필요하고,  인코딩된 미디어를 세그먼트 단위로 잘라 파일로 저장하는 과정이 필요한데, 이 과정은 Apple 혹은 3rd party 에서 만든 media stream segmenter를 사용할 것이다. 



**Distribution Component**

배포 컴포넌트는 미디어와 index 파일을 http로 전송할 웹 서버 혹은 웹 캐싱 시스템을 의미한다. 배포를 위한 서버 모듈은 특별한게 아니고 작은 configuration 만 하면 된다. html 혹은 클라이언트 앱이 receiver로서 역할을 하게 하면 된다. You also need the use of a web server and a way to encode live streams as fragmented MPEG-4 media files containing HEVC or H.264 video, and AAC or AC-3 audio. 



**Client Software**

클라이언트는 적절한 미디어를 요청하고 다운로드하며 reassemble하여 미디어가 연속된 것으로 보이게끔 해야 한다. 클라이언트 소프트웨어는 index 파일을 fetching 하여 스트림을 구별하는 URL을 사용한다. index file은 media file의 위치, description key, alternative stream을 specify 한다. 선택된 스트림에 대해서 클라이언트는 순서대로 미디어 파일을 다운받는다. 적당히 다운 받앗으면 reassemble 하여 사용자에게 보여준다.

클라이언트는 decryption key를 fetch 하여 authentication 혹은 미디어 파일을 decrypt 해야 한다.







#### Reference

https://developer.apple.com/documentation/http_live_streaming