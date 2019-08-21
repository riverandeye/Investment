# 1_Introduction

> React는 UI 제작을 위한 Js 라이브러리 입니다.



### Components

- 리액트는 웹을 구성요소(Component) 단위로 쪼개어 구성합니다.
- 독립되게 구성하여 코드 중복을 방지합니다.

- Header, Sidebar, Headline, Article Contents 등

![1566407568365](./Images/Component.png)

- Custom HTML Elements 라고 생각하고 이용하면 되서 매우 편리하다.



### Setting

- npm install 을 이용하여 라이브러리 설치

  ```shell
  npm install -g create-react-app
  create-react-app my-app
  
  cd my-app
  npm start
  ```

  create-react-app my-app 명령어는 npm 폴더를 Root에 설정해야 사용 가능하다. 

  package-json 에서 npm을 이용한 프로젝트 명령어를 확인할 수 있다.



### Example Code

```javascript
import React from 'react'
import ReactDOM from 'react-dom'
import './index.css'

function Person(props){ // props param has all element
    return (
        <div class="person">
            <h1>{props.name}</h1>
            <p>Your age : {props.age}</p>
        </div>
    );
}

ReactDOM.render(<Person name ="Kwan" age = "28"/>, document.getElementById('root'))
```

npm start를 동작시키면 localhost:3000으로 접속하여 렌더링 된 페이지를 확인할 수 있다.



### Single Page application vs Multi Page application

- Single Page Application
  - 서버에 요청시 Single HTML page를 리턴
  - 서버에 page를 reload하게 요청하지 않아도 됨.
  - 서버에 요청할 때도, reactive web app 을 띄워 쾌적한 환경을 조성
  - 모든 Component가 react component이다
- 

https://medium.com/@NeotericEU/single-page-application-vs-multiple-page-application-2591588efe58

이 글 정리해서 Pro Con 업데이트