#include <iostream>
#include <string>
#include <vector>

#include "Account.h"

int main()
{
    // method를 declaration 밖에서 정하는 방식.
    // scope resolution operator를 사용한다.
    Account frank_account;
    frank_account.set_balence(1000.00);    
    double bal = frank_account.get_balance();

    std::cout << bal << std::endl;
    return 0;
}