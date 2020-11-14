#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001];

int solution(vector<int> sticker)
{
    int answer;
    if(sticker.size() == 1) return sticker[0];
    if(sticker.size() == 2) return max(sticker[0], sticker[1]);
    
    int max_case = 0;
    
    // 맨 앞에꺼 함
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    
    for(int i = 2 ; i < sticker.size() - 1; i++){ // 맨 뒤는 고려하지 않음
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    }
    
    for(int i = 0 ; i < sticker.size(); i++){
        if(max_case < dp[i]) max_case = dp[i];
        cout << dp[i] << ' ';
        dp[i] = 0;
    }
    
    // 맨 앞에꺼 안함
    dp[0] = 0;
    dp[1] = sticker[1];
    
    for(int i = 3 ; i < sticker.size(); i++){// 2번째꺼 고려 안하고, 맨 뒤에꺼 고려함
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    }
    
    for(int i = 0 ; i < sticker.size(); i++){
        if(max_case < dp[i]) max_case = dp[i];
        cout << dp[i] << ' ';
    }
    
    answer = max_case;
    return answer;
}

int main(){
    vector<int> a;

    a.push_back(14);
    a.push_back(6);
    a.push_back(5);
    a.push_back(11);
    a.push_back(3);
    a.push_back(9);
    a.push_back(2);
    a.push_back(10);

    cout << solution(a);
}