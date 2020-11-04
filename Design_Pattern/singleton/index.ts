export default class Singleton {
  private static singleton: Singleton;

  private constructor() {}

  public static getInstance() {
    if (!this.singleton) {
      this.singleton = new Singleton();
    }

    return this.singleton;
  }
}

const main = () => {
  console.log(Singleton.getInstance());
  console.log(Singleton.getInstance());
};

main();
