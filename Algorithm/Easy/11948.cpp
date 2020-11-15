#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int A[6];
  int fst = 101 ,snd = 101, res = 0;

  for(int i = 0 ; i < 6 ; i++){
    cin >> A[i];
    res += A[i];
  }

  for(int i = 0 ; i < 4 ; i ++){
    if(fst > A[i]){
      fst = A[i];
    }
  }

  for(int i = 4 ; i < 6 ; i++){
    if(snd > A[i]){
      snd = A[i];
    }
  }
  
  printf("%d", res - fst - snd);

  return 0;
}