#include <iostream>
#include <memory>
// 아래의 경우는 Static Binding 한 예시를 보이고 있다.

class Base{
public :
    void say_hello() const{
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived: public Base{
public :
    void say_hello() const {
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

void greetings(const Base &obj)
{
    std::cout << "Greetings: ";
    obj.say_hello();
}

int main()
{
    Base b;
    b.say_hello();

    Derived d;
    d.say_hello();

    greetings(b);
    greetings(d); // 문제는 여기에 있음. 우린 Derived가 되길 원했는데, Base가 작동함.

    Base *bptr = new Derived(); // Derived는 Base니까, 말이 되지. 왜냐면 Base를 Derive 했으니까.
    bptr->say_hello(); // 어떻게 될까? 당연히 Base로 가겠지.

    Derived *dptr = new Derived();
    dptr->say_hello(); // 이게 우리가 원한거임.

    std::unique_ptr <Base> ptr1 = std::make_unique<Derived>();
    ptr1->say_hello(); // smart pointer도 static bind 함.

    return 0;
}

// Polymorphism - compile time / Run time

// Compile time은 function과 operator overloading
// Runtime에선 Function Overriding 하는거임. ** 중요. 이건 dynamic 한거임.

