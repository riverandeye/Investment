#include <iostream>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;

ll gcd(ll a, ll b)
{
  if (a == 0)
    return b;
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

Pll exgcd(ll a, ll b) // ax+by=gcd(a,b)
{
  if (!b)
    return {1, 0};
  ll x, y;
  tie(x, y) = exgcd(b, a % b); //C++11 이상
  return {y, x - (a / b) * y};
}

int main()
{
  ll N, A;
  cin >> N >> A;
  cout << N - A << '\n';

  return 0;
}