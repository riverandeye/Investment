import { Pizza, PizzaType } from ".";

import PepperoniPizza from "./pepperoni";
import PotatoPizza from "./potato";

export default class PizzaFactory {
  public createPizza(type: PizzaType): Pizza {
    switch (type) {
      case PizzaType.pepperoni:
        return new PepperoniPizza();

      case PizzaType.potato:
        return new PotatoPizza();
    }
  }
}
