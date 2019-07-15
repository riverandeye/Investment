#include<iostream>
#include <algorithm>

int DATA[1001];
int LIS[1001];

using namespace std;
int main()
{
    int A, ans;
    cin >> A;
    for(int i = 0 ; i < A ; i++)
        cin >> DATA[i];

    for(int i = 0 ; i < A ; i++) {
        LIS[i]=1;
        for(int j = 0 ; j < i ; j++)
        {
            if(DATA[i] > DATA[j])
                LIS[i] = max(LIS[i] , LIS[j] + 1);
        }
        ans = max(ans , LIS[i]);
    }
    cout << ans << endl;
    return 0;   
}
