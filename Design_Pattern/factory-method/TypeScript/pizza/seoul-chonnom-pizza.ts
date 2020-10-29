import Pizza from "./abstract";

export default class SeoulChonnomPizza extends Pizza {
  public constructor() {
    super();

    this.name = "서울 촌놈 피자";
    this.dough = "호밀빵";
    this.sauce = "크림";
  }

  public cut() {
    console.log("Don't Cut");
  }
}
