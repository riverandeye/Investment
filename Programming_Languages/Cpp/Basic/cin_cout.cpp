#include <iostream>

using namespace std;

int main()
{
    int num1, num2, num3;
    double num6;

    cout << "Enter an integer : ";
    cin >> num1;
    cout << "You entered " << num1 << endl;
    // num1 에 int를 넣을 때, whitespace는 자동으로 제거되고 값만 넣는다.
    
    cout << "Enter an two integer : ";
    cin >> num2;
    cin >> num3;
    // 2개를 연속해서 넣을 때, 그냥 띄어쓰기로 구분해서 넣어줘도 된다.
    cout << "You entered " << num2 << " and " << num3 << endl;

    cout << "Enter an two integer : ";
    cin >> num1 >> num2 >> num3;    
    cout << "You entered" << num1 << " " << num2 << " " << num3 << endl;
    // 위와 같이 연속적으로 >> 를 써도 역시 spacebar로 구분하면 된다. enter도 가능.

    cout << "Enter integer and Double ";
    cin >> num1 >> num6;
    cout << "You entered int " << num1 << " and double " << num6 << endl;
    // 여기에 10.5 를 넣으면, 10 이랑 0.5로 나뉠것이다.
    // 10 까지 int니까 int 먹고, 나머지 0.5가 가겠지. input 할때 logic error 조심.
    // Frank 같은 이상한 글을 넣으면, input failed. 안에 들어가는 값은 믿으면 안됨.
    // 근데 문제는 에러가 안난다. 그 부분을 주의하자.
    
    return 0;
} 