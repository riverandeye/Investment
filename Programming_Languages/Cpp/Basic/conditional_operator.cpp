#include <iostream>
using namespace std;

int main()
{
    int a{10}, b{20};
    int score{92};
    int result {};

    // 괄호 안에 조건, 
    result = (a>b) ? a:b; // a가 b보다 크면 a 아니면 b
    cout << result << endl;

    cout << "we can add this conditinal operator in stream like this " << ( (b>a) ? b : a ) << endl; 

    return 0;
}
 