### Spanning Tree

그래프의 간선을 이용해서 트리를 만들어준다 -> 스패닝 트리
왜 Minimum이냐 -> 간선의 가중치의 합이 Minimum

간선을 정렬하는 시간복잡도인 ElogE 만 큼 든다
Union Find는 거의 O(mlog\*n)

#### Kruskal

기본적으로 Greedy Algorithm
간선의 가중치가 작은 것 부터 추가한다
이때 추가하려는 두 정점은 반드시 다른 컴포넌트 여야 한다.

- 어떻게 다른 컴포넌트인 것을 알 수 있을까? 걍 Set 연산하던지 배열하나 만들어서 넣던지
- Union Find 알고리즘을 이용한다
