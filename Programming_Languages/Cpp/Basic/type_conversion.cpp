#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    int a {12};
    double b {0.6};
    int c {4};
    a = a / c;
    cout << typeid(a).name() << endl; // int 로 유지된다.
    a = a * b; // double과의 연산 결과를 a에 할당
    cout << typeid(a).name() << endl; // int 로 유지된다.
    cout << a << endl;
    // 이미 선언한 datatype이 임의로 변경되는 경우는 없다.
    cout << typeid(2 * 0.4).name() <<endl;
    // 변수가 아닌 리터럴의 경우엔 타입이 자동으로 큰 쪽으로 변경된다.
    
    // 너가 만약 integer의 평균을 내어 double로 변경하고 싶으면,
    // type casting이 꼭 필요하다. static_cast <double> (parameter) 이런식으로.

    int num1 {50}, num2 {30}, num3 {20};
    double average;
    average = static_cast <double> (num1 + num2 + num3) / 3;

    cout << average << endl;
    return 0;

}