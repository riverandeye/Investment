#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_
#include "Account.h"

class Saving_Account: public Account
{
    friend std::ostream &operator<<(std::ostream &os, const Saving_Account &account);
protected:
    double int_rate;
public:
    Saving_Account();
    Saving_Account(double balance, double int_rate);
    ~Saving_Account();
    void deposit(double amount);
};

#endif