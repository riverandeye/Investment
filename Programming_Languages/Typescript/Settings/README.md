# Config

> typscript 학습 및 프로젝트 세팅에 대해서 정리합니다.



#### 자동 저장 및 컴파일 마다 실행시키기 

1. nodemon && ts-node 이용

```shell
npm install -S nodemon ts-node
nodemon --exec ts-node src/app.ts
```

tsconfig 없이도 저장마다 컴파일되고 실행해준다.



2. tsc-watch 이용

```shell
npm install --save typescript tsc-watch // dependency 설치

tsc-watch server.ts --outDir ./dist --onSuccess "node ./dist/server.js" --onFailure "echo Beep! Compilation Failed" --compiler typescript/bin/tsc
```

dist 라는 폴더에 server.ts 를 server.js 로 컴파일하여 저장해준다.
watch 하는 파일은 프로젝트의 진입점이 되는 파일로 세팅한다. import시 자동으로 다른 파일도 js로 컴파일되어 저장된다. 애는 build 파일을 매번 생성해준다.



3. tsconfig.json 을 이용하기

```shell
npm install -S typescript
npx tsc --init
```

init 시 장문의 tsconfig.json 이 생성된다. 해당 config 파일엔 설정 가능한 키들이 모두 작성되어있다. 밑의 설정을 추가해주자.

```json
{
  "compileOnSave": true,
  "compilerOptions": {
    "target": "es2018",
    "outDir": "./dist",
    "rootDir": "./src",
    "module": "commonjs"
  }
}
```



