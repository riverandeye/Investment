#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int scores [] {100, 90, 97};

    // type 이 같지 않아도 불러와지긴 한다. 물론 type간의 관계가 중요하겠지.
    for (char score : scores)
        cout << score << endl;
    
    char words [] {'a', 'b', 'c'};

    // array 나 vector 내의 type을 굳이 설정하지 않으면 기본값으로 된다.
    for (auto word : words)
        cout << word << endl;

    vector <double> temps {87.2, 77.1, 80.0, 72.5};
    double average_temp {};
    double running_sum {};

    for (auto temp: temps)
        running_sum += temp;

    average_temp = running_sum / temps.size();
    
    // string 도 iteration 이 가능하다.
    for (auto c: "Jin-Seong-ho")
        cout << c ;
    
    return 0;
}