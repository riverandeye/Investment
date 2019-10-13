// Section 16
// Using override
#include <iostream>

// Override Specifier는 편의를 위해 제공된 함수이다.
// 상위 클래스에 있는 virtual 함수를 override 할 것인지 아닌지를 
// 코드에 명시해주는 기능! 

// 명시를 한 경우엔, Compile 시간에 Override를 제대로 했는지 확인을 해준다. (편안)

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
    virtual ~Base() {}
};

class Derived: public Base {
public: // 여기 밑에 const가 없으면, 수행 결과라 다르다고 예측하니까 Overriding을 하지 않겠죠.
    virtual void say_hello() const override {             // Notice I forgot the const 
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
    virtual ~Derived() {}
};


int main() {
    
    Base *p1 = new Base();      // Base::say_hello()
    p1->say_hello();
    
    Derived *p2 = new Derived();    // Derived::say_hello()
    p2->say_hello();
    
    Base *p3 = new Derived();   //  Base::say_hello()   ?????   I wanted Derived::say_hello()
    p3->say_hello();
   
    return 0;
}

