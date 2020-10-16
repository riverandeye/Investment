#include <bits/stdc++.h>

using namespace std;

vector<int> v[100001];
int ind[100000];

int main()
{
  int n, m;

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    ind[y]++;
  }

  queue<int> q;
  for (int i = 1; i < n; i++)
  {
    if (ind[i] == 0)
      q.push(i);
  }

  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    printf("%d ", x);
    for (int next : v[x])
    {
      ind[next]--;
      if (ind[next] == 0)
        q.push(next);
    }
  }
}
