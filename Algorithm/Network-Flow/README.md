# 네트워크 플로우

각 간선마다 흘릴 수 있는 최대 유량이 정해져 있음
S에서 T까지 최대 얼마의 유량을 흘릴 수 있는가가 네트워크 플로우 문제



![Flow network - Wikipedia](https://upload.wikimedia.org/wikipedia/commons/thumb/a/ae/Network_flow_residual_SVG.svg/332px-Network_flow_residual_SVG.svg.png)

구현은 어떻게 하느냐

- 포드 풀커슨 알고리즘



더 흘릴 수 있는 양을 노드에 저장

남은 유량이 0보다 큰 경로로 이동해서 S->T로 갈 수 있는 아무 경로나 선택

경로에서 가장 적게 흘리는 유량에 대해 모든 경로에 그 크기를 줄인다. 

그리고 그 줄인 만큼의 역방향 간선을 모든 경로에 추가한다. 

경로가 없어질 때 까지 간선을 추가하면 된다. 



- 디닉 알고리즘 (더 빠름)
  - 근데 매우 어려움