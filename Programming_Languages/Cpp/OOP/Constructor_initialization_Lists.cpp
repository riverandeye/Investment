#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    Player(string new_name, int heal_val, int xp_val) : name{new_name}, health{heal_val}, xp {xp_val} {
        cout << "Constructor_initialized" << endl;
    } // 이런식으로 초기값을 주는것이 할당하는 것 보다 효율적이다.

    Player() : Player {"None", 0, 0}{} // delegating constructor 예시

    Player(string new_name) : Player {new_name, 0, 0} {} // 

    void get_info()
    {
        cout << name << " : " << health;
    }
};

int main()
{
    Player david;
    david.get_info();
}