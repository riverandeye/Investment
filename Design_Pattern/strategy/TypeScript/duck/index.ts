import IFlyBehavior from "./fly/interface";
import IQuackBehavior from "./quack/interface";

export default class Duck {
  public constructor(
    private readonly flyBehavior: IFlyBehavior,
    private readonly quackBehavior: IQuackBehavior,
  ) {}

  public fly() {
    this.flyBehavior.fly();
  }

  public quack() {
    this.quackBehavior.quack();
  }
}
