# MKDocs

> MKDocs 모듈을 이용하여 gh-pages 를 만들고 웹을 띄우는 법

- https://demun.github.io/mkdocs-tuts/guide/publish/ ==> 매우 정리 잘된 사이트



### 설치

```shell
pip3 install mkdocs
```



### 폴더 생성

```shell
mkdocs new projectDescriptionSite
```

- 특정 git repo 안에서 위 코드를 실행시킨다. (문서화하고싶은 repo에!)

- 실행시키면 projectDescriptionSite 폴더가 생성된다.

- 해당 폴더엔 docs 폴더와 mkdocs.yml 파일이 생성된다.

  

### 로컬 서버에 띄우기

```shell
cd projectDescriptionSite
mkdocs serve
```

- 폴더에 들어가서 mkdocs serve를 실행시킨다.
- localhost:8000으로 확인한다.



### 설정 변경하기

mkdocs.yml 파일의 값을 변경한다.

- 사이트 제목 변경하기

  - site_name: <사이트 제목> 으로 변경 => serve 다시 하면 값이 변경되어있음.
  - 기본 테마는 `theme: readthedocs` 로 바꿔주자 (그게 무난함)

- 페이지 추가

  - docs 폴더에 md 파일을 추가한다.

  - mkdocs.yml의 pages : 에 양식에 맞게끔 항목을 추가한다

    양식 : \- <md파일 제목> : <추가할 md파일 이름>



### 빌드하기

```shell
mkdocs build
```

- 생성된 폴더 안에서 실행한다.
- 완료시 site 라는 폴더가 생성된다



### 마크다운에 포함되는 이미지 보관

- docs 폴더에 img 폴더를 생성하여 거기에 보관한다.



### github page로 배포하기

- 우선 빌드한다 - `mkdocs build`
- 그다음 `mkdocs gh-deploy` 를 shell에 작성한다
- git에 모두 추가하고 push 한다.

이때 gh-pages 라는 branch가 생성되고, 배포되는 페이지는 master와 독립적으로 관리된다.



### 작업 플로우

1. docs에 md 파일을 추가한다.
2. docs의 img 폴더에 md 파일에 링크되는 이미지를 추가한다.
3. mkdocs build  한다.
4. mkdocs gh-deploy 한다
5. git add . / git commit -m "mkdocs upload" / git push 
6. https://아이디.github.io/저장소이름 으로 접속하면 페이지를 확인할 수 있다.