#include <bits/stdc++.h>

using namespace std;

double arr[1000000];

int main(){
  int n;

  cin >> n;

  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
    arr[i] *= 0.8;
  }

  for(int i = 0 ; i < n ; i++){
    printf("$%.2lf\n", arr[i]);
  }
}

