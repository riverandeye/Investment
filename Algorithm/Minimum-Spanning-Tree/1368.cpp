#include <iostream>
#include <string.h>
#include <algorithm>

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
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  memset(parent, -1, sizeof(parent));

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    int price;
    scanf("%d", &price);

    e[i].x = 0;
    e[i].y = i + 1;
    e[i].cost = price;
  }

  int count = n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      int price;
      scanf("%d", &price);
      // e[i] = {x, y, z};

      if (i == j)
        continue;

      e[count].x = i + 1;
      e[count].y = j + 1;
      e[count].cost = price;

      count++;
    }

  int ans = 0;
  sort(e, e + count, cmp);

  for (int i = 0; i < count; i++)
  {
    int x = e[i].x, y = e[i].y, cost = e[i].cost;
    if (find(x) == find(y))
      continue;

    ans += cost;
    merge(x, y);
  }

  printf("%d\n", ans);
}