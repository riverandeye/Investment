#include <iostream>
using namespace std;
int main()
{
    // used for input validation

    int number {};

    cout << "Enter an integer less than 100 : " ;
    cin >> number;

    while (number >= 100)
    {
        cout << "Enter an integer less than 100 : ";
        cin >> number;
    }
    cout << "Thanks" << endl;
    
    // 이렇게 하면, 같은 코드를 한번 더 써야하니까 이렇게 하는게 좋음.

    bool done {false};
    int numb2 {};
    while (!done) {
        cout << "Enter an integer between 1 and 5: ";
        cin >> numb2;
        if (numb2 >= 1 && numb2 <= 5)
            {
                cout << "Thanks" << endl;  
                done = true;
            }
        else
            cout << "Out of range ! between 1 and 5 please : ";
    }

    // 근데 1번은 해야되는거면 이렇게 하지말고 do while 을 쓰면 clear하다.

    do{
        cout << "Enter an integer between 1 and 5: ";
        cin >> numb2;
    } while(numb2 >= 1 && numb2 <= 5);

    return 0;
}