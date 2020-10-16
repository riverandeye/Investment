#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll input_data[100001];
ll segtree[810000];
int sangsa[100001];

vector<int> vec[100001];
int S[100001], E[100001], cc;

ll lazy_val[810000];
int N, M, K;

void dfs(int n, int p)
{
  S[n] = ++cc;

  for (int next : vec[n])
  {
    if (next == p)
      continue;
    dfs(next, n);
  }
  E[n] = ++cc;
}

void propagation(int node, int S, int E)
{
  if (lazy_val[node] == 0)
    return;

  segtree[node] += (E - S + 1) * lazy_val[node];

  if (S != E)
  {
    lazy_val[node * 2] += lazy_val[node];
    lazy_val[node * 2 + 1] += lazy_val[node];
  }

  lazy_val[node] = 0;
}

void init(int node, int S, int E)
{
  if (S == E)
  {
    segtree[node] = input_data[S];
    return;
  }

  init(node * 2, S, (S + E) / 2);
  init(node * 2 + 1, (S + E) / 2 + 1, E);
  segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

ll find(int node, int S, int E, int i, int j)
{
  propagation(node, S, E);

  if (j < S || i > E)
    return 0LL;

  if (i <= S && E <= j)
    return segtree[node];

  return find(node * 2, S, (S + E) / 2, i, j) + find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}

void update(int node, int S, int E, int i, int j, ll x)
{
  propagation(node, S, E);

  if (i > E || j < S)
    return;

  if (i <= S && E <= j)
  {
    lazy_val[node] += x;
    propagation(node, S, E);
    return;
  }

  update(node * 2, S, (S + E) / 2, i, j, x);
  update(node * 2 + 1, (S + E) / 2 + 1, E, i, j, x);

  segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; i++)
  {
    cin >> sangsa[i];

    if (sangsa[i] == -1)
      continue;

    vec[sangsa[i]].push_back(i);
  }

  dfs(1, -1);

  int a, b, c, d;
  for (int i = 0; i < M; i++)
  {
    cin >> a;

    if (a == 1)
    {
      cin >> b >> c;
      update(1, 1, N * 2, S[b], E[b], c);
    }

    else if (a == 2)
    {
      cin >> d;
      cout << find(1, 1, N * 2, S[d], S[d]) << '\n';
    }
  }
}