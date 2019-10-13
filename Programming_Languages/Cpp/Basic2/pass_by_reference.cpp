#include <iostream>
#include <vector>

using namespace std;

// 참조전달 -> 실제로 값을 바꿀 수 있게 전달하는 것
// 포인터와는 다르다. 포인터는 주소를 전달하는거고, 참조전달은 그냥 바꿀수있게 하는거고.

void scale_number (int &num);

int main()
{
    int number {1000};
    scale_number(number); // changed
    cout << number << endl;
    
    vector<string> stooges {"Larry", "Moe", "Curly"};
    for (auto &a:stooges) // 이 부분에서 a가 reference로 값을 바꿔줄수 있다.
        a = "Mofo";

    for (auto a:stooges)
        cout << a << endl;
        
    return 0;
}

void scale_number(int &number)
{
    if (number > 100)
        number = 100;
}

// vector를 함수에 전달할 때 pass by reference를 이용해야한다.
// 