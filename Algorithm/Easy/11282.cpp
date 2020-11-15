#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  double h,w,tmp;

  cin >> h >> w;

  if(h < w){
    tmp = h;
    h = w;
    w = tmp;
  }

  if(h > w * 3){
    printf("%lf", w);
  }
  else if (h > w * 1.5){
    printf("%lf", h / 3);
  }
  else {
    printf("%lf", w /2);
  }

  return 0;
}