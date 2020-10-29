import Pizza from "./abstract";

export default class BusanGukbobPizza extends Pizza {
  public constructor() {
    super();

    this.name = "BusanGukbobPizza";
    this.dough = "Thin Crust";
    this.sauce = "새우젓";

    this.toppings.push("파", "돼지고기");
  }
}
