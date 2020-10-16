#include <bits/stdc++.h>

using namespace std;

vector<int> child[1001];
int ind[1001];
int delay[1001];
int total_delay[1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T, N, K, Building;

  cin >> T;

  while (T--)
  {
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
      cin >> delay[i];

    for (int i = 1; i <= K; i++)
    {
      int x, y;
      cin >> x >> y;

      child[x].push_back(y);
      ind[y]++;
    }

    cin >> Building;

    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
      if (ind[i] == 0)
        q.push(i);
    }

    while (!q.empty())
    {
      int x = q.front();
      q.pop();

      if (x == Building)
        break;

      for (int next : child[x])
      {
        ind[next]--;
        if (ind[next] == 0)
          q.push(next);

        if (total_delay[next] < total_delay[x] + delay[x])
          total_delay[next] = total_delay[x] + delay[x];
      }
    }

    // cout << "\n디버깅\n";
    // for (int i = 1; i <= N; i++)
    //   cout
    //       << total_delay[i] << ' ';

    // cout << '\n';

    cout << total_delay[Building] + delay[Building] << '\n';
    // cout << "정답 : " << total_delay[Building] + delay[Building] << '\n';

    while (!q.empty())
      q.pop();

    for (int i = 1; i <= N; i++)
    {
      child[i].clear();
      total_delay[i] = 0;
      ind[i] = 0;
    }
  }
}