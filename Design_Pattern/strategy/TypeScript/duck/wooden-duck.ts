import Duck from "./index";

import CannotFlyBehavior from "./fly/cannot-fly-behavior";
import MuteQuackBehavior from "./quack/mute-quack-behavior";

export default class WoodenDuck extends Duck {
  public constructor() {
    super(new CannotFlyBehavior(), new MuteQuackBehavior());
  }
}
