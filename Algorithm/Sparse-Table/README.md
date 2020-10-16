Sparse Table

i부터 j까지의 구간합을 구하는데

d[i][0] <- i 부터 2^0의 구간합
d[i][1] <- i 부터 2^1의 구간합
d[i][2] <- i 부터 2^2의 구간합

i부터 10개 구간합 (i ~ i+9)을 구하려면
d[i][3] + d[i + 8][1]
으로 2^k 만큼 계산을 하는 것

조건은 대신 업데이트가 없어야 한다.

전처리 nlogn
쿼리 logn

---

https://www.acmicpc.net/problem/17435

d[i][j+1] = d[d[i][j]][j]

2^k 번 할것을 한번에 미리 돌려놓는 마인드.

---

구간 최대 구간 최소를 전처리 O(NlogN)
쿼리당 O(1) 로 하는 방법을 알아보자.

d[i][j] = i 부터 2^j개 최대값
d[i][0] = a[i]
d[i][1] = max(d[i][0], d[i + (1<<0)][0])
d[i][2] = max(d[i][1], d[i + (1<<1)][1])
d[i][j+1] = max(d[i][j], d[i + (1<<j)][j])

이렇게 전처리하고

최댓값을 구하는건
max(max([1,10], max([5,15]))) = max([1,15]) 임을 이용해서

찾으려는 구간이 l - r 이면
l - r + 1을 최대로 만족하는 2^m을 구한후
양쪽에서 빼서 최대를 찾는 방식으로 구한다.

max(d[l][m], d[r-2^m+1][m]) 이런식으로

중요한 건, Log에 해당하는 값을 O(n)으로 구해놓아야 복잡도를 O(NlogN) 으로 제한할 수 있다.

for(i = 0 ; i <16 ; i++){
Logg[1<<i] = i;
}

for(i : 1~10만) {
if(!Logg[i]) Log[i] = Log[i-1]; // 없으면 이전값을
}

---

정리해보면

- 데이터에 대한 사전 연산을 오른쪽으로 쌓는거고

---

LCA
LCA를 구하는 방법중에서 가장 쉬운 방법이 Sparse Tree이다.
LCA는 트리의 최소 공통 조상이다.

Sparse Tree를 이용하면 임의의 두 정점간의 거리를 O(1)에 구할 수 있다.

공통 조상이 u면
x와 y 사이의 거리 : depth[x] + depth[y] - 2 \* depth[u]

Sparse Tree를 정의하면

d[i][k] = i의 2^j번째 부모
d[i][0] = dfs 돌면서 계산 (그 노드의 깊이와 부모를 계산하며, 루트의 부모는 -1, 깊이는 0)

vector v[n] : N과 연결된 정점

```c++
void dfs(int N, int p){
  parent[N][0] = p; // 부모정보
  for (int next : v[N]){
    if(next == p) continue
    depth[next] = depth[N] + 1 // 깊이정보
    dfs(next, N);
  }
}

dfs(1,-1) // 초기화

parent[i][j + 1] = parent[parent[i][j]][j]

if(parent[i][j] == -1) continue;
```

여기까지 Sparse Tree를 초기화햇음.
그 다음엔 쿼리! (O(logN))

1. 깊이를 맞춘다
2. 안만날때까지 2^k 만큼 올라간다
3. 그 둘의 부모가 공통조상

```c++

```

---

숙제 : https://www.acmicpc.net/problem/2357
