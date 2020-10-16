#include <iostream>
#include <algorithm>
typedef long long ll;

using namespace std;

ll input_data[1000001];
ll segtree[4200000]; // 들어오는 입력의 갯수가 항상 트리의 밑에 다 깔릴 수 있게 구성해야 (그냥 2배가 아니라 2^n 형식으로)
int N, M;

void init(int node, int S, int E)
{
  if (S == E)
  {
    if (input_data[S] > 0)
      segtree[node] = 1;
    else if (input_data[S] == 0)
      segtree[node] = 0;
    else if (input_data[S] < 0)
      segtree[node] = -1;
    return;
  }

  init(node * 2, S, (S + E) / 2);
  init(node * 2 + 1, (S + E) / 2 + 1, E);
  segtree[node] = segtree[node * 2] * segtree[node * 2 + 1];
}

ll find(int node, int S, int E, int i, int j)
{
  if (j < S || i > E)
    return 1LL;

  if (i <= S && E <= j)
    return segtree[node];

  return find(node * 2, S, (S + E) / 2, i, j) * find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}

void update(int node, int S, int E, int k, ll x)
{
  if (S == E)
  {
    if (x > 0)
      segtree[node] = 1;
    else if (x == 0)
      segtree[node] = 0;
    else if (x < 0)
      segtree[node] = -1;
    return;
  }

  if ((S + E) / 2 >= k)
    update(node * 2, S, (S + E) / 2, k, x);
  else
    update(node * 2 + 1, (S + E) / 2 + 1, E, k, x);

  segtree[node] = segtree[node * 2] * segtree[node * 2 + 1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> N >> M)
  {
    for (int i = 0; i < N; i++)
      cin >> input_data[i];

    init(1, 0, N - 1);

    char b;
    int c, e;
    ll d;

    for (int i = 0; i < M; i++)
    {
      cin >> b;

      if (b == 'C')
      {
        cin >> c >> d;
        update(1, 0, N - 1, c - 1, d);
      }

      if (b == 'P')
      {
        cin >> c >> e;
        ll res = find(1, 0, N - 1, c - 1, e - 1);
        if (res == 0LL)
          cout << 0;
        else if (res < 0)
          cout << '-';
        else
          cout << '+';
      }
    }
    cout << '\n';
  };
}