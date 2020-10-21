import Observer from "./observer";

export default class Subject {
  private observers: Observer[];

  public constructor() {
    this.observers = [];
  }

  public registerObserver(observer: Observer) {
    this.observers.push(observer);
  }

  public removeObserver(observer: Observer) {
    this.observers = this.observers.filter((v) => v !== observer);
  }

  private notifyObserver(subject: Subject) {
    this.observers.forEach((observer) => observer.update(subject));
  }
}
