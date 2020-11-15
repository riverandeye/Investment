#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int a,b;

  cin >> a >> b;

  if(a==b){
    printf("%d",a);
  }
  else {
    printf("%d", a > b ? a : b);
  }

  return 0;
}