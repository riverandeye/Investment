# Optimization



#### 해당 컴포넌트의 변경이 없는 경우 최적화

```javascript
shouldComponentUpdate(nextProps, nextState){
    console.log("[Persons.js] shouldComponentUpdate");
    if(nextProps.persons !== this.props.persons){
        return true;
    }
    else{
        return false;
    }
}
```

현재 props와 이전 props를 비교하여 동일하면 true, 다르면 false를 리턴한다. 

단순히 pointer를 비교하는 shallow comparison 인것 같은데 왜 작동하냐? 

```javascript
const persons = [...this.state.persons];
persons[personIdx] = person;
this.setState(
    {persons : persons});
}
```

이와 같이 새로운 persons를 아예 정의하여 사용하였기 때문이다.

그냥 persons를 modify하는 식으로 하였으면 비교가 안되었을 것이다.



![](Images/1.gif)

- Toggle 후 cockpit을 제거할 시, 실제로 Persons는 변경되지 않는다.
- App.js의 this.state.Persons가 Persons의 props.persons로 들어오는 상황이므로, nextProps.persons와 this.props.persons를 비교해준다.
- 같을 경우 false를 리턴하므로, Persons를 Update하지 않는다.
- 고로 자연스럽게 하위 컴포넌트들에 대해서도 Update되지 않는다.
- 이를 이용하여 불필요한 렌더링을 최소화하여 최적화한다.



#### Functional Components 에서의 Optimization

```javascript
export default React.memo(Cockpit);
```

React.memo 메소드는 입력 컴포넌트의 변경이 없을 시 해당 컴포넌트를 다시 렌더링하지 않게 만드는 역할을 한다.

그래서 export 하는 functional Component를 React.memo 함수로 감싸주면, Component가 update 되었는지 아닌지를 판단해준다.



### When To Optimize?

모든 component들을 extra check 하게 되면 그것 또한 낭비다. 가령 대부분 상위 컴포넌트의 변경이 하위 컴포넌트의 변경을 야기하게 된다면, 굳이 체크할 이유가없다.



### PureComponent

PureComponent는 모든 입력되는 props들에 대한 shouldComponentUpdate 함수가 이미 구현되어 있는 컴포넌트이다. 

```javascript
shouldComponentUpdate(nextProps, nextState){
    console.log("[Persons.js] shouldComponentUpdate");
    if(nextProps.persons !== this.props.persons ||
       nextProps.changed !== this.props.changed ||
       nextProps.clicked !== this.props.clicked){
        return true;
    }
    else{
        return false;
    }
}
```

이런식으로 존재하는 모든 props에 대한 변화를 체크하고 싶으면 차라리

```javascript
class Persons extends PureComponent{
```

이렇게 Person을 정의하자. 이미 다 구현되어 있어서 코드를 복잡하게 할 필요가 없다.



### How React Updates the DOM



![1567921189261](Images/2.png)

- shouldComponentUpdate 를 통과한 Component는 render 함수를 수행한다.
- 이전 Virtual DOM과 새롭게 렌더링되는 Virtual DOM을 비교한다.
- Virtual DOM은 JSX로 작성되어있으며 REAL DOM 보다 빠르다.
- Virtual DOM 간 차이가 있으면, 해당 차이가 있는 부분의 real DOM 을 업데이트한다.



### Rendering Adjacent JSX Element



불필요하게 <div>로 감싸지는 것을 방지하기 위해 사용하는 방법이다.

```javascript
const aux = props => props.children;

export default aux;
```

aux 라는 HOC를 이용하여 

```javascript
return (
    <Aux>
        <p onClick={this.props.click}>I'm {this.props.name}. I'm {this.props.age} years old!</p>
        <p>{this.props.children}</p>
        <input type='text' onChange={this.props.changed} value={this.props.name}></input>
    </Aux>
```

감싸주면 된다. 그러면 <div> 한 단계가 사라진다.



### React.Fragment

그냥 aux 저렇게 구현할 필요 없고, Fragment import 해서 갖다 쓰면 된다.

```javascript
<Fragment>
    <list of jsx>
</Fragment>
```