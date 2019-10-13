#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 내용물의 type을 <> 안에 저장, empty vector 를 생성한다.
    vector <char> vowels;

    // 크기를 처음에 지정해줄 수도 있다. 지정해주면, int는 항상 모두 0으로 initialize 된다.
    vector <int> test_scores (10);

    // 0이 아닌 임의로 initialize 해줄 수 있다.
    vector <int> prices {300,200,100};

    // 크기를 지정해주고, 해당하는 크기 만큼 한꺼번에 initialize 할 수 있다.
    vector <double> hi_temperatures (365, 80.0); // 365개, 80.0 대입

    // individual vector access는 c언어랑 똑같음.
    cout << "first price is " << prices[0] << endl;

    // index 에 해당하는 값을 리턴하는 method : .at(index)

    cout << "second price is " << prices.at(1) << endl;

    // 새 값을 뒤로 붙여주는건 .push_back(value) , type은 꼭 같아야 한다. 메모리 자동 allocate

    prices.push_back(50);

    // vector는 bounds checking을 함 (array 보다 안전함)
    // vector의 size를 리턴하는 메소드 .size()

    cout << "current size of vector prices is " << prices.size() << endl;
    
    // 2d vector과 at 메소드 사용법

    vector <vector<int>> twod // vector 안에 vector를 담으므로 이렇게!!
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    cout << "access 2d vector " << twod.at(1).at(1) << endl;
    return 0;
}