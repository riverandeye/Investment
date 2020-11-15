#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int a,b,c;

  cin >> a >> b >> c;

  long long d = a % c == 0 ? a / c : a / c + 1;
  long long e = b % c == 0 ? b / c : b / c + 1;

  printf("%lld", d*e);
  return 0;
}