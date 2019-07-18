#include <iostream>
#include <vector>

using namespace std;

void combination(int n, int r, vector<int> &v){
    if(r==0){
        for(auto i:v)
            cout << i << " ";
        cout << endl;
        return;
    }

    int next = v.empty() ? 0 : v.back() + 1;
    for(int i=next;i<n;i++){
        v.push_back(i);
        combination(n, r-1, v);
        v.pop_back();
    }
}

void Rcombination(int n, int r, vector<int> &v){
    if(r==0){
        for(auto i:v)
            cout << i << " ";
        cout << endl;
        return;
    }

    int next = v.empty() ? 0 : v.back();
    for(int i=next;i<n;i++){
        v.push_back(i);
        combination(n, r-1, v);
        v.pop_back();
    }
}

int main(){
    vector<int> emptyvec{};
    // combination(10, 5, emptyvec);
    Rcombination(10,5,emptyvec);
    return 0;
}