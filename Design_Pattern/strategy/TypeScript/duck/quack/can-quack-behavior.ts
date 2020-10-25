import IQuackBehavior from "./interface";

export default class CanQuackBehavior implements IQuackBehavior {
  public quack() {
    console.log("Quack Quack!");
  }
}
