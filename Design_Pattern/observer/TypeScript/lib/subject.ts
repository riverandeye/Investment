import Observer from "./observer";

export default class Subject {
  private observers: Observer[];

  public constructor() {
    this.observers = [];
  }

  registerObserver(observer: Observer) {
    this.observers.push(observer);
  }

  removeObserver(observer: Observer) {
    this.observers = this.observers.filter((v) => v !== observer);
  }

  notifyObserver(subject: Subject) {
    this.observers.forEach((observer) => observer.update(subject));
  }
}
