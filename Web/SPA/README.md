# Single Page Application



### Single Page Application 이란

- 웹 애플리케이션에 필요한 모든 정적 리소스를 최초에 한번 다운로드한다.
- 새로운 페이지 요청 시, 페이지 갱신에 필요한 데이터만을 전달받아 페이지를 갱신한다.



### Hash 방식을 이용한 구현 예시

- URL : https://riverandeye.github.io/SPA_Hash_demo/

- 해당 코드 : https://github.com/riverandeye/Investment/tree/master/Web/SPA/HashExample



>App.js 



```javascript
window.addEventListener('DOMContentLoaded', router);
window.addEventListener('hashchange', router);
```

핵심은 이 eventListener의 존재이다. 같은 페이지에서 해시값이 변경되면 해당 라우터를 실행시킨다.



```javascript
const getCurrentPath = () => {
    const hashPath = window.location.hash.split("#");
    return hashPath[1] ? hashPath[1] : '/';
}

const getRoute = () => {
    const path = getCurrentPath();
    const route = routes[path];
    return route ? route : routes['/404'];
}

const router = async () => {
    const {
        component,
        title
    } = getRoute();
    document.title = title;

    const page = component;
    const view = page.render();
    const root = document.getElementById('root');
    root.innerHTML = view;

    page.init();
}
```

라우터는 이렇게 작성되었다. getRoute() 함수를 통해 매핑한 routes 객체에서 path 에 해당하는 component과 title을 전달받는다.

전달된 component는 고유의 render 함수를 통해 HTML을 리턴하고, root의 innerHTML로 설정해줌으로써 화면을 렌더링 해주는 것이다.



```javascript
import main from './views/main.js';
import about from './views/about.js';
import contact from './views/contact.js';

const routes = {
    '/': {
        component: main,
        title: 'Homepage'
    },

    'home': {
        component: main,
        title: 'Homepage'
    },
    'about': {
        component: about,
        title: 'About Myself'
    },

    'contact': {
        component: contact,
        title: 'Contact to me!'
    }
}
```

매핑은 명시성을 위해 오브젝트 리터럴 형식으로 구성하였고, view를 import하여 사용한다. view 폴더에 관리되는 최종 view들은 Component들의 조합으로 구성하여 코드의 재사용성을 높인다.

/404에 해당하는 예외처리도 해놓았는데 매핑이 되어있지 않다. 자율적으로 추가해보자.



### Reference

header - https://www.w3schools.com/howto/howto_css_responsive_header.asp

footer - https://codepen.io/slstudios/pen/mJqjeP

SPA - https://poiemaweb.com/js-spa

