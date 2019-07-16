#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long int> DP;

int main(){
    int N;
    long long int now;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%lld", &now);
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