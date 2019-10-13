#include <iostream>

using namespace std;
int main()
{
    // nullptr 로 초기화
    int *i {nullptr};
    char *j {nullptr};
    
    int hello {100};
    // 포인터는 주소를 저장한다.
    i = &hello;

    // dereferencing 하기 
    cout << *i << endl;

    // dynamic allocation - heap 영역에 저장
    // integer를 heap에 allocate    
    int *int_ptr {nullptr};
    int_ptr = new int;

    *int_ptr = 100;
    
    //deallocate 
    delete int_ptr;

    // int array를 allocate 하고 deallocate 하기.
    int *array_ptr {nullptr};
    size_t size {10};

    array_ptr = new int[size];

    delete [] array_ptr;

    // array와 pointer의 관계를 생각해보자.
    // array name 이랑 pointer는 결국 주소값을 저장하는거임. 
    // array name은 물론 주소값을 바꿀순 없다.

    int scores[] {100,90,80};
    int *score_ptr {scores};

    cout << score_ptr << scores << endl;
    cout << *score_ptr << *scores << endl;
    cout << *(score_ptr+1) << scores[1] << endl;   
}