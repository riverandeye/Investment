#include <iostream>
#include <string>
#include <vector>

// Template class는 꼭 헤더파일에 선언하자.

template <typename T>
class item{
private:
    std::string name;
    T value;
public:
    item(std::string name, T value):name{name}, value{value}{}
    std::string get_name() const{return name;}
    T get_value() const {return value;}
};

int main(){

    item<int> item1{"KwanHun", 100};
    std::cout << item1.get_name() << " got " << item1.get_value() << " score! " << std::endl;

    item<std::string> item2{"exam", "sucks"};
    std::cout << item2.get_name() << item2.get_value() <<"!"<< std::endl;

    item<item<int>> item3{"Kwanhun", {"awesomeness", 100}};
    std::cout << item3.get_name() << "'s " << item3.get_value().get_name() << " is " << item3.get_value().get_value() << std::endl;
    return 0;
}
