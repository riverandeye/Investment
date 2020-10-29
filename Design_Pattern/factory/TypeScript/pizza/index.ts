export enum PizzaType {
  pepperoni,
  potato,
}

export abstract class Pizza {
  public name = "no-name";

  public constructor(name: string) {
    this.name = name;
  }

  public getName() {
    return name;
  }
}
