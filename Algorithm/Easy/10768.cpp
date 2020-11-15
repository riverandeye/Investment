#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int a,b;
  cin >> a >> b;

  if(a > 2){
    printf("After");
  }
  else if(a == 1){
    printf("Before");
  }
  else if (b > 18){
    printf("After");
  }
  else if (b == 18){
    printf("Special");
  }
  else {
    printf("Before");
  }

  return 0;
}