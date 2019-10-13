#include <iostream>
#include <string>

using namespace std;

int main()
{
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {"XZNLW3BGJHQDYVTKFU0MPCIASRxznlwebgjhqdyvtkfuompc1asr"};
    string mess {};
    string cyphered {};
    cout << "Enter your secret message : " ;
    getline(cin, mess);

    cout << "Encrypting message...\n" << endl;

    for (int i{0}; i < mess.length(); i++)
    {
        if (alphabet.find(mess[i]) == 4294967295)
            cyphered.push_back(mess[i]);
        else 
            cyphered.push_back(key[alphabet.find(mess[i])]);
    }

    cout << "Encrypted message : " << cyphered << endl;
    return 0;
}