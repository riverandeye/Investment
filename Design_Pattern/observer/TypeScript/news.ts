import Subject from "./lib/subject";

export default class NewsApp extends Subject {
  public constructor(public name: string, public message: string) {
    super();
  }

  updateNews(name: string, message: string) {
    this.message = message;
    this.name = name;

    this.notifyObserver(this);
  }
}
