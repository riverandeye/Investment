import Duck from ".";
import CannotFlyBehavior from "./fly/cannot-fly-behavior";
import CanQuackBehavior from "./quack/can-quack-behavior";

export default class Chicken extends Duck {
  constructor() {
    super(new CannotFlyBehavior(), new CanQuackBehavior());
  }
}
