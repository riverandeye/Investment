#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Max3(int a, int b, int c) {
   int ret = (a > b) ? a : b;
   return (ret > c) ? ret : c;
}

int* GenerateNumbers(int N)
{
    int *A = NULL, i; //integer type의 A의 주소 초기화 
    A = malloc(sizeof(int)*N); // heap 영역에 int의 byte수 (4) * N 만큼의 메모리를 할당한다.
    // Type Casting은 할당된 메모리의 형식이 int 임을 명시하기 위해 사용한다.  

    if( A == NULL ) return NULL; // malloc 함수가 메모리 할당에실패하면 null을 리턴하므로
                                // A가 NULL을 가리키면 프로그램을 종료한다.
    for( i=0 ; i<N ; i++ ) A[i] = rand()-RAND_MAX/2; //A[]의 원소들은 랜덤한수-랜덤수중가장큰수/2로 생성되어 배열에 할당. 
    return A; //A값 반환 후 종료 
}

int MaxSubsequenceSum_1(const int A[],int N)
{
   int ThisSum, MaxSum, i, j, k;
   
   MaxSum = 0;
   for(i=0 ; i<N ; i++ ) {
      for(j=i ; j<N ; j++ ) {
         ThisSum = 0;
         for(k=i ; k<=j ; k++ ) ThisSum += A[k];
         if(ThisSum > MaxSum) MaxSum = ThisSum;
      }
   }
   return MaxSum;

}


int MaxSubsequenceSum_2(const int A[],int N)
{
   int ThisSum, MaxSum, i, j;
   
   MaxSum = 0;
   for(i=0;i<N;i++) {
      ThisSum = 0;
      for(j=i;j<N;j++) {
         ThisSum += A[j];
         if(ThisSum > MaxSum) MaxSum = ThisSum;
      }
   }
   return MaxSum;
}

int MaxSubSum(const int A[], int Left, int Right)
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;
    
    if(Left == Right) {
        if( A[Left]>0 ) return A[Left];
        else return 0;
    }
    
    Center = (Left+Right)/2;
    MaxLeftSum = MaxSubSum(A, Left, Center);
    MaxRightSum = MaxSubSum(A, Center+1, Right);
    
    MaxLeftBorderSum = 0 ; LeftBorderSum = 0;
    for( i=Center ; i>=Left ; i-- ) {
        LeftBorderSum += A[i];
        if(LeftBorderSum > MaxLeftBorderSum) 
        MaxLeftBorderSum = LeftBorderSum;
        
    }
    
    MaxRightBorderSum = 0; RightBorderSum = 0;
    for(i=Center+1 ; i<=Right ; i++) {
        RightBorderSum += A[i];
        if(RightBorderSum > MaxRightBorderSum) 
            MaxRightBorderSum = RightBorderSum;
        
    }
    
    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum+MaxRightBorderSum);
}

int MaxSubsequenceSum_3(const int A[],int N)
{
   return MaxSubSum(A,0,N-1);
} 

int MaxSubsequenceSum_4(const int A[],int N)
{
   int ThisSum, MaxSum, i;
   
   ThisSum = MaxSum = 0;
   for(i=0;i<N;i++) {
      ThisSum += A[i];
      if(ThisSum > MaxSum) MaxSum = ThisSum;
      else if(ThisSum < 0) ThisSum = 0;
   }
   return MaxSum;
}

int MinSubsequenceSum(const int A[],int N)
{
   int ThisSum, Minsum, i;
   
   ThisSum = Minsum = 0;
   for(i=0;i<N;i++) {
      ThisSum += A[i];
      if(ThisSum < Minsum) Minsum = ThisSum;
      else if(ThisSum > 0) ThisSum = 0;
   }
   return Minsum;
}

int main(int argc, char *argv[]) 
{
    int *A = NULL, N, MaxSum1, MaxSum2, MaxSum3, MaxSum4, Seed; 
    clock_t t11, t12, t21, t22, t31, t32, t41, t42, tm1, tm2;
    double elapse1, elapse2, elapse3, elapse4, elapsem; 

    Seed = 0;
    srand(Seed);

    N = 100;
    A = GenerateNumbers(N);
    if( A == NULL ) {
        printf("fail to generate %d numbers\n",N);
        exit(-1);
    }

    t11 = clock();  
    MaxSum1 = MaxSubsequenceSum_1(A,N);
    t12 = clock();
    elapse1 = (double)(t12-t11)/CLOCKS_PER_SEC;

    t21 = clock();
    MaxSum2 = MaxSubsequenceSum_2(A,N);
    t22 = clock();
    elapse2 = (double)(t22 - t21)/CLOCKS_PER_SEC;

    t31 = clock();
    MaxSum3 = MaxSubsequenceSum_3(A,N);
    t32 = clock();
    elapse3 = (double)(t32 - t31)/CLOCKS_PER_SEC;

    t41 = clock();
    MaxSum4 = MaxSubsequenceSum_4(A,N);
    t42 = clock();
    elapse4 = (double)(t42 - t41)/CLOCKS_PER_SEC;
 
    printf("Algorithm 1 : The MaxSum is %d (%.4f sec)\n",MaxSum1,elapse1);
    printf("Algorithm 2 : The MaxSum is %d (%.4f sec)\n",MaxSum2,elapse2);
    printf("Algorithm 3 : The MaxSum is %d (%.4f sec)\n",MaxSum3,elapse3);
    printf("Algorithm 4 : The MaxSum is %d (%.4f sec)\n",MaxSum4,elapse4);
    free(A);

    int *B = GenerateNumbers(N);
    tm1 = clock();
    int MinSum = MinSubsequenceSum(B, N);
    tm2 = clock();
    elapsem = (double)(tm2 - tm1)/CLOCKS_PER_SEC;

    printf("The MinSum is %d (%.4f sec)\n", MinSum, elapsem);
    return 0;   
}
