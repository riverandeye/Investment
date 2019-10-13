#include <iostream>

using namespace std;

void double_data(int *data)
{
    *data *= 2;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b ;
    *b = temp;
}

int *array_intializer(size_t size, int init_value=0)
{
    int *new_storage {nullptr};
    new_storage = new int[init_value];
    for (size_t i{0} ; i < size; i++)
        *(new_storage + i) = init_value;
    return new_storage;
}
int main()
{
    int value {10};
    int *int_ptr {nullptr};
    
    // 주소를 받음
    int_ptr = &value;
    double_data(int_ptr);

    cout << value << endl;
    
    // 주소를 전달 
    int a{1}, b{200};
    swap(&a, &b);
    cout << a << " " << b ;

    int *initialized_arrray {nullptr};
    initialized_arrray = array_intializer(100,20);
    delete [] initialized_arrray;

    return 0;
}

