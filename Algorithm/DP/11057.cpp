#include <iostream>

long long int DP[10];

int main(){
    int N;
    scanf("%d", &N);
    long long int ans{0};
    DP[0] = 1;

    for(int i=0;i<N;i++){
        for(int j=1;j<10;j++){
            DP[j] += DP[j-1];
            if(DP[j]>10007) DP[j] = DP[j] % 10007;
        }
    }
    for(int i=0;i<10;i++)
        ans += DP[i];

    printf("%lld", ans % 10007);
}