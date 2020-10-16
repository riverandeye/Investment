#include <iostream>

using namespace std;
typedef long long ll;

ll input_data[1000001];
ll segtree[4100000];
ll lazy[4100000];
int N, M, K;

void propagate(int node, int S, int E)
{
  if (lazy[node] == 0)
    return;

  segtree[node] += (E - S + 1) * lazy[node];

  if (S != E)
  {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }

  lazy[node] = 0;
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
  propagate(node, S, E);

  if (j < S || i > E)
    return 0LL;

  if (i <= S && E <= j)
    return segtree[node];

  return find(node * 2, S, (S + E) / 2, i, j) + find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}

void update(int node, int S, int E, int i, int j, ll x)
{
  propagate(node, S, E);

  if (i > E || j < S)
    return;

  if (i <= S && E <= j)
  {
    lazy[node] += x;
    propagate(node, S, E);
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

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> input_data[i];

  init(1, 0, N - 1);

  cin >> M;

  int a, i, j, n;
  ll k;

  for (int r = 0; r < M; r++)
  {
    cin >> a;

    if (a == 1)
    {
      cin >> i >> j >> k;
      update(1, 0, N - 1, i - 1, j - 1, k);
    }

    else if (a == 2)
    {
      cin >> n;
      cout << find(1, 0, N - 1, n - 1, n - 1) << '\n';
    }
  }
}