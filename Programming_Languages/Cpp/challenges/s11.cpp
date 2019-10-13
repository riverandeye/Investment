#include <iostream>
#include <vector>
using namespace std;

void check_empty(vector <int>);

int main()
{
    char c {};
    vector <int> ints;
    while(true)
    {
        cout << "P - Print numbers\nA - Add a number\nM - Display mean of the number\nS - Display the smallest number\nL - Display the largest number\nQ - Quit\n\nEnter your choice: ";
        cin >> c;

        if (c == 'P' || c == 'p'){
            check_empty(ints);
        }
        else if (c == 'A' || c == 'a')
        {
            int var {0};
            cout << "give me the integer to add : ";
            cin >> var;
            ints.push_back(var);
            cout << var <<" added" << endl;
        }
        else if (c == 'M' || c == 'm')
        {
            if (ints.size() == 0)
                cout << "Unable to calculate the mean"<<endl;
            else
            {   
                int rs {};
                double result;
                for (int i:ints)
                    rs += i;
                result = static_cast <double> (rs) / ints.size();
                cout << "average of ints is " << result << endl;
            }
        }
        else if (c == 'S' || c == 's')
        {
            if (ints.size() == 0)
                cout << "Unable to determine the smallest value."<<endl;
            else
            {
                int minval {2147483647};
                for (int i: ints)
                {
                    if (minval > i)
                        minval = i;
                }
                cout << "The smallest number is " << minval << endl;
            }
        }
        else if (c == 'L' || c == 'l')
        {
            if (ints.size() == 0)
                cout << "Unable to determine the largest value."<<endl;
            else
            {
                int maxval {-2147483648};
                for (int i: ints)
                {
                    if (maxval < i)
                        maxval = i;
                }
                cout << "The largest number is " << maxval << endl;
            }
        }
        else if (c == 'Q' || c == 'q')
        {
            cout << "Goodbye" << endl;
            break;
        }
        else
        {
            continue;
        }
        
    }
    return 0;
}

void check_empty(vector <int> ints)
{
    if (ints.size() == 0)
        cout << "[] - the list is empty"<<endl;
    else
    {   
        cout << "[ ";
        for (int i:ints)
            cout << i << " ";
        cout << "]";
    }
}