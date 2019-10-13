#include <iostream>
#include <cstring>

#include "Mystring.h"

int main()
{
    Mystring empty;
    Mystring larry("Larry");
    Mystring stooge(larry);
    empty.display();
    larry.display();
    stooge.display();
    cout << "Larry and stoogre is" << (larry == stooge) << endl;

    return 0;
}