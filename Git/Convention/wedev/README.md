# Wedev

> Wedev를 개발했을 때 시행했던 컨벤션을 다룹니다.



### Commit Convention

```
[server ? client] | <type>(<scope>): <subject>
    <BLANK LINE>
    <body>
    <BLANK LINE>
    <issue>(optional)

```

    ex)
    backend | feat(auth): Table Manager 구현
    
    express-session을 이용하여 세션테이블 매니저를 구현했습니다.
    
    (옵션)Fixes https://github.com/plone/PACKAGE/issue/42


- **subject**와 **body**를 한글로 작성하고, 그 외엔 영어로 작성합니다.
- **type** : 어떤 의도로 커밋했는지를 type에 명시합니다. 자세한 사항은 아래서 설명하겠습니다.
- **scope** :  커밋의 대상이 되는 것을 명시합니다.
- **subject** : 최대 50글자가 넘지 않도록 하고 마침표는 찍지 않습니다.
- **body** : 최대한 작성합니다. **HOW**와 **WHY** 위주로 작성합니다. ~합니다 라는 문체로 작성합니다.최대한 간결하게 씁니다.
- **issue**: 이슈에 대한 상세한 설명이 필요한 경우 해당 이슈의 링크를 첨부한다.



#### type

- **feat** : 새로운 기능 추가
- **fix** : 버그 수정
- **docs** : 문서의 수정
- **style** : (코드의 수정 없이) 스타일(style)만 변경(들여쓰기 같은 포맷이나 세미콜론을 빼먹은 경우)
- **refactor** : 코드를 리펙토링
- **test** : Test 관련한 코드의 추가, 수정
- **chore** : (코드의 수정 없이) 설정을 변경



#### 참조

[RFC: Git Commit Message Guidelines](https://gist.github.com/abravalheri/34aeb7b18d61392251a2)



