#include <iostream>

int main()
{
    // initialization 없이 정의
    int test_score [5];

    // const로 size 정의
    const int days_in_year {365};
    double hi_temperatures [days_in_year];

    // initialization과 함께 정의
    int test_result [5] {100,96,95,94,93};

    // 모든 element를 다 initialize 할 필요는 없다.
    int high_score_per_level [10] {3,5};

    // 모두 0으로 initialize 하는건 그냥 {0} 해주면 된다.
    double zeroinit [10] {0};

    // initialize 한 만큼 자동으로 크기를 정해준다.
    int autoinit [] {1,2,3,4,5};

    return 0;

    // 2차원 배열도 그냥 해주면 되는데, initialize 에 주목할 것.

    int movie_rating [3][4] // 앞에께 세로 (row) , 뒤에께 가로 (column) 이다.
    {
        {0,4,3,5},
        {1,2,6,2},
        {3,1,7,5}
    };

    
}