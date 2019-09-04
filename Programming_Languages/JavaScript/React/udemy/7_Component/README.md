# Components (Detail)

> 컴포넌트와 React Internals에 대해서 자세히 알아봅시다.



### Better Project Structure

- 이전 과제에서, state에서 List로 구성된 여러 Person을 render 해주기 위해 map 함수를 이용하였는데, 이를 App.js 에서 작동시켰다.

- 그러나 App.js 컴포넌트는 안에서 로직이 작동하는 것 보단 독립된 구성품들을 하나로 묶은 결과가 직관적으로 보이게 구성해야 한다.
- 그러므로 Persons라는 객체를 설정하여, Person이 모여 Persons가 구성되게끔 하는 것이 바람직하다.
- 또, Persons와 동등한 지위를 갖는 객체들이 모여있는 공간을 Components로 이름짓는 것이 적절하다.



![](http://jamesknelson.com/wp-content/uploads/2018/08/react-cruv.png)

위 사진은 프로젝트의 예시이다.

사실 리액트 프로젝트의 구조 제안은 매우 다양하지만, 이 강의에서 제시하는건 다음과 같다.

- assets -> 이미지, 공통으로 사용되는 알고리즘 등 구현체
- components -> container를 구성할 때 중복하여 사용되는 컴포넌트의 모임
- containers -> index.js에서 route 단위로 바인딩되는 대상들의 모임



#### Person을 묶어 Persons로 변경하기

- 개념은 매우 단순하다. 기존에 app.js에서 했던걸 그냥 Persons가 해주면 된다. Persons라는 wrapper를 만들어 Person을 묶어서 넘겨준다고 봐도 무방하다. (물론 functional component를 사용하여 구성해도 된다.)

```javascript
const Persons = (props)=>
    props.persons.map(
        (person, idx)=>{
            return <Person
            key={person.id}
            click={()=>props.clicked(idx)}
        	name={person.name} 
            age={person.age}
            changed={(event)=>props.changed(event, person.id)}/>}	)
```

- 말 그대로, props에서 person을 App.js의 this.states.persons 로 넘겨받아 각 객체를 map해서 만들어준 것이다. 함수도 props를 통해 전달받은걸 넘겨준 것 뿐이다.



#### 버튼이 있는 영역을 Cockpit으로 묶어주기

- button의 CSS가 바뀌는 부분도 Cockpit 함수로 빼줘야 한다.



```javascript
const Cockpit = (props) => {
    // logic
   return (
       <div className={classes.Cockpit}>
        <h1>Hi, I'm a React App</h1>
          <p className={assignedClasses.join(' ')}>This is really Working!</p>
          <button style={{btnClass}} onClick={props.clicked}>Toggle</button>
       </div>
   );
};
```

**이렇게 컴포넌트화 하는 것들의 핵심은, State는 가장 위의 컴포넌트인 App이 갖고 있고, 해당 state를 아래로 뻗어주자는 것이다.**

-> 데이터의 흐름이 항상 위에서 아래라는 점이다.

#### App.js에서 드러나는 컴포넌트화의 장점

```javascript
return (
      <div className="App">
          <Cockpit
            showPersons = {this.state.showPersons}
            persons = {this.state.persons}
            clicked = {this.togglePersonsHandler}
          />
          {persons}
      </div>
    );
```

App.js 가 무엇을 리턴하는지 딱 보면 `아 이페이지가 어떤 형태를 띄겠구나` 를 캐치할 수 있다. 매우 간결하고 직관적이고 재사용성이 높아진다.



#### Stateless Component

- 프로젝트가 커질수록 Stateful Component는 최소화하는 것이 바람직하다. 이는 구성의 직관성을 높이기 위함이다.





### 의문

- 왜 CSS가 안먹힐까..