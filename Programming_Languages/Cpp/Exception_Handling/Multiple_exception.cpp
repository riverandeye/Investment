#include <iostream>

using namespace std;

double calculate(int miles, int gallons)
{
    if (gallons == 0)
        throw std::string{"Gallons should not be zero"};
    if (miles < 0 || gallons < 0)
        throw std::string{"Negative value error"};
}

int main()
{  
    int miles, gallons;
    cout << "Give miles : ";
    cin >> miles;
    cout << "Give gallons :";
    cin >> gallons;
    try {

    }

}