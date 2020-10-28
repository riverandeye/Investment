export default abstract class Beverage {
  public description: string = "Unknown Beverage";

  public getDescription() {
    return this.description;
  }

  public abstract cost(): number;
}
