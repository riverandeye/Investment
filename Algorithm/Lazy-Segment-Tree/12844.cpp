#include <iostream>

using namespace std;
typedef long long ll;

int input_data[1000001];
int segtree[4100000];
int lazy_val[4100000];
int N, M, K;

void propagation(int node, int S, int E)
{
  if (lazy_val[node] == 0)
    return;

  segtree[node] ^= ((E - S + 1) % 2) * lazy_val[node];

  if (S != E)
  {
    lazy_val[node * 2] ^= lazy_val[node];
    lazy_val[node * 2 + 1] ^= lazy_val[node];
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
  segtree[node] = segtree[node * 2] ^ segtree[node * 2 + 1];
}

int find(int node, int S, int E, int i, int j)
{
  propagation(node, S, E);

  if (j < S || i > E)
    return 0LL;

  if (i <= S && E <= j)
    return segtree[node];

  return find(node * 2, S, (S + E) / 2, i, j) ^ find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}

void update(int node, int S, int E, int i, int j, int x)
{
  propagation(node, S, E);

  if (i > E || j < S)
    return;

  if (i <= S && E <= j)
  {
    lazy_val[node] ^= x;
    propagation(node, S, E);
    return;
  }

  update(node * 2, S, (S + E) / 2, i, j, x);
  update(node * 2 + 1, (S + E) / 2 + 1, E, i, j, x);

  segtree[node] = segtree[node * 2] ^ segtree[node * 2 + 1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> input_data[i];

  init(1, 0, N - 1);

  int a, b, c;
  int d;

  cin >> M;

  for (int i = 0; i < M; i++)
  {
    cin >> a;

    if (a == 1)
    {
      cin >> b >> c >> d;

      update(1, 0, N - 1, b, c, d);
    }

    else if (a == 2)
    {
      cin >> b >> c;
      cout << find(1, 0, N - 1, b, c) << '\n';
    }
  }
}