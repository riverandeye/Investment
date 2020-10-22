import NewsApp from "./news";
import Reader from "./reader";

const main = () => {
  const newsApp = new NewsApp("동아", "물가가 떨어졌다.");
  const 관훈 = new Reader("관훈");
  const 진용 = new Reader("진용");

  newsApp.registerObserver(관훈);
  newsApp.registerObserver(진용);
  newsApp.updateNews("경향", "마스크가 동났다");

  newsApp.removeObserver(관훈);
  newsApp.updateNews("유투브", "미노이 Vlog");
};

main();
