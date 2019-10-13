// Section 16
// Virtual destructors

#include <iostream>

// This class uses dynamic polymorphism for the withdraw method
// Virtual 을 사용할 때 virtual Destructor를 선언하지 않으면 예상치 못한 일이 발생 할 수 있음.
// Virtual Function 이 있는 Class는 Virtual Destructor를 꼭 선언해주자!!

// 만약 Virtual이 없으면, 하위 클래스들 선언된건 Destruct 가 되지 않고
// 메모리에 둥둥 떠다닐 것이 분명하다. 왜냐면 Default가 없으니까.
// 그래서 Destructor를 선언해줘야 한다.

class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() { std::cout << "Account:: destructor" << std::endl; }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() { std::cout << "Checking:: destructor" << std::endl; }

};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() { std::cout << "Savings:: destructor" << std::endl; }

};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() { std::cout << "Trust:: destructor" << std::endl; }

};

int main() {

    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    

    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
        
    return 0;
}

