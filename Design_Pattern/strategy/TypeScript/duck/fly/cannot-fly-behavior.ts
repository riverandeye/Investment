import IFlyBehavior from "./interface";

export default class CannotFlyBehavior implements IFlyBehavior {
  public fly() {
    console.log("I can't fly");
  }
}
