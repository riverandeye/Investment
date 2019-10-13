#include <iostream>
using namespace std;

int main()
{
    // char - 단일 문자형
    // char a {'j'};
    // cout << a ;

    // unsigned short int - 자연수 with 0
    // unsigned short int score {100};
    // cout << score;

    // 숫자가 클땐 long
    // long int allkorean {50000000};
    // cout << allkorean;

    // 숫자가 너무 클땐 ' 마크를 사용할 수 있다.
    // long int allchinese {1'200'000'000};
    // cout << allchinese;

    // short, long, long long은 int를 안 써줘도 무조건 정수로 된다. 

    // = 으로 initialize 해주면 overflow에 대해 compile시 에러를 발생 X
    // {} 으로 initialize 해주면 overflow 시 컴파일 단계에서 에러를 리턴한다
    // 그렇지만, {a*b} 이런식으로 해서, a랑 b 각각은 안넘지만 곱한 결과가 넘으면 그건 못봐줌.
    // 그냥 warning만 뜬다.

    // float car {400.123};
    // cout << car ;
    // return 0;

    // boolean , 출력하면 0이나 1을 출력한다.
    // bool something {false};
    // cout << something; 

    // size of variable - from c language

    int i {10};
    cout << sizeof(i);


    return 0;
}