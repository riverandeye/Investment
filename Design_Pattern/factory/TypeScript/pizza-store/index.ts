import { PizzaType } from "../pizza";
import PizzaFactory from "../pizza/factory";

export default class PizzaStore {
  public pizzaFactory: PizzaFactory;

  public orderPizza(pizzaType: PizzaType) {
    return this.pizzaFactory.createPizza(pizzaType);
  }
}
