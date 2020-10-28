import Beverage from "./abstract-class";

export default class ColdBrew extends Beverage {
  public constructor() {
    super();
    this.description = "Cold Brew";
  }

  public cost(): number {
    return 3000;
  }
}
