#include <iostream>
#include <algorithm>

int MAP[1000][1000];

int MAX(int a, int b){
    return (a > b) ? a : b;
}

int main(){
    int N,M;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &MAP[i][j]);
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         printf("%d ", MAP[i][j]);
    //     }
    //     printf("\n");
    // }

    // initialize
    for(int i=1;i<N;i++){
        MAP[i][0] += MAP[i-1][0];
    }

    for(int i=1;i<M;i++){
        MAP[0][i] += MAP[0][i-1];
    }

    
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         printf("%d ", MAP[i][j]);
    //     }
    //     printf("\n");
    // }

    // DP
    for(int i=1;i<N;i++){
        for(int j=1;j<M;j++){
            MAP[i][j] += MAX(MAX(MAP[i-1][j], MAP[i][j-1]), MAP[i-1][j-1]);
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         printf("%d ", MAP[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d", MAP[N-1][M-1]);
    return 0;
}