# LIS (Longest Increasing Subsequence)



### 문제 설명

- 주어진 수열에 대해 가장 긴 증가하는 부분 수열의 길이를 구하는 것이 목표
- ex ) **1** 13 6 **2** 53 **3** 42 **4** 13 **5** 64 **6** 18 **7** 5 **8** 3 **9** 에서 123456789가 LIS이므로 답은 9를 리턴



### O(N<sup>2</sup>) Algorithm

- input size가 N이면, DP[N]을 정의, DP[i]는 i번째 인덱스의 값을 포함한 LIS의 길이
- DP[i] = arr[i] > arr[j]인 모든 j에 대해서 DP[j]의 최대값 + 1 

<br>

[백준 11053 가장 긴 증가하는 부분 수열](https://www.acmicpc.net/problem/11053)

```c++
#include<iostream>
#include <algorithm>

int DATA[1001];
int LIS[1001];
int A,ans;

using namespace std;
int main(){
    cin >> A;
    for(int i = 0 ; i < A ; i++)
        cin >> DATA[i];

    for(int i = 0 ; i < A ; i++) {
        LIS[i]=1;
        for(int j = 0 ; j < i ; j++){
            if(DATA[i] > DATA[j])
                LIS[i] = max(LIS[i] , LIS[j] + 1);
        }
        ans = max(ans , LIS[i]);
    }
    cout << ans << endl;
    return 0;   
} 
```

이는 N <= 1000 이기 때문에 위 알고리즘으로도 풀 수 있다.<br>

### O(NlogN) Algorithm

- 위 O(N<sup>2</sup>) 알고리즘은 DP[i] = arr[i] > arr[j]인 모든 j에 대해서 DP[j]의 최대값 + 1 의 방식으로 DP[i] 를 결정하는데, 이 과정 자체가 O(N)의 시간복잡도를 가진다. i보다 작은 값에 대해서 모두 search 하기 때문이다.
- 이 과정을 이진 탐색으로 대체하여 O(logN)의 시간복잡도로 변경하는 것이 목표이다.

<br>

[백준 12015 가장 긴 증가하는 부분 수열 2](https://www.acmicpc.net/problem/12015)

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> DP;

int main(){
    int N, now;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &now);
        if(DP.size() == 0 || DP[DP.size()-1] < now){
            DP.push_back(now);
            continue;
        }
        auto pos = lower_bound(DP.begin(),DP.end(), now);
        *pos = now;
    }
    printf("%d", DP.size());
    return 0;
}
```

vector DP에는 인덱스 i에 대하여 i+1의 길이를 갖는 Increasing Subsequence 중 Sequence의 마지막 값이 가장 작은 Sequence의 마지막 값을 i번째에 넣는다. <br> 

### LIS 원소 구하기

DP에 저장되는 값이 LIS에 해당하는 값은 아니므로,  역추적을 통해 LIS의 원소를 찾을 수 있도록 원소를 array를 따로 저장하고, 해당 원소가 만드는 최장길이가 몇인지를 다른 vector에 저장합니다. 

역추적은, N개부터 시작하여 0개가 될때까지 하는 것을 목표로 재귀로 설정하며, idx를 하나씩 줄여나가면서 현재 갯수와 일치하는 (사실 재귀로 안하고 그냥 for loop으로 구현해도 됩니다)

**Backtrace를 추가한 백준 12015**

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;
vector<int> DP;
vector<int> res;

ostream &operator<<(ostream &os, const vector<int> rhs){
    for(auto i:rhs)
        os << i << " ";
    os << endl;
    return os;
}

void backtrace(int idx, int num) {
    if(idx == -1 || num == 0)
        return;
    if(res[idx] == num) {
        backtrace(idx - 1, num - 1);
        cout << arr[idx] << " ";
    }
    else {
        backtrace(idx - 1, num);
    }
}

int main(){
    int N, now;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &now);
        arr.push_back(now);
        if(DP.size() == 0 || DP[DP.size()-1] < now){
            DP.push_back(now);
            res.push_back(distance(DP.begin(),DP.end()));
            continue;
        }
        auto pos = lower_bound(DP.begin(),DP.end(), now);
        *pos = now;
        res.push_back(distance(DP.begin(),pos + 1));
    }
    backtrace(N, DP.size());
    printf("%d", DP.size());    
    return 0;
}
```

