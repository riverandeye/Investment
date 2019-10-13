#include <iostream>

using namespace std;

void print_array(int arr[], size_t size)
{
    for (size_t i {0}; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// array는 포인터가 전달되기 때문에 값이 변한다.
void set_array(int arr[], size_t size, int value)
{
    for (size_t i {0}; i < size ; i++)
        arr[i] = value;
}

int main()
{
    int my_score[] {100, 90, 80 ,70, 60};
    print_array(my_score, 5);
    set_array(my_score, 5, 100);
    print_array(my_score, 5);

    return 0;
}