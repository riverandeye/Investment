# Base Features & Syntax



### react-app 폴더 분석

- public
  - favicon.ico - 그냥 [favicon](https://blogoon.tistory.com/69) 이다 
  - index.html - default로 Template이 되는 파일 (manifest.json 으로 해당 여부는 지정할 수 있음)
    - meta 혹은 script는 여기 추가해야 한다.
  - manifest.json  - 구성하려는 페이지의 metadata
  - src - 실제 React Application 을 담는 파일
    - index.js : index.html의 dom 객체에 ReactDom을 render 하는 역할을 한다.
    - App.js : 그냥 처음 구현되어있는 App임. index.js에 수렴시켜 merge 하면 됨.
    - App.css : 그냥 처음 구현되어있는 App의 css
    - App.tets.js : Jasmine 으로 작성된 test code



### React Component

- UI의 각 부분을 재사용하기 쉽게 조각해놓은 것이다. 

```javascript
import React, {Component} from 'react';
import './App.css';

class App extends Component {
  render(){
      return (
      <div className="App">
        <h1>Hi, I'm a React App</h1>
      </div>
    );
  }
}

export default App;
```

- 'react' 에서 Component를 가져온 후, App을 상속시켜 render() 라는 메소드를 정의한다. App을 render할 때 해당 메소드가 작동한다.
- 중간에 return 후 plain HTML이 quotation mark 없이 등장하는데, 이는 React여서 가능한 것이다.

```javascript
return (
      <div className="App">
        <h1>Hi, I'm a React App</h1>
      </div>
);

return React.createElement('div', {className:"App"}, React.createElement('h1', null, "Hi! I'm a React App"));
```

위 두 return 은 같은 결과를 리턴한다. 밑의 방식보단 위의 방식이 훨씬 편해 보인다. HTML 값을 전달하는 것 처럼 보이지만, 실제로는 자바스크립트에서 동작하는 것으로 이를 JSX 라고 부른다.



## JSX

- React element 를 생성하는 코드
- Real HTML Tag를 쓰는 것이 아니라, JSX가 지원하는 태그를 사용해야 한다.
  - className : css class 를 지정해줌
- 사용시 주의할 점
  - 사용하는 스크립트 상단에 React 라이브러리를 꼭 불러와야 사용할 수 있음.
  - 최상위 태그는 1개여야 함.
  - 태그안에 들어가지 않는 경우만 태그를 바로 닫을 수 있음.
- Fragment 태그 : 최상위 태그가 1개여야 한다는 조건에 의해 감싸주는 역할을 하는 태그



### Functional Component

그냥 함수형으로 JSX를 리턴하는 함수를 의미한다.

```javascript
import React from 'react';

const person = ()=>{
    return <p>I'm a Person!</p>
} // for this binding

export default person;
```

이를 index.js에 import 하여 그대로 붙였더니 화면에 렌더링이 된다.

```javascript
function tick() {
    const element = (
    <div>
      <h3>현재 시각은 [{new Date().toLocaleTimeString()}] 입니다.</h3>
      <Person/>
    </div>
    );
    ReactDOM.render(element, document.getElementById('root'));
  }
  setInterval(tick, 1000);
```

이와 같이, 컴포넌트들은 쉽게 중복하여 사용될 수 있어 매우 편하다.



### Dynamic Components

같은 Component 라도 Dynamic 하게끔 변경하고 싶다면, JSX 내에 JS 함수를 사용하면 된다.

```javascript
import React from 'react';

const person = ()=>{
    return <p>I am a Person. I am {Math.floor(Math.random() * 30)} years old!</p>
} // for this binding

export default person;
```



### Using props

함수형 컴포넌트의 인자를 넣을 수 있는데 , 하나의 Object가 입력되고, 해당 Object의 attribute를 사용하는 식으로 인자를 사용하게 된다.

```javascript
import React from 'react';

const person = (props)=>{
    return <p>I'm {props.name}. I'm {props.age} years old!</p>
} // for this binding

export default person;
```

이와 같이 정의된 함수를 jsx에서 사용하는 방식은 이러하다

```javascript
<Person name="KKH" age="3"/>
```

tag 안에 attribute를 정해서 입력해주면 된다.



### Childern Property

Component의 angle bracket 안의 대상들은, 해당 함수의 children property 로 입력된다.

```javascript
const person = (props)=>{
    return (
    <div>
        <p>I'm {props.name}. I'm {props.age} years old!</p>
        <p>{props.children}</p>
    </div>
    )
}
```

위에서 Component의 props.children property를 p tag로 감싸었다.

```javascript
<Person name="KKH" age="3">My Hobbies : Racing</Person>
```

해당 jsx에 대하여 props.children 은 My Hobbies : Racing로 대체된다. 꼭 text가 아니라 함수 혹은 react Component 등으로 대체될 수 있다.



### State property

rendering 되는 값을 하드코딩하지 않고, State property 를 이용하여 Object의 값으로 변경하여 접근할 수 있다.

```javascript
class App extends Component {
  state = {
    persons : [
      { name : "Max", age : 28},
    ]
  }
  render(){
      return (
      <div className="App">
        <h1>Hi, I'm a React App</h1>
        <Person name={this.state.persons[0].name} age={this.state.persons[0].age}/>
      </div>
    );
  }
}
```

State property 는 Component class를 상속한 class에서 사용할 수 있다.



### State and Props







### 궁금한 점 && 더 알고싶은 점

```css
@keyframes App-logo-spin {
  from {
    transform: rotate(0deg);
  }
  to {
    transform: rotate(360deg);
  }
}
```

처음 시작할 때 화면에 React svg logo가 어떻게 돌아가는지 봤는데 CSS로 돌리는것 같다. 

```css
.App-logo {
  animation: App-logo-spin infinite 20s linear;
  height: 40vmin;
  pointer-events: none;
}
```

.App-logo 라는 className="App-logo" 인 객체 이미지에 이러한 animation을 두는것 같다. 구체적으로 어떻게 사용하는지 알아야겠다. 이걸 알면 뭔가를 짜는게 더 수월해질듯.



SVG 이미지를 어떻게 만드는지 알고싶다.