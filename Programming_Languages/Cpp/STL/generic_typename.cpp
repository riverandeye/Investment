#include <iostream>
#include <string>
using namespace std;


template <typename T> 
T _min(T a, T b){
    return (a<b) ? a:b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b){
    cout << a << " " << b << endl;
}

struct Person{
    std::string name;
    int age;
    bool operator<(const Person rhs) const {return this->age < rhs.age;}
};

std::ostream &operator<<(std::ostream &os, const Person &p){
    os << p.name;
    return os;
}

template <typename T> void myswap(T &a, T &b){
    T temp=a;
    a=b;
    b=temp;
}

int main(){
    Person p1{"Curly", 50};
    Person p2{"Mo", 30};

    func(p1, p2);
    cout << _min<int>(2,3) << endl;
    cout << _min('h','d') << endl;
    cout << _min(3.5, 4.5) << endl;

    Person p3 = _min(p1,p2);
    cout << p3.name << " is younger"; ;
    
    return 0;
}