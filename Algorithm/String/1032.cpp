#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
  int n;
  int check[60];
  string s[60];

  memset(check, 0, sizeof(check));

  cin >> n;

  cin >> s[0];
  for (int i = 1; i < n; ++i)
  {
    cin >> s[i];

    for (int j = 0; j < s[0].length(); ++j)
    {
      if (s[i][j] != s[i - 1][j])
      {
        check[j] = 1;
      }
    }
  }

  for (int i = 0; i < s[0].length(); ++i)
  {
    if (check[i] == 0)
    {
      cout << s[0][i];
    }
    else
    {
      cout << "?";
    }
  }

  return 0;
}
