import Duck from ".";

import CanFlyBehavior from "./fly/can-fly-behavior";
import CanQuackBehavior from "./quack/can-quack-behavior";

export default class FlyingDuck extends Duck {
  constructor() {
    super(new CanFlyBehavior(), new CanQuackBehavior());
  }
}
