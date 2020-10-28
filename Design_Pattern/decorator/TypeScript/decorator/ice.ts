import Beverage from "../beverage/abstract-class";
import CondimentDecorator from "./decorator";

export default class Ice extends CondimentDecorator {
  public constructor(public readonly beverage: Beverage) {
    super();
    this.beverage = beverage;
  }
  public getDescription() {
    return this.beverage.getDescription() + ` + 얼음`;
  }

  public cost(): number {
    return this.beverage.cost();
  }
}
