import Espresso from "./beverage/espresso";
import Milk from "./decorator/milk";
import Mocha from "./decorator/mocha";
import Ice from "./decorator/ice";

const main = () => {
  const espresso = new Espresso();
  const espressoWithShot = new Mocha(espresso);
  const espressoWithShotAndMilk = new Milk(espressoWithShot);
  const espressoWithShotAndMilkAndIce = new Ice(espressoWithShotAndMilk);

  console.log(espresso.getDescription(), espresso.cost());
  console.log(espressoWithShot.getDescription(), espressoWithShot.cost());
  console.log(espressoWithShotAndMilk.getDescription(), espressoWithShotAndMilk.cost());
  console.log(espressoWithShotAndMilkAndIce.getDescription(), espressoWithShotAndMilkAndIce.cost());
};

main();
