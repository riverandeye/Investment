# Tutorial



가장 먼저 시작하게 되면 [이 문서](https://facebook.github.io/react-native/docs/getting-started)를 만나게 됩니다. 설치 잘 되고 실행 잘 되지만, 막히는 부분이 있다면 초기화된 코드가 돌아갈 머신이 없다는 점인데요. expo에 실행시키는 [튜토리얼](https://docs.expo.io/versions/v33.0.0/workflow/up-and-running/)이 있어서 한번 따라가 봅시다.



### 설치하기



설치에 관한 내용은 [여기](https://facebook.github.io/react-native/docs/getting-started)에 너무 잘 나와있다. 꼭 참고하자.



### 실행하기



- 시뮬레이터에서 실행하기 ([Android](https://docs.expo.io/versions/v33.0.0/workflow/android-studio-emulator/))

- 직접 핸드폰에서 시뮬레이션 해보는 것도 괜찮지만, 우선 로컬 머신에서 먼저 시뮬레이터를 돌려보자.

  - 안드로이드 스튜디오를 설치한 후, Settings에서 Android VDM 을 선택하여 시뮬레이터를 임의로 만들어보자. (본인이 테스트하려는 디바이스와 맞게끔 구성) 

  ![image-20200118035621212](C:\Users\tony0\Desktop\github\Investment\Programming_Languages\JavaScript\React-Native\tutorial\images\image-20200118035621212.png)

  

  가상 디바이스를 만든 후 더블클릭하면 Launch 된다. (우측 화살표를 눌러도 됨)

  

  ![image-20200118035722736](C:\Users\tony0\Desktop\github\Investment\Programming_Languages\JavaScript\React-Native\tutorial\images\image-20200118035722736.png)



​		이런 식으로! 매우 간편하다. 이렇게 안드로이드 앱을 하나 띄운 상태에서, npm run start로 앱을 실행시킨 후, 		a를 누르면 실행한 Android Emulator 에 앱이 연결이 된다.



![image-20200118040219484](C:\Users\tony0\Desktop\github\Investment\Programming_Languages\JavaScript\React-Native\tutorial\images\image-20200118040219484.png)



​		자바스크립트 번들링이 완료되면 제대로 화면에 등장 할 것이다. 



![image-20200118040259007](C:\Users\tony0\Desktop\github\Investment\Programming_Languages\JavaScript\React-Native\tutorial\images\image-20200118040259007.png)



​		이렇게 이쁘고 깔끔하게 나온다. 그럼 저장할때마다 업데이트되는지 확인해보자.



![image-20200118040344607](C:\Users\tony0\Desktop\github\Investment\Programming_Languages\JavaScript\React-Native\tutorial\images\image-20200118040344607.png)



​		어우 잘된다. 이제 개발을 하면 되겠다!



- 핸드폰에서 실행시키기
  - 갖고 있는 휴대폰에서 실행시키기 위해선 Expo 라는 앱을 설치해야 하는데, 이건 나중에 작성해야겠다.



### 기본이 되는 내용들

- 