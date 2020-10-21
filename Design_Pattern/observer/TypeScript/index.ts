import NewsApp from "./news";
import Reader from "./reader";

const main = () => {
  const newsApp = new NewsApp("동아", "물가가 떨어졌다.");
  const 관훈 = new Reader("관훈");

  newsApp.registerObserver(관훈);
  newsApp.updateNews("경향", "마스크가 동났다");
};

main();
