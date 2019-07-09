#include <iostream>

int DP[35];
int MIX[35];

int main(){
    int N;
    scanf("%d", &N);
    DP[0] = 1;
    DP[2] = 3;

    for(int i=4;i<=N;i++){
        DP[i] += DP[i-2] * 3;
        for(int j = 4; i - j >= 0; j+=2){
            DP[i] += DP[i-j] * 2; 
        }
    }
    printf("%d", DP[N]);
}
