import ICharacter from "./interface";

export class Aran implements ICharacter {
  public calculateAttackDamage() {
    return 30;
  }

  public calculateMoveSpeed() {
    return 20;
  }
}
