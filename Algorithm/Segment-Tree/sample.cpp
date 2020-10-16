#include <iostream>

using namespace std;

int input_data[100001];
int tree_odd[210000];  // 들어오는 입력의 갯수가 항상 트리의 밑에 다 깔릴 수 있게 구성해야 (그냥 2배가 아니라 2^n 형식으로)
int tree_even[210000]; // 들어오는 입력의 갯수가 항상 트리의 밑에 다 깔릴 수 있게 구성해야 (그냥 2배가 아니라 2^n 형식으로)
int N, M;

void init_odd(int node, int S, int E)
{
  if (S == E)
  {
    tree_odd[node] = (input_data[S] % 2 == 1) ? 1 : 0;
    return;
  }

  init_odd(node * 2, S, (S + E) / 2);
  init_odd(node * 2 + 1, (S + E) / 2 + 1, E);
  tree_odd[node] = tree_odd[node * 2] + tree_odd[node * 2 + 1];
}

void init_even(int node, int S, int E)
{
  if (S == E)
  {
    tree_even[node] = (input_data[S] % 2 == 1) ? 0 : 1;
    return;
  }

  init_even(node * 2, S, (S + E) / 2);
  init_even(node * 2 + 1, (S + E) / 2 + 1, E);
  tree_even[node] = tree_even[node * 2] + tree_even[node * 2 + 1];
}

int find(int tree[], int node, int S, int E, int i, int j)
{
  if (j < S || i > E)
    return 0;

  if (i <= S && E <= j)
    return tree[node];

  return find(tree, node * 2, S, (S + E) / 2, i, j) + find(tree, node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}

void update_odd(int node, int S, int E, int k, int x)
{
  if (S == E)
  {
    tree_odd[node] = (x % 2 == 1) ? 1 : 0;
    return;
  }

  if ((S + E) / 2 >= k)
    update_odd(node * 2, S, (S + E) / 2, k, x);
  else
    update_odd(node * 2 + 1, (S + E) / 2 + 1, E, k, x);

  tree_odd[node] = tree_odd[node * 2] + tree_odd[node * 2 + 1];
}

void update_even(int node, int S, int E, int k, int x)
{
  if (S == E)
  {
    tree_even[node] = (x % 2 == 1) ? 0 : 1;
    return;
  }

  if ((S + E) / 2 >= k)
    update_even(node * 2, S, (S + E) / 2, k, x);
  else
    update_even(node * 2 + 1, (S + E) / 2 + 1, E, k, x);

  tree_even[node] = tree_even[node * 2] + tree_even[node * 2 + 1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> input_data[i];

  init_odd(1, 0, N - 1);
  init_even(1, 0, N - 1);
  cout << '\n';
  cout << '\n';

  for (int i = 0; i < 3 * N + 1; i++)
  {
    cout << tree_odd[i] << ' ';
  }

  cout << '\n';

  for (int i = 0; i < 3 * N + 1; i++)
  {
    cout << tree_even[i] << ' ';
  }

  cout << '\n';
  cout << '\n';

  cin >> M;

  int a, b, c, d;

  for (int i = 0; i < M; i++)
  {
    cin >> a;

    if (a == 1)
    {
      cin >> b >> d;
      update_odd(1, 0, N - 1, b, d);
      update_even(1, 0, N - 1, b, d);
    }

    else if (a == 2)
    {
      cin >> b >> c;
      cout << find(tree_even, 1, 0, N - 1, b, c) << "ㅎㅎ짝수" << '\n';
    }

    else if (a == 3)
    {
      cin >> b >> c;
      cout << find(tree_odd, 1, 0, N - 1, b, c) << "ㅎㅎ홀수" << '\n';
    }
  }
}