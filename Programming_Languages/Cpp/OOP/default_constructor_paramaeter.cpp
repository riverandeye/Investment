#include <iostream>

using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;
public:

    Player(string name_val = "None", int health_val = 0, int xp_val = 0);
    // 이 부분이 Constructor parameter에 default 값을 넣어준 것임.
};

Player::Player(string name_val, int health_val, int xp_val)
: name{name_val}, health {health_val}, xp{xp_val}
{
    cout << "Three args constructor" << endl;
} // default를 넣어줫기 때문에 delegating을 쓸 필요가 없다.

int main()
{
    Player empty;
    Player frank {"Frank"}; // frank() 로 소환하는거랑 다른거임.
    // frank() 는 frank()라는 constructor를 소환하는거임.
    // frank 는 default constructor를 소환하면서, parameter에 값을 넣어주는거임.
    // 근데 여기선 default constructor를 소환할 때 3개의 변수가 이미 들어가있으므로
    // Player::Player(string name_val, int health_val, int xp_val) 이녀석이 실행되는거임.
}

