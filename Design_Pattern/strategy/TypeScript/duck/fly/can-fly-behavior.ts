import IFlyBehavior from "./interface";

export default class CanFlyBehavior implements IFlyBehavior {
  public fly() {
    console.log("I can fly");
  }
}
