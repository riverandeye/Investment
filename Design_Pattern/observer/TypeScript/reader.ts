import Observer from "./lib/observer";
import Subject from "./lib/subject";

import NewsApp from "./news";

export default class Reader implements Observer {
  public constructor(public name: string) {}

  public update(subject: Subject) {
    if (subject instanceof NewsApp) {
      console.log(
        `${this.name} : 흠 ${subject.name} 뉴스의 새로 업데이트된 내용 ${subject.message} 는 정말 흥미롭구만`,
      );
    }
  }
}
