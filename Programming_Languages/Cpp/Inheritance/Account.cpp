#include <iostream>
#include "Account.h"

Account::Account():balance{0.0}
{

}

Account::Account(double balance):balance{balance}
{

}

void Account::deposit(double amount)
{
    balance += amount;
}

void Account::withdraw(double amount)
{
    if (balance < amount)
        std::cout << "Insufficient fund sorry " << std::endl;
    else
        balance-=amount;
}

std::ostream &operator<<(std::ostream &os, const Account &account) {
    os <<  "Account balance: " << account.balance;
    return os;
}

Account::~Account(){}