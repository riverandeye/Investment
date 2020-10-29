export default abstract class Pizza {
  protected name: string;
  protected dough: string;
  protected sauce: string;
  protected toppings: string[];

  public prepare() {
    console.log("Preparing " + name);
    console.log(`Tossing ${this.dough}...`);
    console.log(`adding ${this.sauce}..`);
    console.log("adding toppings : ");

    this.toppings.forEach((topping) => {
      console.log(` ${topping}`);
    });
  }

  public bake() {
    console.log(`Bake for 25 minutes at 350 celcius`);
  }

  public cut() {
    console.log(`cut the pizza`);
  }

  public box() {
    console.log("boxing");
  }

  public getName(): string {
    return this.name;
  }
}
