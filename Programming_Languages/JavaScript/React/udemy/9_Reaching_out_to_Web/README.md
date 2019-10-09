# Reaching out to WEB



- 일반적으로 React Single Page App에선 Render 할 HTML을 받는 것이 아니라 JSON을 통해 소통한다.

* axios를 이용하여 서버와 통신하여 데이터를 교환한다.



### 적절한 HTTP Request 시점

- Component를 Render 하는데 필요한 json data를 받아오는데 적합한 Lifecycle은 **ComponentDidMount**

```javascript
componentDidMount() {
    axios.get('https://jsonplaceholder.typicode.com/posts').then(response => {
        console.log(response);
    });
}
```

위와 같이 **side-effect**를 불러 일으키는 코드를 위 lifecycle에 구현하면 된다.



#### 불러온 데이터 하위 컴포넌트 렌더하기

**State**를 이용하여 Render 할 데이터를 저장하고, render 함수 내에서 해당 state에 담긴 데이터를 이용하여 JSX를 만들어 뿌려주면 된다.

```javascript
state = {
    posts: []
};
```

위와 같이 state를 지정하고

```javascript
componentDidMount() {
    axios.get('https://jsonplaceholder.typicode.com/posts').then(response => {
        this.setState({ posts: response.data });
    });
}
```

ajax 요청 후 setState를 이용하여 데이터를 state에 저장한다.

```javascript
render() {
    const posts = this.state.posts.map(post => {
        return <Post title={post.title} key={post.id} />;
    });
```

그 후 **render 함수 내에서 해당 state를 이용하여 JSX를 만든다**

```javascript
<div>
    <section className="Posts">{posts}</section>
....
```

만든 JSX의 array를 이와 같이 뿌려주면 된다.

데이터에 대한 변경 또한 ComponentDidMount 에서 이루어진다.



#### 컴포넌트 업데이트시 데이터 불러오기

- ComponentDidUpdate에서 데이터를 불러온 후, async한 요청을 보낸 결과를 state에 저장하여 하위 컴포넌트를 다시 렌더링 하는 경우를 생각해보자. 이때 2가지 문제가 발생한다.

  - 요청이 async 하기 때문에 render()시 미리 참조해두었던 **변수가 아직 로드되지 않는 경우** (setState는 요청 이후의 then에 붙어있기 때문에)
    - render 함수에서 해당 변수가 초깃값인지 아닌지 예외처리를 해주어야 한다.

  - setState를 하는 경우 해당 컴포넌트가 Update될 것이고, ComponentDidUpdate가 또 실행될 것이다. 그럼 요청이 무제한으로 계속 요청되게 된다.
    - **현재 요청에 대한 결과와 이전 update된 state와 값이 같은지 아닌지 확인하고, 그때만 state update를 해줘야한다.**



#### 에러 처리

state에 error를 추가하여 try catch 구문으로 에러를 잡아낸 뒤, setState로 error를 update 해준다. 그 후 render 함수 내에서 해당 error를 render 한다.



#### Global 한 에러 처리

프로젝트의 entry point인 index.js에서 axios를 통해 에러를 잡아주자.

```javascript
axios.interceptors.request.use(request=>{
    console.log(request);
    return request;
}, error => {
    console.log(error);
    return Promise.reject(error);
})
```

axios의 interceptors는 request가 보내기지 전에, response를 수용하기 전에 해당 req와 res를 handle해주는 관문처럼 사용할 수 있다.

위의 코드는 request를 날릴때 에러를 handle해주는 것이다. request 시 발생할 error는 주로 internet connectivity 와 관련된 것이고 그러한 에러들이 위 콜백에서 handle 된다.

 

```javascript
axios.interceptors.response.use(response=>{
    console.log(response);
    return response;
}, error=> {
    return Promise.reject(error)
})
```

애는 response에 대한 error handling이다. 해당 코드를 entry point에 추가해주어 **global 하게** 에러 처리 할 수 있다.



#### Axios를 이용한 default setting

**baseUrl**

```javascript
axios.defaults.baseUrl = '~~~~'
```

위와 같이 설정하면, 해당 사이트에 post를 날릴시

```javascript
axios.post('/person/1') 
```

이와 같이 하면 starting url을 변경하지 않아도 된다.

 

**header**

axios.defaults.headers.common['Authorization'] = 'AUTH TOKEN'

axios.defaults.headers.post['Content-type'] = 'application/json'

이런식으로 하면 굳이 매번 헤더를 작성해주지 않아도 되어 매우 편리하다.



#### Axios 객체를 이용하여 독립적으로 사용하기

매번 baseurl을 쓰는게 아니라면 Axios instance를 만들어서 사용하는 것이 편하다.

```javascript
const instance = axios.create({
    baseURL:'~~',
})
```

해당 instance도 default 세팅한 axios에서 create 하면 해당 세팅이 모두 default로 되어있는 상태로 사용할 수 있다.



#### 출처

[axios vs fetch](https://medium.com/@jeffrey.allen.lewis/http-requests-compared-why-axios-is-better-than-node-fetch-more-secure-can-handle-errors-better-39fde869a4a6)