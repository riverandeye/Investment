#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int input_data[1000001];
ii segtree[2100000]; // 들어오는 입력의 갯수가 항상 트리의 밑에 다 깔릴 수 있게 구성해야 (그냥 2배가 아니라 2^n 형식으로)
int N, M;

void init(int node, int S, int E)
{
  if (S == E)
  {
    segtree[node].first = S;
    segtree[node].second = input_data[S];
    return;
  }

  init(node * 2, S, (S + E) / 2);
  init(node * 2 + 1, (S + E) / 2 + 1, E);

  ii left_child = segtree[node * 2];
  ii right_child = segtree[node * 2 + 1];

  if (left_child.second <= right_child.second)
    segtree[node] = left_child;
  else
    segtree[node] = right_child;
}

void update(int node, int S, int E, int k, int x)
{
  if (S == E)
  {
    segtree[node].second = x;
    return;
  }

  if ((S + E) / 2 >= k)
    update(node * 2, S, (S + E) / 2, k, x);
  else
    update(node * 2 + 1, (S + E) / 2 + 1, E, k, x);

  ii left_child = segtree[node * 2];
  ii right_child = segtree[node * 2 + 1];

  if (left_child.second <= right_child.second)
    segtree[node] = left_child;
  else
    segtree[node] = right_child;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++)
    cin >> input_data[i];

  init(1, 1, N);

  cin >> M;

  int a, b, c;

  for (int i = 1; i <= M; i++)
  {
    cin >> a;

    if (a == 1)
    {
      cin >> b >> c;
      update(1, 1, N, b, c);
    }

    else if (a == 2)
    {
      cout << segtree[1].first << '\n';
    }
  }
}