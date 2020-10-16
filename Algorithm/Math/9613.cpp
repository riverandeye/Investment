#include <bits/stdc++.h>

using namespace std;

int tcs[101];

int gcd(int a, int b)
{
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--)
  {
    int a;
    cin >> a;

    for (int i = 0; i < a; i++)
      cin >> tcs[i];

    long long res = 0;

    for (int i = 0; i < a; i++)
      for (int j = i + 1; j < a; j++)
        res += gcd(tcs[i], tcs[j]);

    cout << res << '\n';
  }
}