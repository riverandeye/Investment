#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  if (next_permutation(a.begin(), a.end()))
  {
    for (int i = 0; i < n; i++)
    {
      cout << a[i] << ' ';
    }
  }
  else
  {
    cout << "-1";
  }
  cout << '\n';
  return 0;
}