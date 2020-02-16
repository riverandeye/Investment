import ICharacter from "./interface";

export class Phantom implements ICharacter {
  public calculateAttackDamage() {
    return 20;
  }

  public calculateMoveSpeed() {
    return 40;
  }
}
