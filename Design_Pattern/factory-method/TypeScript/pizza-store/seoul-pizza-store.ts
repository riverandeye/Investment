import PizzaStore from "./abstract";
import Pizza from "../pizza/abstract";
import SeoulChonnomPizza from "../pizza/seoul-chonnom-pizza";

export default class SeoulPizzaStore extends PizzaStore {
  public constructor() {
    super();
  }

  public createPizza(type: string): Pizza {
    switch (type) {
      case "SeoulChonnomPizza":
        return new SeoulChonnomPizza();
    }
  }
}
