#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;

vector<ii> v[100001]; // 자식, 거리 순
int parent[100001][17], depth[100001];
ii minmaxdist[100001][17];

void dfs(int N, int p)
{
  parent[N][0] = p; // 부모정보
  for (ii next : v[N])
  {
    if (next.first == p)
      continue;

    depth[next.first] = depth[N] + 1; // 깊이정보
    minmaxdist[next.first][0].first = next.second;
    minmaxdist[next.first][0].second = next.second;
    dfs(next.first, N);
  }
}

void LCA(int x, int y)
{
  // 우선 depth를 맞춰준다
  int minval = 1000001;
  int maxval = 0;

  if (depth[x] < depth[y]) // x가 더 낮게끔 바꿔준다.
    swap(x, y);

  int k = depth[x] - depth[y]; // depth 차이

  for (int i = 16; i >= 0; i--)
  {
    if (k & (1 << i)) // depth가 낮은걸 위로 올려준다.
    {
      minval = min(minval, minmaxdist[x][i].first);
      maxval = max(maxval, minmaxdist[x][i].second);
      x = parent[x][i];
    }
  }

  if (x == y) // 같으면 그게 부모
  {
    printf("%d %d\n", minval, maxval);
    return;
    // return x;
  }

  for (int i = 16; i >= 0; i--)
  {
    if (parent[x][i] != parent[y][i])
    {
      minval = min(minval, min(minmaxdist[x][i].first, minmaxdist[y][i].first));
      maxval = max(maxval, max(minmaxdist[x][i].second, minmaxdist[y][i].second));
      x = parent[x][i], y = parent[y][i];
    }
  }

  // 마지막꺼를 해줘야한다
  minval = min(minval, min(minmaxdist[x][0].first, minmaxdist[y][0].first));
  maxval = max(maxval, max(minmaxdist[x][0].second, minmaxdist[y][0].second));

  // return parent[x][0];
  printf("%d %d\n", minval, maxval);
}

int main()
{
  int N, K;
  scanf("%d", &N);

  for (int i = 1; i < N; i++)
  {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    v[x].push_back(make_pair(y, z));
    v[y].push_back(make_pair(x, z));
  }

  dfs(1, -1);

  for (int j = 0; j < 16; j++)
  {
    for (int i = 1; i <= N; i++)
    {
      if (parent[i][j] == -1)
        continue;

      parent[i][j + 1] = parent[parent[i][j]][j];
      minmaxdist[i][j + 1].first = min(minmaxdist[i][j].first, minmaxdist[parent[i][j]][j].first);
      minmaxdist[i][j + 1].second = max(minmaxdist[i][j].second, minmaxdist[parent[i][j]][j].second);
    }
  }

  scanf("%d", &K);

  for (int i = 0; i < K; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    LCA(a, b);
  }
}