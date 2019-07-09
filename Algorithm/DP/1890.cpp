#include <iostream>

int MAP[102][102];
long long int DP[102][102];

int main(){
    int N;
    scanf("%d", &N);

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d", &MAP[i][j]);
        }
    }

    int pos;

    // initialize
    DP[1][1] = 1; 

    // DP
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(DP[i][j] == 0 || MAP[i][j] == 0) continue;
            if(i + MAP[i][j] <= N) DP[i+MAP[i][j]][j] += DP[i][j];
            if(j + MAP[i][j] <= N) DP[i][j+MAP[i][j]] += DP[i][j];
        }
    }
    printf("%lld", DP[N][N]);
}