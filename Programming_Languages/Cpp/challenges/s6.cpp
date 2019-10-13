#include <iostream>

using namespace std;
int main()
{
    int sr, lr, pps {25}, ppl {35};
    cout << "Number of small room: ";
    cin >> sr;
    cout << "Number of large room: ";
    cin >> lr;
    cout << "Price per small room: $" << pps << endl;
    cout << "Price per large room: $" << ppl << endl;
    cout << "Cost : $" << sr * pps + lr * ppl << endl;
    cout << "Tax : $" << (sr * pps + lr * ppl) * 0.06 << endl;
    cout << "=====================================" << endl;
    cout << "Total estimate: $" << (sr * pps + lr * ppl) * 1.06 << endl;
    cout << "This estimate is valid for 30 days" << endl;
    return 0;
}