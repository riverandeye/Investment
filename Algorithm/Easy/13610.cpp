#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int a,b;

  cin >> a >> b;

  int lab = 1;
  int cur = a;
  
  lab += (cur % (b-a) == 0) ? cur / (b-a) : cur / (b-a) + 1;

  printf("%d",lab);

  return 0;
}