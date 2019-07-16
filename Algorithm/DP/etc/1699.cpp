#include <iostream>
#include <cmath>

int DP[100001];

int min(int a, int b){
    if(a>b) return b;
    else return a;
}

int main(){

    int N;
    scanf("%d", &N);
    for(int i=1;i<=N;i++) DP[i] = i;
    
    // for(int i=0;i<=N;i++) printf("%d ", DP[i]);
    // printf("\n");

    for(int i=2;i<=(int)sqrt(N); i++){
        for(int j=i*i;j<=N;j++){
            DP[j] = min(DP[j], DP[j-i*i] + 1);
        }
    }

    // for(int i=0;i<=N;i++) printf("%d ", DP[i]);
    //     printf("\n");

    printf("%d", DP[N]);
}