#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{

  int n, i, sum = 0, temp;
  int arr[8];

  scanf("%d", &n);

  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  sort(arr, arr + n);

  do
  {
    temp = 0;
    for (i = 0; i < n - 1; i++)
    {
      temp += abs(arr[i] - arr[i + 1]);
    }
    sum = max(sum, temp);
  } while (next_permutation(arr, arr + n));

  printf("%d\n", sum);

  return 0;
}