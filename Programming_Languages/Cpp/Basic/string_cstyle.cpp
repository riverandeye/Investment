#include <iostream>
#include <cstring>
#include <cctype> // char data를 가공할 때 사용

using namespace std;

// C style string은, char array를 의미한다.

// 일반적인 C method들
// return bool -  isalpha, isalnum, isdigit, islower, isprint, ispunct, isupper, isspace
// return char - tolower, toupper
int main()
{
    // cstyle은 null charactor 를 문장의 끝으로 인식한다. 

    char my_name[] {"Kwan_Hun"};
    for (char i:my_name)
        cout << i;

    char first_name[20], last_name[20], full_name[50], temp[50];
    // initialize 하지 않았으므로 run 하면 garbage가 나오겠지.

    // // cin 으로 넣으면 문제가 생기지 않는다.
    // cout << "Enter your first_name : " ;
    // cin >> first_name;
    // cout << "Enter your last_name : " ;
    // cin >> last_name;

    // cout << "Hello, " << first_name << ". Your first name has " << strlen(first_name) << " characters." << endl;
    // cout << "And your last name " << last_name << " has " << strlen(last_name) << " characters" << endl; 
    
    // // null charactor 까지 copy 하기 때문에 걱정 하지 않아도 된다.
    // strcpy(full_name, first_name);
    // strcat(full_name, " ");
    // strcat(full_name, last_name);

    // cout << "Your full name is " << full_name << endl;

    // 띄어쓰기를 포함하여 한줄을 통채로 읽어들이고 싶을 때
    cout << "Enter your full name : ";
    cin.getline(full_name, 50); // 복사 해야하는 주소에 복사, 글자제한 작성
    cout << "Your full name is " << full_name << endl;

    // 항상 storage를 염두에 두어야 한다.

    cout << "---------------------" << endl;
    strcpy(temp, full_name);
    if (strcmp(temp, full_name) == 0)
        cout << temp << " and " << full_name << " are the same" << endl;     
    else
        cout << temp << " and " << full_name << " are different " << endl;
    cout << "---------------------" << endl;

    for (size_t i{0}; i < strlen(full_name); ++i)
    {
        if (isalpha(full_name[i]))
            full_name[i] = toupper(full_name[i]);
    }
    cout << "Your full name is " << full_name << endl;
    cout << "---------------------" << endl;
    if (strcmp(temp, full_name) == 0)
        cout << temp << " and " << full_name << " are the same." << endl;
    else
        cout << temp << " and " << full_name << " are differnet." << endl;
    cout << "---------------------" << endl;

    // strcmp 의 리턴방식 -> 앞에꺼가 뒤에꺼보다 언어순으로 먼저오면 1, 앞에께 뒤에꺼보다 늦게오면 -1
    // 지금 full_name이 대문자기 때문에 소문자보다 늦게 온다. 그래서 이런 결과가 나옴.
    cout << "Result of comparing " << temp << " and " << full_name << " : " << strcmp(temp, full_name) << endl; // 1
    cout << "Result of comparing " << full_name << " and " << temp << " : " << strcmp(full_name, temp) << endl; // -1
    cout << "---------------------" << endl;

    return 0;
}
