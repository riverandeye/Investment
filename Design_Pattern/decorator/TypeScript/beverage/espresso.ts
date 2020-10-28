import Beverage from "./abstract-class";

export default class Espresso extends Beverage {
  public constructor() {
    super();
    this.description = "Espresso";
  }

  public cost(): number {
    return 2500;
  }
}
