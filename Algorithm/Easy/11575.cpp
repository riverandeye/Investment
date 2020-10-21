#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100
#define INF 0x7fffffff
#define CENDL "\n"
#define ll long long

#define c_reverse(s) reverse(s.begin(), s.end())
#define c_sort(s) sort(s.begin(), s.end())

#define print_vector(v)              \
  for (int i = 0; i < v.size(); i++) \
    cout << v[i];

int cipher(int index, int a, int b)
{
  return ((a * index) + b) % 26;
}

int main()
{

  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  cin >> n;

  while (n--)
  {
    int e, c;
    cin >> e >> c;
    string s;
    cin >> s;

    const int size = s.size();
    for (int i = 0; i < size; i++)
    {
      int cand = cipher(s[i] - 'A', e, c);
      cout << char('A' + cand);
    }
    cout << CENDL;
  }

  return 0;
}