#include <iostream>

class Base{
public:
    int a{0};
    void display(){std::cout<<a<<","<<b<<","<<c;}
    Base(){std::cout<<"Base constructor" << std::endl;}
    Base(int i){a=i; std::cout<< "Base constructor with input" << std::endl;};
protected:
    int b{1};
private:
    int c{2};
};

class Derived: public Base{
    using Base::Base; // 이렇게 하면, Base constructor 를 Derived에서도 사용할 수 있다.
    // 그러나 같은 형식으로 정의된 Derived constructor가 있다면 애는 무시된다.
    // 그렇기 때문에 Base class constructor에 변수를 전달하여 Derived class constructor에 구현해야.
public:
    void access_Base_member()
    {
        a=100;
        b=200;
        //c=300; // 애는 당연히 안되겠지
    }
    Derived():Base{}{std::cout <<"Derived constructor"<<std::endl;}
    Derived(int j):Base{j}{b=j;std::cout<<"Derived constructor with input" << std::endl;}
};

int main()
{
    Derived derived{10};
    std::cout << derived.a;
    return 0;
}