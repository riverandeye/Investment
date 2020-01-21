# KUCC

> KUCC를 개발했을 때 시행했던 컨벤션을 다룹니다.



**<커밋 제목>: message**

type

- feat : 새로운 기능을 추가하였을 때
- docs : 문서 작업을 하였을 때 (swagger, requirement.txt 등)
- fix : 오류 혹은 예상되는 오류를 수정하였을 때
- init : 파일을 초기화 (initialize) 한 경우
- style : 코드의 변경은 없으나 indentation, whitespace, semicolon 등의 것들이 변경된 경우
- refactor : 기능상 차이는 없으나 함수명 혹은 변수명 등 코드가 변경된 경우 (말그대로 리팩토링)
- perf : 기능상 차이는 없으나 성능을 개선한 경우
- test : 테스트 코드를 작성한 경우
- build : 빌드하는 과정에 변화를 주는 것들을 수정한 경우 (npm, yarn 등)
- ci : CI configuration 에 변화를 준 경우 (Travis 등)
- chore : 코드 작성 외의 것을 수행하였을 경우
- revert : 이전 커밋을 revert 한 경우

**커밋 메세지**

- 무엇을 어떻게 왜 했는지 작성
- 너무 길게 쓸 필요는 없고, 명확하게 의사를 전달할 수 있는 정도면 됨.

**예시**

- 사용자 정보를 반환하는 api를 추가하였을 때

  - **커밋 제목 :** <feat>: add user api

    **커밋 메세지 :**

    사용자 정보를 반환하는 API를 작성하였습니다.

    GET /users/:id 로 접근할 수 있습니다.