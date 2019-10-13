#include <iostream>

using namespace std;
int main()
{
    // input 은 int 2개, 같은지 다른지 비교 : 너무 obvious 해서 pass    
    // input 이 char 2개인 경우도 비교하는 메모는 안하겠음.
    // double 2개끼리 비교할때가 좀 special 하다.

    double d1, d2;
    cout << "Put two double for comparison : ";
    cin >> d1 >> d2;
    cout << "is it same? : "<< (d1 == d2) << endl; 
    cout << "is it different? : "<< (d1 != d2) << endl; 

    // 이거 12.1111111111111111 이랑 12.111111111111111111112 이거랑 같게나옴.
    // 컴퓨터가 floating point를 approximation하기 때문에 같게 나옴.
    // built in double을 쓰는건 완전 정확하진 않을거임.
    

    // int 랑 double이랑 비교할때.
    int num1;
    double d3;
    cout << "Put one integer and one double for comparison respectively : ";
    cin >> num1, d3;
    cout << "is it same? : "<< (num1 == d3) << endl; 
    cout << "is it different? : "<< (num1 != d3) << endl; 
    // type 이 달라도 floating point represent 상 같으면 같다.

    return 0;
}