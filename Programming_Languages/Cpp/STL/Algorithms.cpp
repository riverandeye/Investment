#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person{
    std::string name;
    int age;
public:
    Person()=default;
    Person(std::string name, int age):name(name),age(age){}
    bool operator < (const Person rhs)const{
        return (this->age < rhs.age);
    }
    bool operator==(const Person rhs)const{
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

void findtest(){

    std::vector<int> vec{2,1,3,4,5};

    auto loc = std::find(std::begin(vec), std::end(vec), 1);
    if(loc != std::end(vec))
        std::cout<<"Found the number : "<< *loc << std::endl;
    else
        std::cout<<"Couldn't find the value" << std::endl;
}

void counttest(){

    std::vector<int> vec{1,2,3,4,3,2,3,4,1,5,1,1,5,2,24,1,2,5,4,2};
    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << "the number of 1 is " << num << std::endl;    

}

void countiftest(){
    std::vector<int> vec{1,2,3,2,1,2,3,2,1,3,2,3,1};
    int num = std::count_if(vec.begin(), vec.end(),[](int x){return x % 2 == 0;});
    std::cout << num << "even number is total " << num << std::endl;
}

void replacetest(){
    std::vector<int> vec{1,2,3,4,5,4,5,4,3,4,2,3,1};
    std::replace(vec.begin(), vec.end(), 1, 100);
    for(auto i:vec)
        std::cout << i << " " ;
    std::cout << std::endl;
}

void alloftest(){
    std::vector<int> vec{1,2,3,4,5,4,5,4,3,4,2,3,1};
    if(std::all_of(vec.begin(),vec.end(), [](int x){return x > 0;}))
        std::cout<<"All of the vec is higher than 0" << std::endl;
    else
        std::cout<<"Not all the elements are higher than 0" << std::endl;
}

void string_transformation_test(){
    std::string data{"Hello world"};
    std::cout << "Before : " << data << std::endl;
    std::transform(data.begin(), data.end(), data.begin(), ::toupper);
    std::cout << "After : " << data << std::endl;
}

int main(){

    findtest();
    counttest();
    countiftest();
    replacetest();
    alloftest();
    string_transformation_test();

    return 0;
}