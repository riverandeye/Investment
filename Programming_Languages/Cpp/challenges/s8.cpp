#include <iostream>
using namespace std;

int main()
{
    int dollar, quarter, dime, nickel, penny, money;
    cout <<"Enter an amount in cents : ";
    cin >> money;
    cout << "\nYou can provide this change as follows\n";

    dollar = money / 100;
    money -= dollar * 100;
    quarter = money / 25;
    money -= quarter * 25;
    dime = money / 10;
    money -= dime * 10;
    nickel = money / 5;
    money -= nickel * 5;
    penny = money;

    cout << "dollars\t: " << dollar << endl;
    cout << "quarter\t: " << quarter << endl;
    cout << "dime\t: " << dime << endl;
    cout << "nickel\t: " << nickel << endl;
    cout << "pennies\t: " << penny << endl;
    
    return 0;

}