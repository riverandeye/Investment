#include <iostream>

int data[1002];
int DP[1002];

int MAX(int a, int b){
    if (a>b) return a;
    else return b;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i=1;i<=N;i++){
        scanf("%d", &data[i]);
    }

    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            DP[j] = MAX(DP[j], DP[j-i] + data[i]);
        }
    }
    
    printf("%d", DP[N]);
    return 0;
}
