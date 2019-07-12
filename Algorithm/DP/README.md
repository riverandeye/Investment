# Dynamic Programming :running_woman:

### Definition

- Mathematical Optimization method - **Solve problems by combining the solution to subproblem**

- DP는 DAQ와는 달리, **Subproblem이 overlap** 할 때에 사용한다.

  <br>

### Elements of DP

- Optimal Substructure
  - 최적해가 substructure의 최적해로 구성되어 있는 경우, Optimal substructure 를 가진다.
  - Optimal substructure 에 의해 문제 해결 과정 중에
    - 여러가지 선택지가 있으며, 그중 최선을 선택해야 한다.
    - Subproblem이 어떤식으로 구성되는지를 파악해야한다.
    - nonOptimal 이 였던 것 위에 더욱 Optimal 한 것을 덧붙여야 한다. (Cut-and-Paste)
- Overlapping Subproblems
  - Recursive한 알고리즘이 같은 문제를 반복해서 해결해야 할 때 Overlapping Subproblems 이다.
  - lookup table에 Subproblem의 결과를 저장한 후 필요 할 때 꺼내 사용한다.
  - Memoization으로 해결한 Subproblem을 저장한다.

<br>

### Explained Example

- LIS