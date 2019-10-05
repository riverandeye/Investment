const electron = require('electron');
const url = require('url');
const path = require('path');

const { app, BrowserWindow, Menu, ipcMain } = electron;

// DevTool 제거하기
process.env.NODE_ENV = 'production';

let mainWindow;
let addWindow;

// 앱 준비시킴
app.on('ready', function() {
  // Window를 만든다
  mainWindow = new BrowserWindow({
    // nodejs 문법을 script에서 사용할 수 있게 한다.
    webPreferences: {
      nodeIntegration: true
    }
  });
  // 해당 Window에 Load를 하되, URL 을 입력하여 해당 자원을 load한다.
  mainWindow.loadURL(
    url.format({
      pathname: path.join(__dirname, 'main.html'),
      protocol: 'file',
      slashes: true
    }) // 문서를 불러오는 프로토콜을 설정
  ); //file://pathname 으로 불러오겠따는 뜻임.

  const mainMenu = Menu.buildFromTemplate(mainMenuTemplate);
  Menu.setApplicationMenu(mainMenu);
});

// 새 창을 만들어보자.
function createAddWindow() {
  // Window를 만든다
  addWindow = new BrowserWindow({
    width: 300,
    height: 200,
    title: '대충 새로 추가한다는 제목',
    webPreferences: {
      nodeIntegration: true
    }
  });
  // 해당 Window에 Load를 하되, URL 을 입력하여 해당 자원을 load한다.
  addWindow.loadURL(
    url.format({
      pathname: path.join(__dirname, 'addWindow.html'),
      protocol: 'file',
      slashes: true
    }) // 문서를 불러오는 프로토콜을 설정
  ); //file://pathname 으로 불러오겠따는 뜻임.

  // garbage collection용
  addWindow.on('closed', function() {
    addWindow = null;
  });

  // 메인창이 닫히면 모든 창을 닫게 만들어보자.
  mainWindow.on('closed', function() {
    app.quit();
  });

  //Garbage collection handle
  addWindow.on('close', function() {
    addWindow = null;
  });
}

// ipcRenderer가 emit한 item:add 이벤트를 듣는거임.
ipcMain.on('item:add', function(e, item) {
  mainWindow.webContents.send('item:add', item);
  addWindow.close();
});

// 상단 메뉴 템플릿 만들기
const mainMenuTemplate = [
  {
    label: 'File',
    // submenu는 내부에서 갈라지는 갈래길 같은거임. 바꾸면서 한번 해보시길.
    submenu: [
      {
        label: 'Add Item',
        click() {
          createAddWindow();
        }
      },
      {
        label: 'Clear Items',
        click() {
          mainWindow.webContents.send('item:clear');
        }
      },
      {
        label: 'Quit',
        // accelerator = 단축키
        accelerator: process.platform == 'darwin' ? 'Command+Q' : 'Ctrl+Q',
        click() {
          app.quit();
        }
      }
    ]
  }
];

// 맥 환경이면 메뉴에 empty menu를 추가하자. (electron 이 뜨는거 방지)
(function() {
  if (process.platform == 'darwin') {
    mainMenuTemplate.unshift({});
  }
})();

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
