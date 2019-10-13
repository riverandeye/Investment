#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 함수 오버로딩 -> 서로 다른 input 형태에 대해 다른 기능을 부여하기 위한 방식.
// Template 기능은 generic 한 것에 대해 지원을 해줌.

void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector <string>);

void print(int num)
{
    cout << "Printing int " << num << endl; 
}

void print(double num)
{
    cout << "Printing double " << num << endl; 
}

void print(string s)
{
    cout << "Printing string " << s << endl; 
}

void print(string s, string t)
{
    cout << "Printing 2 string " << s << " and " << t << endl; 
}

void print(vector <string> v)
{
    cout << "Printing vector of strings : "; 
    for (auto s:v)
        cout << s;
    cout << endl; 
}

int main()
{
    print(100);
    print('A');
    print(123.5);
    print(123.3F);
    print("C style string");
    
    string s {"Cpp style string!"};

    print(s);
    print(s,s);
    vector <string> damns {"is", "life", "hard?"};

    print(damns);
    return 0;
}