#include <bits/stdc++.h>

using namespace std;

int main()
{
  bool check[1000001];

  int i, j, a, b, n;

  for (i = 1; i <= 1000000; i++)
    check[i] = true;
  for (i = 2; i <= sqrt(1000000); i++)
  {
    for (j = i + i; j <= 1000000; j += i)
    {
      if (check[j] == true)
        check[j] = false;
    }
  }

  while (1)
  {
    scanf("%d", &n);
    if (n == 0)
      break;
    i = 3;
    while (1)
    {
      if (n - i < 0)
      {
        printf("Goldbach's conjecture is wrong.\n");
        break;
      }
      if (check[i] == true && check[n - i] == true)
      {
        printf("%d = %d + %d\n", n, i, n - i);
        break;
      }
      i++;
    }
  }

  return 0;
}