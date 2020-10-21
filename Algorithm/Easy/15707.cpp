#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

bool compare(string s)
{
  if (s.length() > 19)
  {
    return true;
  }
  else if (s.length() < 19)
  {
    return false;
  }
  else
  {
    return s.compare("9223372036854775807") > 0;
  }
}

int main(int argc, char *argv[])
{
  ll r, a, b;
  string s1, s2;

  cin >> s1 >> s2 >> r;

  if (s1 == "0" || s2 == "0")
  {
    cout << "0" << endl;
  }
  else if (compare(s1) || compare(s2))
  {
    cout << "overflow" << endl;
  }
  else
  {
    a = stoll(s1);
    b = stoll(s2);

    if (a > (r / b))
    {
      cout << "overflow" << endl;
    }
    else
    {
      cout << a * b << endl;
    }
  }

  return 0;
}