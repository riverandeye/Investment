# Electron Tutorial

> 아주 단순하게 목록 저장하는 페이지를 만들어 봅시다.



[이 강좌](https://www.youtube.com/watch?v=kN1Czs0m1SU) 를 천천히 보시는게 이해가 더 잘 될 수도 있습니다.



### 0. 패키지 설치 및 세팅

```shell
// 
npm init
npm install --save electron
touch main.js
```

- package.json을 초기화하고 Dependency를 설치한다. 

 ```json
// package.json
"main": "main.js",
"scripts": {
    "start": "electron .",
    ...
 ```

- package.json의 entry point를 main.js로 설정한다.

- script에 start 스크립트를 추가한다 (npm start로 프로젝트를 실행)



### 1. 기본 페이지 띄워보기

```javascript
//main.js
const electron = require('electron');
const { app, BrowserWindow, Menu, ipcMain } = electron;


let mainWindow;
app.on('ready', function() {
  // Window를 만든다
  mainWindow = new BrowserWindow();
})
```

npm start를 하면 데스크탑 앱 형태에 빈 창이 만들어진다.



### 2. 기본 페이지에 원하는 HTML을 입히기

우선, main.html을 같은 폴더에 만들고, 현재 github에 업로드 된 것을 복사해주자. 

```javascript
const url = require('url');
app.on('ready', function() { 
    ...
    mainWindow.loadURL(
        url.format({
            pathname: path.join(__dirname, 'main.html'),
            protocol: 'file',
            slashes: true
        }) // 문서를 불러오는 프로토콜을 설정
    ); //file://pathname 으로 불러오겠따는 뜻임.
```

app.on('ready') 내의 콜백함수 안에 선언된 mainWindow의 loadURL 메소드를 통해 URL값을 이용하여 HTML을 불러온다. url을 임포트하여 굳이 format으로 url을 만들어주었지만, 그냥 string으로 넣어도 된다.



### 3. 상단 메뉴바 설정

```javascript
const mainMenuTemplate = [
    {
        label:'File',
        submenu:[
            {
                label ...
            }
        ]
    }
]
const mainMenu = Menu.buildFromTemplate(mainMenuTemplate);
Menu.setApplicationMenu(mainMenu);
```

Object의 array로 정의된 mainMenuTemplate를 Menu의 buildFromTemplate 메소드에 입력해주고, 어플리케이션의 메뉴로 지정해주면 된다. 메뉴바 템플릿 지정시 자주 사용되는 property는 다음과 같다.

**submenu** : 해당 메뉴의 갈래 목록

**label** : 해당 메뉴의 이름

**click(item, focusedWindow)** : 클릭되었을 시 수행되는 함수

**accelerator** : 단축키

이 부분은 백문이 불여일견이라 직접 작성하고 값을 바꾸다 보면 어떤 구조인지 쉽게 알 수 있다.



### Developer Tool 추가하기

```javascript
// developer tool 추가하기 (production mode 아닐때)
(function() {
  if (process.env.NODE_ENV !== 'production') {
    mainMenuTemplate.push({
      label: 'Developer Tools',
      submenu: [
        {
          label: 'Toggle DevTools',
          accelerator:
            process.platform == 'darwin' ? 'Command+I' : 'Ctrl+Shift+J',
          click(item, focusedWindow) {
            focusedWindow.toggleDevTools();
          }
        },
        {
          role: 'reload'
        }
      ]
    });
  }
})();

```

단순히 [IIFE](https://github.com/riverandeye/Investment/tree/master/Programming_Languages/JavaScript/Fundamentals/Terminology) 패턴으로 감쌌는데, 내부 로직을 보면, production 모드가 아닐 때 메뉴 템플릿에 developer tool 을 추가하는 것이다.

단축키 설정은 OS마다 다르게 했고, click때는 devtool을 Toggle하는 메서드를 이용한다. 해당 Object를 mainMenuTemplate에 push 하면 적용된다. (물론 setApplicationMenu 보다 더 일찍 실행되어야 한다.)



### HTML 내 Script에서 nodejs 사용하기

```javascript
addWindow = new BrowserWindow({
    ...
    webPreferences: {
        nodeIntegration: true
    }
});
```

webPreferences 의 nodeIntegration 을 true로 두면 nodejs 지원 문법들을 사용할 수 있다.



### Reference

[유투브 강좌](https://www.youtube.com/watch?v=kN1Czs0m1SU)

