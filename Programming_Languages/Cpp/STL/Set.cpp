#include <iostream>
#include <set>

using namespace std;
int main(){
    set<int> s{1,2,3,4,5};
    
    s.insert(7);
    // set element remove
    auto it = s.find(5);
    if(it != s.end())
        s.erase(it);
    

    // remove all element
    s.clear();

    // check whether it is empty
    cout << s.empty() << endl;

}