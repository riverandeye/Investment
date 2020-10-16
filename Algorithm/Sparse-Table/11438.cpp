#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100001];
int parent[100001][17], depth[100001];

void dfs(int N, int p)
{
  parent[N][0] = p; // 부모정보

  for (int next : v[N])
  {
    if (next == p)
      continue;

    depth[next] = depth[N] + 1; // 깊이정보
    dfs(next, N);
  }
}

int LCA(int x, int y)
{
  // 우선 depth를 맞춰준다
  if (depth[x] < depth[y]) // x가 더 낮게끔 바꿔준다.
    swap(x, y);

  int k = depth[x] - depth[y]; // depth 차이

  for (int i = 16; i >= 0; i--)
  {
    if (k & (1 << i)) // depth가 낮은걸 위로 올려준다.
      x = parent[x][i];
  }

  if (x == y) // 같으면 그게 부모
    return x;

  for (int i = 16; i >= 0; i--)
  {
    if (parent[x][i] != parent[y][i])
      x = parent[x][i], y = parent[y][i];
  }

  return parent[x][0];
}

int main()
{
  int n, m;
  scanf("%d", &n);

  for (int i = 1; i < n; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);

    v[x].push_back(y);
    v[y].push_back(x);
  }

  dfs(1, -1);

  for (int j = 0; j < 16; j++)
  {
    for (int i = 1; i <= n; i++)
    {
      if (parent[i][j] == -1)
        continue;

      parent[i][j + 1] = parent[parent[i][j]][j];
    }
  }

  scanf("%d", &m);

  while (m--)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", LCA(a, b));
  }
}