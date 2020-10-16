#include <iostream>

using namespace std;

int a[200000], d[200000][18];

int query(int i, int j)
{
  int l = j - i + 1;
  int res = 0;

  for (int k = 17; k >= 0; k--)
  {
    if (l & (1 << k))
    {
      res += d[i][k];
      i += (1 << k);
    }
  }

  return res;
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", a + i);
    d[i][0] = a[i];
  }

  for (int j = 0; j < 16; j++)
  {
    for (int i = 0; i < n; i++)
    {
      if (i + (1 << (j + 1)) > n)
        break;

      d[i][j + 1] = d[i][j] + d[i + (1 << j)][j];
    }
  }
}