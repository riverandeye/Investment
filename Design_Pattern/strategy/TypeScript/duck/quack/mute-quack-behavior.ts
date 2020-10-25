import IQuackBehavior from "./interface";

export default class MuteQuackBehavior implements IQuackBehavior {
  public quack() {
    console.log("...");
  }
}
