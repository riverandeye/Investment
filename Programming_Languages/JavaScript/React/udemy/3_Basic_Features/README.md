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

위 두 return 은 같은 결과를 리턴한다. 



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