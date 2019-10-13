#include <iostream>
using namespace std;

int main()
{
    int a{1}, b{64};
    cout << (a<<3) << endl; // bitwise right shift // 
    cout << (b<<1) << endl; // bitwise left shift // 2배
    a <<= 5;
    cout << (a ^ b) << endl; // bitwise xor
    cout << (a | b) << endl; // bitwise or
    
    return 0; 
}

