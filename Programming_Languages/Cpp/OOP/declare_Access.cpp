#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player{
    
    public:

    //attributes
    string name;
    int health;
    int xp;

    //methods
    void talk(string text_to_say)
    {
        cout << name << " says " << text_to_say << endl;;
    };
    bool is_dead();
};

class Account
{
    //attributes
    
    public:
    string name;
    double balance;

    bool withdraw(double amount);
    bool deposit(double amount);
};

int main()
{
    Player frank;
    cout << "shit";
    // 일반적인 attribute 접근 방식
    Account frank_account;

    // 클래스로 선언된 경우 접근방식
    // Account *frank_account2;
    // (*frank_account2).balance = 1000;
    // frank_account2->balance = 1000;

    frank.name = "Frank";
    frank.talk("Fuck you");

    Player *enemy = new Player;
    (*enemy).name = "Enemy";
    enemy->health = 100;
    enemy->xp = 15;

    enemy->talk("Bitch I will kill you");

    delete enemy;
    return 0;
}