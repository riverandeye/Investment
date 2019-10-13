#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account
{
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
public:
    double balance;
    void deposit(double amount);
    void withdraw(double amount);
    Account();
    Account(double balance);
    ~Account();
};

#endif // _ACCOUNT_H_