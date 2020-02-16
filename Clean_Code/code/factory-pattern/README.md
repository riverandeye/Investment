# Factory Pattern

> switch statement를 한번만 사용하게 해주는 Factory Pattern!



Factory Pattern을 이용하여 하나의 메소드가 여러 타입에 대해서 서로 다른 결과를 내는 것이 아니라, 타입을 입력하면 각 타입에 해당하는 객체를 반환하는 식으로 구성합니다.



### 문제 상황

```typescript
function calculateAttackDamage(character) {
  switch (character) {
    case "PHANTOM":
      return 20;
    case "ARAN":
      return 30;
  }
  return 0;
}

function calculateMoveSpeed(character) {
  switch (character) {
    case "PHANTOM":
      return 40;
    case "ARAN":
      return 20;
  }
  return 0;
}

function runGame() {
  console.log("팬텀 평타 " + calculateAttackDamage("PHANTOM"));
  console.log("아란 평타 " + calculateAttackDamage("ARAN"));
  console.log("팬텀 이동속도 " + calculateMoveSpeed("PHANTOM"));
  console.log("아란 이동속도 " + calculateMoveSpeed("ARAN"));
}

runGame();
```

문제상황은 다음과 같습니다. 서로 다른 유형의 캐릭터들에 대해서 Speed와 Damage를 계산합니다.

현재 주어진 상황에선 캐릭터를 함수에 입력하면, 그 캐릭터의 유형에 따라 함수가 다른 결과를 보이게 됩니다. 위 기능은 캐릭터의 종류가 많아지면 해당 함수를 고쳐야 하며, 하나의 함수가 여러개의 타입에 대해 동작하게 되어 재사용성이 떨어집니다.



각 type 별로, 각 타입에 해당하는 메소드가 정의되어 있는 객체를 반환하여 문제를 해결해 봅시다.



#### 1. 인터페이스 및 객체 정의

- 모든 타입이 Speed와 AttackDamage 를 계산하지만, 계산 방식이 다르므로 Interface를 통해 메소드를 명시해주고 이를 서로 다른 Class를 통해 Implement 해줍니다.

  - ICharacter.ts (Interface)

  ```typescript
  export default interface Icharacter {
    calculateAttackDamage(): number;
    calculateMoveSpeed(): number;
  }
  ```

  - Aran.ts

  ```typescript
  import ICharacter from "./interface";
  
  export class Aran implements ICharacter {
    public calculateAttackDamage() {
      return 30;
    }
  
    public calculateMoveSpeed() {
      return 20;
    }
  }
  ```

  - Phantom.ts

  ```typescript
  import ICharacter from "./interface";
  
  export class Phantom implements ICharacter {
    public calculateAttackDamage() {
      return 20;
    }
  
    public calculateMoveSpeed() {
      return 40;
    }
  }
  ```

  

- 그 후, 입력 받은 타입에 따라 그에 해당하는 객체를 생성해줍니다.

  ```typescript
  import Icharacter from "../interface";
  import { Phantom } from "../Phantom";
  import { Aran } from "../Aram";
  
  export class CharacterFactory {
    public static createCharactor(type: string): Icharacter {
      switch (type) {
        case "PHANTOM":
          return new Phantom();
        case "ARAN":
          return new Aran();
      }
    }
  }
  ```

  

- 해당 static method를 이용하여 캐릭터 인스턴스를 생성하여, 각각의 메소드를 호출해 줍니다.

  ```typescript
  const aran = CharacterFactory.createCharactor("ARAN");
  const phantom = CharacterFactory.createCharactor("PHANTOM");
  
  console.log(aran.calculateAttackDamage());
  console.log(phantom.calculateAttackDamage());
  ```

  

이렇게 하면 서로 다른 메서드는 각각의 객체에 종속되고, 각 메서드를 매우 작은 단위로 쪼갤 수 있습니다. Switch 문은 팩토리의 메서드에만 한번 만들어주면, 각 case에 따라 서로 다른 객체를 반환받고, 각 객체는 서로 다른 기능을 하게 되어 매우 이상적입니다. Factory 메소드 외 모든 함수는 다른 대상들의 존재에 구애받지 않으며, 테스트 할 수 있게끔 작게 구성되어 바람직합니다.