#include <iostream>
using namespace std;

int main()
{
  long long n, m;

  cin >> n >> m;

  long long res;

  if (n > m)
  {
    res = n - m;
  }
  else
  {
    res = -n + m;
  }

  cout << res;
}
