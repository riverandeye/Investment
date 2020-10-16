#include <iostream>

using namespace std;

struct edge
{
  int x, y, cost;
} e[100000];

int parent[100001];

int find(int x)
{
  if (parent[x] < 0)
    return x;
  return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
  x = find(x), y = find(y);
  if (x != y)
    parent[x] = y;
}

bool cmp(edge e1, edge e2)
{
  return e1.cost < e2.cost;
}

int main()
{
  memset(parent, -1, sizeof(parent));

  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; i++)
  {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    // e[i] = {x, y, z};
    e[i].x = x;
    e[i].y = y;
    e[i].cost = z;
  }

  int ans = 0;
  sort(e, e + m, cmp);

  for (int i = 0; i < m; i++)
  {
    int x = e[i].x, y = e[i].y, cost = e[i].cost;
    if (find(x) == find(y))
      continue;

    ans += cost;
    merge(x, y);
  }

  printf("%d\n", ans);
}