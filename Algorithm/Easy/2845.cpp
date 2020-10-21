#include <iostream>
using namespace std;

int main()
{
  int l, p, a[5];
  cin >> l >> p;
  for (int i = 0; i < 5; i++)
  {
    cin >> a[i];
    cout << a[i] - l * p << " ";
  }
  return 0;
}