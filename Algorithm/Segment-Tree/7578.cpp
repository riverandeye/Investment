#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

ii segment_tree[2100000];

int position[1000001];

void update(int node, int S, int E, int k, int x)
{
  if (S == E)
  {
    segment_tree[node] = ii(x, 1);
    return;
  }

  if ((S + E) / 2 >= k)
    update(node * 2, S, (S + E) / 2, k, x);
  else
    update(node * 2 + 1, (S + E) / 2 + 1, E, k, x);

  segment_tree[node].second = segment_tree[node * 2].second + segment_tree[node * 2 + 1].second;
}

int find(int node, int S, int E, int i, int j)
{
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N, dum;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> dum;
    position[dum] = i;
  }
}