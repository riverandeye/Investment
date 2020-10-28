import Beverage from "../beverage/abstract-class";

export default abstract class CondimentDecorator extends Beverage {
  public abstract getDescription(): string; // Re-Implement 를 요구함
}
