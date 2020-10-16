#include <bits/stdc++.h>

using namespace std;

vector<int> v[1001];
int ind[1001];
int hockey[1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;

  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;

    v[x].push_back(y);
    ind[y]++;
  }

  queue<int> q, q2;
  for (int i = 1; i <= n; i++)
  {
    if (ind[i] == 0)
      q.push(i);
  }

  int nowHockey = 1;
  while (!q.empty())
  {
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      hockey[x] = nowHockey;

      for (int next : v[x])
      {
        ind[next]--;
        if (ind[next] == 0)
          q2.push(next);
      }
    }

    nowHockey++;

    while (!q2.empty())
    {
      q.push(q2.front());
      q2.pop();
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << hockey[i] << ' ';
  }
}