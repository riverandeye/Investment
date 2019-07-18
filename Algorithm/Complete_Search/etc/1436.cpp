#include <iostream>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    int nth=0;
    int num=665;
    while(nth < N){
        num++;
        string s = to_string(num);
        int n_six = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '6') n_six++;
            else n_six = 0;
            if(n_six == 3) break;
        }
        if(n_six == 3) nth++;
    }
    printf("%d", num);
}