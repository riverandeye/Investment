#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int A,B,C,D;
  cin >> A >> B >> C >> D;

  printf("%d", A+D > B+C ? B+C:A+D);

  return 0;
}