#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;
vector<int> DP;
vector<int> res;

ostream &operator<<(ostream &os, const vector<int> rhs){
    os << "now : ";
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
        res.push_back(distance(DP.begin(),pos+1));
    }
    printf("%d\n", DP.size());   
    backtrace(N-1, DP.size());
    return 0;
}