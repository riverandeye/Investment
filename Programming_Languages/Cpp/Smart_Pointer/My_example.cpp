#include <iostream>
#include <memory>

using namespace std;

class Account
{
public:
    int money;
    virtual void check() const = 0;
    
};

class Checking_Account : public Account 
{
public : 
    int money;
    Checking_Account() : money{0}
    {
        cout << "Created Checking Account" << endl;
    }
};


int main()
{

    return 0;
}