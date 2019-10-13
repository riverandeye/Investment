#pragma once
#include <string>

using namespace std;
class Account{

    private:
    string name;
    double balance;

    public:
    Account()
    {
        name = "None";
        balance = 0.0;
    } // -> 이렇게 해놓으면, default construtor를 user가 설정해놓은거고
    // 이때는 default로 선언 해도 되겠지.

    Account(string new_name, double new_balance)
    {
        name = new_name;
        balance = new_balance;
    } // 만약 constructor를 이거만 선언해놓으면 
    // default construct하면 에러가 뜨겠지.
    // 그래서 위에 default constructor를 하나 만들어준다.
    
    void set_balence(double the_balance)
    {
        balance = the_balance;
    }

    double get_balance()
    {
        return balance;
    }

    bool withdraw(double amount);
    bool deposit(double amount);
    // We will use default constructor in this case
};