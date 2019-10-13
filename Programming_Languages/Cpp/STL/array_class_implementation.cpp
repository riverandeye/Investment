#include <iostream>

using namespace std;

template <typename T, int N>
class Array{
private:
    int size{N}; // 이건 진짜 엄청난 기술이네
    T values[N];

    friend std::ostream &operator<<(std::ostream &os, const Array<T,N> &arr){
        os<<"[ ";
        for(const auto &val:arr.values)
            os << val << " ";
        os << "]" <<std::endl;
        return os;
    }
public:
    Array() = default;
    Array(T init_val){
        for(auto &item:values)
            item=init_val;
    }
    void fill(T val){
        for(auto &item: values)
            item = val;
    }
    int get_size() const {return size;}
    // subscript operator overloading
    T &operator[](int index){
        return values[index];
    }
};

int main(){
    Array<int, 5> nums{1};
    Array<char, 10> words{'f'};
    cout<<"The size of array is " << nums.get_size()<< endl;
    cout<<nums<<endl;
    cout<<"The size of array is " << words.get_size()<< endl;
    cout<<words<<endl;

    Array<std::string, 10> strings{"Hello"};
    
    cout<<"The size of array is " << strings.get_size()<< endl;
    cout<<strings<<endl;

    strings[0] = "WWWWWWWWWhat";
    cout << strings << endl;
    return 0;
}