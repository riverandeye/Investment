#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--)
  {
    string a, b;
    cin >> a >> b;

    string c = a;
    string d = b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << c << " & " << d << " are";

    if (a.compare(b) != 0)
    {
      cout << " NOT";
    }

    cout << " anagrams.\n";
  }
}