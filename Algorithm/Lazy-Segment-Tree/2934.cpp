#include <iostream>

using namespace std;
typedef long long ll;

ll segtree[4100000];
ll lazy_val[4100000];
int N, M, K;
int WIDTH = 100000;

void propagation(int node, int S, int E)
{
  if (lazy_val[node] == 0)
    return;

  segtree[node] += lazy_val[node];

  if (S != E)
  {
    lazy_val[node * 2] += lazy_val[node];
    lazy_val[node * 2 + 1] += lazy_val[node];
  }

  lazy_val[node] = 0;
}

ll find(int node, int S, int E, int i, int j)
{
  propagation(node, S, E);

  if (j < S || i > E)
    return 0LL;

  if (i <= S && E <= j)
  {
    int a = segtree[node];
    segtree[node] = 0;
    return a;
  }

  return find(node * 2, S, (S + E) / 2, i, j) + find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}

void update(int node, int S, int E, int i, int j)
{
  propagation(node, S, E);

  if (i > E || j < S)
    return;

  if (i <= S && E <= j)
  {
    lazy_val[node] += 1;
    propagation(node, S, E);
    return;
  }

  update(node * 2, S, (S + E) / 2, i, j);
  update(node * 2 + 1, (S + E) / 2 + 1, E, i, j);

  segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int a, b;

    cin >> a >> b;

    if (b - a >= 2)
    {
      update(1, 0, WIDTH - 1, a, b - 2);
    }

    cout << find(1, 0, WIDTH - 1, a - 1, a - 1) + find(1, 0, WIDTH - 1, b - 1, b - 1) << '\n';
  }
}