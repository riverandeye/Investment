#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  char a[11];
  int t, ans[11];
  cin >> t;
  while (t--)
  {
    int cnt = 0;
    for (int i = 0; i < 11; i++)
    {
      a[i] = '0';
      ans[i] = 0;
    }
    cin >> a;
    for (int i = 0; i < strlen(a); i++)
      ans[a[i] - '0']++;
    for (int i = 0; i < 10; i++)
      if (ans[i] > 0)
        cnt++;
    cout << cnt << '\n';
  }
}
