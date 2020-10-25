import WoodenDuck from "./duck/wooden-duck";
import FlyingDuck from "./duck/flying-duck";
import Chicken from "./duck/chicken";

const main = () => {
  const woodenDuck = new WoodenDuck();
  const flyingDuck = new FlyingDuck();
  const chicken = new Chicken();

  woodenDuck.fly();
  woodenDuck.quack();

  flyingDuck.fly();
  flyingDuck.quack();

  chicken.fly();
  chicken.quack();
};

main();
