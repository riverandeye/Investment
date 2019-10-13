#include <iostream>
#include <vector>

using namespace std;

int* apply_all(int *a1, size_t a1size, int *a2, size_t a2size)
{
    int *intarray = new int[a1size * a2size];

    for (size_t i{0} ; i < a1size ; i++)
    {
        for (size_t j{0} ; j < a2size; j++)
        {
            intarray[i + j * a1size ] = a1[i] * a2[j];
        }
    }

    return intarray;
}

void print(int *ar, size_t arsize)
{   
    cout << "[ ";
    for (size_t a{0}; a < arsize ; a++)
        cout << ar[a] << " ";
    cout << "]" << endl;
}

int main()
{
    int *new_array;
    int array1[] {1,2,3,4,5}, array2[] {10, 20, 30};

    print(array1,5);
    print(array2,3);
    new_array = apply_all(array1, 5, array2, 3);

    print(new_array, 15);
    return 0;
}