#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s0;
    string s1 {"Apple"};
    string s2 {"Banana"};
    string s3 {"Kiwi"};
    string s4 {"apple"};
    string s5 {s1}; // Apple
    string s6 {s1,0,3}; // App
    string s7 {10, 'X'}; // XXXXXXXXXX

    // cout << s0 << endl; // garbage 없음
    // cout << s0.length() << endl;

    // comparison
    cout << boolalpha; // i/o manipulator -> boolean 결과를 true, false로 출력하게 해준다.
    cout << "s1 >= s2 : " << (s1 > s2) << endl; 
    cout << "s2 >= s3 : " << (s2 > s3) << endl; // 결과는 ascii table을 참고하자.

    // concat은 + 로 하면 되고
    // index 접근은 하면 되고..
    // range based for loop 도 지원한다.
    
    // substring
    s1 = "This is test";
    cout << s1.substr(0,7) << endl; // this is

    //erasing
    s1.erase(0,7);
    cout << s1 << endl;

    //getline

    string full_name {};
    cout << "Enter your full name : ";
    getline(cin, full_name);
    cout << "Your full name is " << full_name << endl;

    // find 는 그냥 쓰면 됨.. 어렵지 않다.    
}