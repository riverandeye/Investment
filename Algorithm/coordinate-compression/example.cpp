#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int a[100000];
int main()
{
  int n;
  scanf("%d", &n);

  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", a + i);
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  for (int i = 0; i < n; i++)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();

  // 값을 가져올 땐
}