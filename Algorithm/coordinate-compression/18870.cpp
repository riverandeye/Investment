#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int comp[1000001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, dum;
  cin >> n;

  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    cin >> comp[i];
    v.push_back(comp[i]);
  }

  sort(v.begin(), v.end());

  v.resize(unique(v.begin(), v.end()) - v.begin());

  for (int i = 0; i < n; i++)
  {
    comp[i] = lower_bound(v.begin(), v.end(), comp[i]) - v.begin();
    cout << comp[i] << ' ';
  }
  cout << '\n';
}