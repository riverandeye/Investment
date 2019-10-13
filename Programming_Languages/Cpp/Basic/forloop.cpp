#include <iostream>
#include <vector>

using namespace std;

int main()
{
    for (int i{1},j{5}; i<5 ; ++i, ++j)
        cout << "i : " << i << ". j is " << j << endl;

    for (int j{1}; j<101; ++j)
    {
        cout << j << " ";
        if (j % 10 == 0)
            cout << endl;
    }

    for (int j{1}; j<101; ++j)
    {
        cout << j;
        cout << ( (j % 10 == 0) ? "\n" : " ");
    } 

    vector <int> nums {100,101,102,103,104};
    for (int k{0};k<nums.size(); k++)
        cout << nums[k];

    vector<vector <int>> vec2d 
    {
        {1,2,3,4},
        {100,101,102},
        {2105,3103}
    };
    
    for (auto vec: vec2d)
    {
        for (auto item:vec)
        {
            cout << item << endl;
        }
    }
    return 0;
}
