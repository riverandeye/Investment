#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &v1){
    for(auto it =v1.cbegin(); it != v1.cend(); it++){os<<*it<<" ";}
    os << endl;
    return os;
}

int main(){

    vector<int> hello {1,2,3,4,5,6,7,8,9,10};

    for(auto it=hello.begin(); it != hello.end(); it++){
        cout << *it << " " << endl;
    }

    for(auto it=hello.rbegin(); it != hello.rend();it++){
        cout << *it << " " << endl;
    }

    for(auto it=hello.cbegin(); it != hello.cend(); it++){
        cout << *it << " " << endl;
    }

    for(auto it=hello.crbegin(); it != hello.crend(); it++){
        cout << *it << " " << endl;
    }

    /* for each를 사용해서 값을 바꿔줄순없나. 그냥 iterator를 써야할듯 하다.*/ 
    for_each(hello.begin(), hello.end(), [](int x){x=x*x;}); 
    
    cout << hello;
}
