#include <iostream>
#include <vector>
#include <algorithm>

/* Vector의 특징 */
/* 1. Dynamic size */
/* 2. access - const time */
/* 3. insertion, deletion at the back - const time */ // back 이부분 중요함

class Person{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age):name(name), age(age){}
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p){
    os << p.name << ":" << p.age;
    return os;
}

void display2(const std::vector<int> &vec){
    std::cout<<"[ ";
    std::for_each(vec.begin(), vec.end(), [](int x){std::cout<<x<<" ";});
    std::cout<<"]";
}

template <typename T>
void display(const std::vector<T> &vec){
    std::cout<<"[ ";
    for(const auto &elem:vec)
        std::cout<<elem<<" ";
    std::cout<<"]";
}

void test1(){

    std::vector<int> vec{1,2,3,4,5};
    display(vec);

    vec = {2,4,5,6};
    display2(vec);
}

/* 이부분이 중요함. 
벡터는 사이즈가 추가될때마다 증가하는게 아니라, 허용량을 넘을때마다 증가함. */
void test2() {
    std::cout << "\nTest2 =========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;
    
    vec.push_back(6);
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;
    
    vec.shrink_to_fit();    // Capacity랑 size를 같게 만들어줌
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;
    
    vec.reserve(100); // Capacity를 set 해줌
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;
    
}

void test3() {
    std::cout << "\nTest3 =========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    
    vec[0] = 100;
    vec.at(1) = 200; // at이랑 index 접근은 같은것임.
    
    display(vec);
}

/* emplace back을 사용합시다 */
void test4() {
    std::cout << "\nTest4 =========================" << std::endl;
    std::vector<Person> stooges;
    
    Person p1 {"Larry", 18};
    display(stooges);
    
    stooges.push_back(p1);
    display(stooges);
    
    stooges.push_back(Person{"Moe", 25});
    display(stooges);
    
    stooges.emplace_back("Curly", 30);      // Use emplace_back!!!
    display(stooges);
}

/*  */
void test5() {
    std::cout << "\nTest5 =========================" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}
    };
    
    display(stooges);
    std::cout << "\nFront: " << stooges.front() << std::endl;
    std::cout << "Back: " << stooges.back() << std::endl;
    
    stooges.pop_back();
    display(stooges);
}

void test6() {
    std::cout << "\nTest6 =========================" << std::endl;
    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    
    vec.clear();    // 다 지우기
    display(vec);
    
    vec = {1,2,3,4,5,6,7,8,9,10};
    display(vec);
    vec.erase(vec.begin(), vec.begin() + 2); // 앞에 2개만 지우기 (없에버리는거임)
    display(vec);
    
    vec = {1,2,3,4,5,6,7,8,9,10};
    // erase all even numbers
    auto it = vec.begin();
    while (it != vec.end()) {
        if (*it %2 == 0)
            vec.erase(it);  
        else
            it++;   // only increment if not erased!
    }
    display(vec);
}

void test7() {
    std::cout << "\nTest7 =========================" << std::endl;
    
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20,30,40,50};
    
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    vec2.swap(vec1);
    display(vec1);
    display(vec2);
}

void test8() {
    std::cout << "\nTest8  =========================" << std::endl;

    std::vector<int> vec1 {1,21,3,40,12};    
    
    display(vec1);
    std::sort(vec1.begin(), vec1.end());
    display(vec1);
}

void test9() {
    // std::back_inserter contructs a back-insert iterator that inserts new elements 
    // at the end of the container it applied to. It's a special output iterator
    // It's awesome!!!!   and  very efficient
    // There is also a front_inserter we can use with deques and lists
    // Copy one list to another using an iterator and back_inserter
    
    std::cout << "\nTest9  =========================" << std::endl;
    
    std::vector<int> vec1 {1,2,3,4,5};   
    std::vector<int> vec2 {10,20};
    
    display(vec1); 
    display(vec2);
    std::cout << std::endl;

    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    
    // Copy_if the element is even
    
    vec1 = {1,2,3,4,5,6,7,8,9,10};
    vec2 = {10,20};
    
    display(vec1);
    display(vec2);
    std::cout << std::endl;
    
    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
            [](int x) { return x%2 == 0; });
    display(vec1);
    display(vec2);
    
    
}

void test10() {
    std::cout << "\nTest10  =========================" << std::endl;
    // transform over 2 ranges
    
    std::vector<int> vec1 {1,2,3,4,5};   
    std::vector<int> vec2 {10,20,30,40,50};
    std::vector<int> vec3;
    
    
    // 1*10, 2*20, 3*30, 4*40, 5*50 and store the results in vec3
    std::transform(vec1.begin(), vec1.end(), vec2.begin(),
        std::back_inserter(vec3),
        [](int x, int y) { return x * y;});
        
    display(vec3);
    
}



// Insertion from another vector
// Insert vec2 into vec1 before the 5
void test11() {
    std::cout << "\nTest11  =========================" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vec2 {100,200,300,400};
    
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    
    auto it = std::find(vec1.begin(), vec1.end(), 5);
    if (it != vec1.end()) {
        std::cout << "inserting..." << std::endl;
        vec1.insert(it, vec2.begin(), vec2.end());
    } else {
        std::cout << "Sorry, 5 not found" << std::endl;
    }
    display(vec1);
}