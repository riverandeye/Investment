export default class Monster {
  public constructor(
    public readonly name: string,
    public readonly HP: number,
    public readonly MP: number,
    public readonly level: number
  ) {}

  public static newOrangeMushroom() {
    return new Monster("OrangeMushroom", 150, 30, 10);
  }

  public static newRibbonPig() {
    return new Monster("RibbonPig", 200, 50, 12);
  }

  public sayHello() {
    console.log(`Hello! I am ${this.name}!`);
  }
}

const orangeMushroom = Monster.newOrangeMushroom();
orangeMushroom.sayHello();
