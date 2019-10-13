#include <iostream>

using namespace std;

double calculate_avg(int sum, int total){
    if (total == 0)
        throw 0; // exception handler
    return static_cast<double>(sum) / total;
}
    
int main(){

    double average {};
    try{
        average = calculate_avg(70 , 0);
        cout<<"the average is :" << average<<endl;
    }
    catch(int &ex)
    {
        cerr<<"You cannot divide by zero" << endl;
    }

    cout<<"Bye"<<endl;
}