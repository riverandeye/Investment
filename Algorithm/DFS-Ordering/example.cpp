#include <bits/stdc++.h>

using namespace std;

vector<int> v[100001];
int S[100001], E[100001], cc;

void dfs(int N, int p)
{
  printf("%d in \n", N);
  S[N] = ++cc;

  for (int next : v[N])
  {
    if (next == p)
      continue;
    dfs(next, N);
  }
  E[N] = ++cc;
  printf("%d out\n", N);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  // Tree니까
  for (int i = 1; i < n; i++)
  {
  }
}