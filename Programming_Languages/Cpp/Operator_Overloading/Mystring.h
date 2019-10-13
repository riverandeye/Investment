#include <iostream>
#include <cstring>

using namespace std;

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::ostream &in, Mystring &rhs);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);
    private:
        char *str;

    public:
        Mystring();
        Mystring(const char *s);
        Mystring(const Mystring &source);
        ~Mystring();
        void display() const;
        int get_length() const;
        const char *get_str() const;
        Mystring &operator=(const Mystring &rhs);
        // bool operator==(const Mystring &rhs) const;
        Mystring operator-() const;
        Mystring operator+(const Mystring &rhs) const;
};
