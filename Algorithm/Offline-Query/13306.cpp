#include <bits/stdc++.h>

using namespace std;

tuple<int,int,int> query[400001];

int saved_parent[200001];
int parent[200001];

int find(int x)
{
  if (parent[x] < 0)
    return x;
  return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
  x = find(x), y = find(y);
  if (x != y)
    parent[x] = y;
}

int N, Q;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> Q;

  for(int i = 0 ; i < N ; i++){
    parent[i] = -1;
  }

  int par;
  for(int i = 1 ; i < N; i++){
    cin >> par;
    saved_parent[i] = par - 1;
  }

  for(int i = 0 ; i < N + Q - 1; i++){
    int a,b,c;

    cin >> a;
    if(a){
      cin >> b >> c;
      query[i] = tuple<int,int,int>(a,b-1,c-1);
    }
    else {
      cin >> b;
      query[i] = tuple<int,int,int>(a,b-1,-1);
    }
  }

  vector<string> res;
  for(int i = N + Q - 2 ; i >= 0; i--){
    int a = get<0>(query[i]),c;
    int b = get<1>(query[i]);

    if(a){
      c = get<2>(query[i]);
      int d = find(b);
      int e = find(c);

      if (d==e) res.push_back("YES\n");
      else res.push_back("NO\n");
    }

    else{
      merge(b,saved_parent[b]);
    }
  }

  for(int i = res.size()-1 ; i >= 0; i--){
    cout << res[i];
  }
}