#include <iostream>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;
bool is_palindrome(const string &s){

    deque<char> deq;
    for(char i:s){
        if ( !( (i >= 97 & i <= 122) || (i >= 65 && i <= 90) ) ) continue;
        deq.emplace_back(toupper(i));
    }

    while(deq.size() > 1){
        if(deq.front() != deq.back()) break;
        deq.pop_back();
        deq.pop_front();
    }

    if(deq.size() == 1 || deq.size() == 0) return true;
    else return false;
}

int main(){

    string a;
    cin >> a;
    cout << (is_palindrome(a) ? "True" : "False") << endl;
    return 0;
}