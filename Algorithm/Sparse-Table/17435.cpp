#include <iostream>

using namespace std;

int d[200001][19];

void query(int n, int x)
{
  for (int k = 18; k >= 0; k--)
  {
    if (n & (1 << k))
      x = d[x][k];
  }

  printf("%d\n", x);
}

int main()
{
  int m;
  scanf("%d", &m);

  for (int i = 1; i <= m; i++)
    scanf("%d", &d[i][0]);

  for (int j = 0; j < 18; j++)
  {
    for (int i = 1; i <= m; i++)
    {
      d[i][j + 1] = d[d[i][j]][j]; // 이전 j가 먼저 채워져야 된다
    }
  }

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    query(a, b);
  }
}