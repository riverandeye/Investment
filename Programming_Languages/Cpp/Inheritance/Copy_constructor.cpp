#include <iostream>

// Copy consturctor는 자동으로 만들어짐. 

class Base
{
    int value;
public:
    Base():value{0}{std::cout << "Default no-arg constructor of Base operated" << std::endl;}
    Base(int x):value{x}{std::cout<<"int constructor of Base operated"<<std::endl;}
    Base &operator=(const Base &rhs)
    {
        std::cout<< "Assignment operator of Base operated" << std::endl;
        if (this == &rhs)
            return *this;
        value = rhs.value;
        return *this;
    }
    Base(const Base &other):value{other.value}
    {std::cout << "Copy constructor of Base operated"<<std::endl;}
    ~Base(){std::cout<<"Base destructor operated" << std::endl;}
};

class Derived : public Base
{
    int derived_value;
public:
    Derived():derived_value{0}{std::cout<<"Default no-arg constructor of Derived operated"<<std::endl;}
    Derived(int x):Base(x), derived_value{x}{std::cout << "int constructor of Derived operated"<<std::endl;}
    Derived &operator=(const Derived &rhs)
    {
        std::cout << "Assignment operator of Derived operated" << std::endl;
        if (this == &rhs)
            return *this;
        Base::operator=(rhs);
        derived_value = rhs.derived_value;
        return *this;
    }
    Derived(const Derived &other):Base(other), derived_value{other.derived_value}
    {
        std::cout<<"Copy constructor of Derived operated"<<std::endl;
    }
    ~Derived(){std::cout<<"Derived desturctor operated" << std::endl;}
};

int main()
{
    Base a;
    Base b{10};
    Base c{a};
    b = c;
    std::cout << std::endl;

    Derived e;
    Derived f{10};
    Derived g{e};
    f = g;

    return 0;
}