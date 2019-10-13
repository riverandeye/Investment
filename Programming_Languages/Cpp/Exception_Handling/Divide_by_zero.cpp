#include <iostream>

/* Exception Handling - dealing with exceptional situation */

int main()
{
    int sum{10}, total{0};
    double average{};
    try {
        if (total == 0) /* Unlike Python, we should predict the error situation and throw error in that case */
            throw 0; /* Below this point is not executed */
        average = sum/total;
    }
    catch(int &ex)
    {
        std::cout<<"Cannot divide to zero" << std::endl;
    }
    std::cout << "Program continues" << std::endl;

    return 0;
}