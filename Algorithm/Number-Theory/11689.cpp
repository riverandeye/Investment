// 정수론

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, b;

vector<ll> dividers;

void get_dividers(ll n) // 소인수를 구하자
{
  ll center = sqrt(n);

  for (int i = 2; i <= center; i++)
  {
    if (n % i == 0)
    {
      dividers.push_back(i);
      while (n % i == 0)
        n /= i;
    }
  }

  if (n > 1)
    dividers.push_back(n);
}

int main()
{
  cin >> n;
  get_dividers(n);

  ll j = n;
  for (ll i = 0; i < dividers.size(); i++)
  {
    j /= dividers[i];
    j *= (dividers[i] - 1);
  }

  cout << j << '\n';
  return 0;
}