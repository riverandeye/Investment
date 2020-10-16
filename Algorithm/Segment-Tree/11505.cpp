#include <iostream>
typedef long long ll;

using namespace std;

ll input_data[1000001];
ll segtree[3000000]; // 들어오는 입력의 갯수가 항상 트리의 밑에 다 깔릴 수 있게 구성해야 (그냥 2배가 아니라 2^n 형식으로)
int N, M, K;

void init(int node, int S, int E)
{
  if (S == E)
  {
    segtree[node] = input_data[S];
    return;
  }

  init(node * 2, S, (S + E) / 2);
  init(node * 2 + 1, (S + E) / 2 + 1, E);
  segtree[node] = (segtree[node * 2] * segtree[node * 2 + 1]) % 1000000007;
}
ll find(int node, int S, int E, int i, int j)
{
  if (j < S || i > E)
    return 1LL;

  if (i <= S && E <= j)
    return segtree[node] % 1000000007;

  ll a = find(node * 2, S, (S + E) / 2, i, j) % 1000000007;
  ll b = find(node * 2 + 1, (S + E) / 2 + 1, E, i, j) % 1000000007;
  return (a * b) % 1000000007;
}

void update(int node, int S, int E, int k, ll x)
{
  if (S == E)
  {
    segtree[node] = x % 1000000007;
    return;
  }

  if ((S + E) / 2 >= k)
    update(node * 2, S, (S + E) / 2, k, x);
  else
    update(node * 2 + 1, (S + E) / 2 + 1, E, k, x);

  segtree[node] = (segtree[node * 2] * segtree[node * 2 + 1]) % 1000000007;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> K;

  for (int i = 0; i < 3000000; i++)
  {
    segtree[i] = 1;
  }

  for (int i = 0; i < N; i++)
    cin >> input_data[i];

  init(1, 0, N - 1);

  int a, b, c;
  ll d;

  for (int i = 0; i < M + K; i++)
  {
    cin >> a;

    if (a == 1)
    {
      cin >> b >> d;
      update(1, 0, N - 1, b - 1, d);
    }

    else if (a == 2)
    {
      cin >> b >> c;
      cout << find(1, 0, N - 1, b - 1, c - 1) % 1000000007 << '\n';
    }
  }
}