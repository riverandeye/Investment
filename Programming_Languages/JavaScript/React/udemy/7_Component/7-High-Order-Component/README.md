

# High Order Component



리액트 컴포넌트는 하나로 감싸진 jsx만을 리턴해야 하는데, 이를 위해 React.Fragment를 사용했다. 이 또한 컴포넌트를 입력받아 새로운 컴포넌트를 입력받는 **HOC** 라고 할 수 있다. div 같은걸 사용하지 않고, 독립적으로 HOC를 구성하여 CSS를 적용시키는 방법에 대해 알아보자.



**1. JSX를 리턴하는 방식**

```javascript
import React from 'react';

const WithClass = props => {
    console.log(props.className);
    return (<div className={props.className}>
        {props.children}
    </div>
)}

export default WithClass;
```



이 함수는 특정 컴포넌트에 클래스를 제공하기 위해 만들어 준 HOC로, withClass라는 컴포넌트로 감싸면, 해당 클래스를 가지는 div로 감싼 jsx를 리턴한다.

애는 리턴하려는 컴포넌트 무리들을 위 컴포넌트로 감싸주면 된다.



**2. 컴포넌트를 리턴하는 방식** 

```javascript
const WithClass = (WrappedComponents, className) => {
    return props => (
        <div className={className}>
            <WrappedComponents />
        </div>
    );
}
```



이렇게 아예 함수를 리턴하는 경우엔 

```javascript
export default WithClass(App, Classes.App);
```

이런식으로 export할 때 감싸서 리턴해주어야 한다.



그럼 Wrap된 하위 컴포넌트들에게 Props를 어떻게 전달해줘야 할까?

```javascript
import React from 'react';

const WithClass = (WrappedComponents, className) => {
    return props => (
        <div className={className}>
            <WrappedComponents {...props}/>
        </div>
    );
}

export default WithClass;
```

위 HOC는 단순히 컴포넌트를 입력받아 거치게 하는 도구이므로, 실제로 JSX로 표현될 때는 해당 컴포넌트가 입력된다. JSX만 놓고 보면 HOC를 거치는지 알 수 없고, Props는 WrappedComponents에 들어가야 하기 때문에 위와 같이 spread 연산자를 통해 전달해준다.

