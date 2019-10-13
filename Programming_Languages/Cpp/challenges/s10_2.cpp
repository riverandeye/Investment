#include <iostream>
#include <string>

using namespace std;
int main()
{
    string iw {};
    int i,j;

    getline(cin, iw);
    int len = iw.length();
    for (i = 0; i < len; i++)
    {
        for (j = len - 1 - i ; j > 0 ; j--)
            cout << ' ';
        string part = iw.substr(0,i);
        cout << part << iw[i];
        for (int k = part.length()-1; k >= 0 ; k--)
            cout << part[k];
        cout << endl;
    }
    return 0;
}