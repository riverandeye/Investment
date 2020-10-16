# Segment Tree



### Introduction

일반적인 배열이 있을 떄, 배열 내 구간의 합을 구하고 싶다. 

[3,1,4,3,5,6] 배열에서 1 ~ 3 번째 index 의 합을 구하고 싶으면

Prefix Sum을 이용해서 Sum[4] - Sum[1] 으로 구하면 쉽다



만약 Update를 하게 되면 Prefix Sum의 업데이트가 O(N) 이 걸린다. -> 매우 비효율적



이를 극복하기 위해 구간을 분리한다.



Find와 Update 모두 log(N)이다.



부분합, 구간내 최소값 최댓값, 부분행렬값 등

응용할 수 있는 게 매우 무궁무진하다.



### Implement

자동으로 구간 합에 대한 정보가 반영이 되어야 한다.



```c++
#include <iostream>
typedef long long ll;

using namespace std;

ll input_data[1000001];
ll segtree[2100000]; // 들어오는 입력의 갯수가 항상 트리의 밑에 다 깔릴 수 있게 구성해야 (그냥 2배가 아니라 2^n 형식으로)
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
  segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

ll find(int node, int S, int E, int i, int j)
{
  if (j < S || i > E)
    return 0LL;

  if (i <= S && E <= j)
    return segtree[node];

  return find(node * 2, S, (S + E) / 2, i, j) + find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}

void update(int node, int S, int E, int k, ll x)
{
  if (S == E)
  {
    segtree[node] = x;
    return;
  }

  if ((S + E) / 2 >= k)
    update(node * 2, S, (S + E) / 2, k, x);
  else
    update(node * 2 + 1, (S + E) / 2 + 1, E, k, x);

  segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> K;

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
      cout << find(1, 0, N - 1, b - 1, c - 1) << '\n';
    }
  }
}
```

init, find, update 의 부분합 구현 예시이다.



### K-th Element 구하기

- 어떤 배열에서 k번째로 작은 원소를 O(logN)에 구하기 (Update 없으면 Sort 해버리면 되는데 그경우는 아님)
- Update 가 존재하고, Update도 O(logN)인 경우



init을 통해 각 구간에 포함되는 원소의 갯수를 node에 담는다. 

찾는거는 위에서부터 왼쪽, 오른쪽으로 가되, 왼쪽으로 가는 경우는 그대로 가면 되고 오른쪽은 k를 왼쪽 값에서 빼주면 된다.

update는 

- 같으면 찾은거니까 그거 빼주거나 더하고 (빼는 경우도 있을 거니까)
- 왼쪽 오른쪽 가면 되고 업데이트하면 되고



