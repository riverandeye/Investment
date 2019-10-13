#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

const double pi {3.14159};

double calc_area_circle(double radius)
{
    return pi * radius * radius;
};

// default argument setting : 변수명에! 꼭 헤더에다가 해줘야된다.

double calc_cost(double base_cost, double tax_rate = 0.06, double shipping = 3.50); // 미리 선언할때 이렇게 해놓으면 된다.

// 선언을 먼저 하지 않았다면, 그냥 함수 헤더에 놓으면 된다.
// 위에서 변수 미리 지정해줬으면 밑에선 하면 안된다.
double calc_cost(double base_cost, double tax_rate, double shipping)
{
    return base_cost += (base_cost * tax_rate) + shipping;
};
int main()
{
    srand(time(nullptr)); // seeding the null pointer
    
    // // 주사위
    // size_t count {10};
    // int random_number {}, max{6}, min{1};
    // for (size_t i{1}; i <= count; ++i)
    // {
    //     random_number = rand() % max + min;
    //     cout << random_number << endl;
    // }

    double radius {7.2};
    cout << calc_area_circle(radius) << endl;

    cout << calc_cost(100, 0.08, 4.25) << endl;
    cout << calc_cost(100, 0.08) << endl;
    cout << calc_cost(100) << endl;
    return 0;
}

