#include <iostream>

int data[301][301];
int Nsum[301][301];

int main(){
    int N,M;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &data[i][j]);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    
    // N의 각 열마다 합 저장
    for(int i=0;i<N;i++){
        Nsum[i+1][1] = data[i][0];
        for(int j=1;j<M;j++){
            Nsum[i+1][j+1] = Nsum[i+1][j] + data[i][j];
        }
    }

    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            printf("%d ", Nsum[i][j]);
        }
        printf("\n");
    }

    int K;
    scanf("%d", &K);

    int i,j,x,y;
    for(int tcase = 0; tcase < K; tcase++){
        scanf("%d %d %d %d", &i, &j, &x, &y);
        int ans{0};
        for(int k=i;k<=x;k++){
            ans += (Nsum[k][y] - Nsum[k][j-1]);
        }
        printf("%d\n", ans);
    }

    return 0;
}