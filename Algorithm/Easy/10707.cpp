#include <bits/stdc++.h>

using namespace std;

int A,B,C,D,P;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> C >> D >> P;

  int X = A * P;
  int Y = B;

  if(P > C){
    Y += (P - C) * D;
  }

  printf("%d",X > Y ? Y : X);
  return 0;
}