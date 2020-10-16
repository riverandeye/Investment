// #include <bits/stdc++.h> 이거 해놔라
#include <iostream>
#include <algorithm>
#define INF 2147483647

using namespace std;

int input_data[1000001];
pair<int, int> segtree[2100000];
int N, M;

void init(int node, int S, int E)
{
  if (S == E)
  {
    segtree[node].first = input_data[S];
    segtree[node].second = input_data[S];
    return;
  }

  init(node * 2, S, (S + E) / 2);
  init(node * 2 + 1, (S + E) / 2 + 1, E);
  segtree[node].first = min(segtree[node * 2].first, segtree[node * 2 + 1].first);
  segtree[node].second = max(segtree[node * 2].second, segtree[node * 2 + 1].second);
}

pair<int, int> find(int node, int S, int E, int i, int j)
{
  if (j < S || i > E)
    return pair<int, int>(INF, -INF);

  if (i <= S && E <= j)
    return segtree[node];

  pair<int, int> res_left = find(node * 2, S, (S + E) / 2, i, j);
  pair<int, int> res_right = find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);

  int minres = min(res_left.first, res_right.first);
  int maxres = max(res_left.second, res_right.second);

  return pair<int, int>(minres, maxres);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    cin >> input_data[i];

  init(1, 0, N - 1);

  int a, b;
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    pair<int, int> res = find(1, 0, N - 1, a - 1, b - 1);
    cout << res.first << ' ' << res.second << '\n';
  }
}